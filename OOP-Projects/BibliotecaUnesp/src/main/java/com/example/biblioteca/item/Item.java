package com.example.biblioteca.item;

import com.example.biblioteca.database.SQLiteConnection;
import com.example.biblioteca.emprestimo.*;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Calendar;

/**
 * Classe abstrata que possui as informações compartilhadas por
 * todos os items.
 * Essa classe implementa a interface Emprestavel.
 * @author Guilherme Romanholo
 */
public abstract class Item implements Emprestavel {
    /**
     * Título do item
     */
    private String titulo;
    /**
     * Autor do item
     */
    private String autor;
    /**
     * Ano de publicação do item
     */
    private int anoPub;
    /**
     * Quandtidade disponível do item
     */
    private int qtdDisponivel;
    /**
     * Quantidade emprestada do item
     */
    private int qtdEmprestada;

    /**
     * Método construtor da classe Item, para suas classes filho
     * @param titulo Titulo do item
     * @param autor Autor do item
     * @param anoPub Ano de publicação do item
     * @param qtdDisponivel Quantidade disponível do item
     * @param qtdEmprestada Quandtidade emprestada do item
     */
    public Item(String titulo, String autor, int anoPub, int qtdDisponivel, int qtdEmprestada) {
        this.titulo = titulo;
        this.autor = autor;
        this.anoPub = anoPub;
        this.qtdDisponivel = qtdDisponivel;
        this.qtdEmprestada = qtdEmprestada;
    }

    /**
     * Método para imprimir na tela as informações do item.
     */
    public void printInfo() {
        System.out.printf("Quantidade disponível: %s\n",qtdDisponivel - qtdEmprestada);
        System.out.printf("Título: %s\n",titulo);
        System.out.printf("Autor: %s\n",autor);
        System.out.printf("Ano de publicação: %d\n",anoPub);
    }

    /**
     * Método da interface Emprestavel, realiza o empréstimo do item
     * @param matricula Número de matrícula do usuário
     * @param bancoDeDados Caminho do arquivo do banco de dados
     */
    @Override
    public void emprestimo(String matricula, String bancoDeDados, int dias) {
        // Usuário pode emprestar o mesmo item mais de uma vez?
        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(bancoDeDados);

        Calendar dataAtual  = Calendar.getInstance();

        Calendar dataDevolucao = Calendar.getInstance();
        dataDevolucao.add(Calendar.DAY_OF_YEAR, dias);

        try {
            String query = "INSERT INTO Emprestimos (DataEmprestimo, DataDevPrevista, Item, Usuario, MultaPaga, ItemDevolvido) VALUES (?,?,?,?,?,?)";
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setDate(1, new Date(dataAtual.getTime().getTime()));
            pstmt.setDate(2, new Date(dataDevolucao.getTime().getTime()));
            pstmt.setString(3, this.titulo);
            pstmt.setString(4, matricula);
            pstmt.setInt(5, 0);
            pstmt.setInt(6, 0);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        this.qtdEmprestada++;

        try {
            String query = "UPDATE Items SET QtdEmprestada = ? WHERE Titulo = ?";
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setInt(1 , this.qtdEmprestada);
            pstmt.setString(2, this.titulo);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();
    }

    /**
     * Método da interface emprestável, realiza a devolução de um item.
     * @param matricula Número de matrícula do usuário
     * @param bancoDeDados Caminho para o arquivo do banco de dados
     * @param emprestimo Objeto referente ao empréstimo que será devolvido.
     */
    @Override
    public void devolucao(String matricula, String bancoDeDados, Emprestimo emprestimo) {
        // update no emprestimos(data de entrega) e no items(voltar a quantidade), além de aplicar a multa
        String query;
        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(bancoDeDados);

        this.qtdEmprestada--;

        try {
            String query1 = "UPDATE Items SET QtdEmprestada = ? WHERE Titulo = ?";
            PreparedStatement pstmt = connection.getConn().prepareStatement(query1);
            pstmt.setInt(1 , this.qtdEmprestada);
            pstmt.setString(2, this.titulo);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        Date hoje = new Date(Calendar.getInstance().getTime().getTime());

        int compara = hoje.compareTo(emprestimo.getDataDevolucaoPrevista());

        if (compara > 0) {
            LocalDate ld1 = hoje.toLocalDate();
            LocalDate ld2 = emprestimo.getDataDevolucaoPrevista().toLocalDate();
            long diff = ChronoUnit.DAYS.between(ld2, ld1);

            System.out.printf("A devolução está atrasada em %d dias. Para verificar as multas pendentes acesse a área de multas!\n", diff);

            query = "UPDATE Emprestimos SET DataDevReal = ?, MultaPaga = 0, ItemDevolvido = 1 WHERE Usuario = ? AND Item = ?";
        } else {
            System.out.println("Livro devolvido dentro do prazo!");

            query = "UPDATE Emprestimos SET DataDevReal = ?, MultaPaga = 1, ItemDevolvido = 1 WHERE Usuario = ? AND Item = ?";
        }

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setDate(1, hoje);
            pstmt.setString(2, matricula);
            pstmt.setString(3, this.titulo);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Getter para o título do item.
     * @return Título do item
     */
    public String getTitulo() {
        return titulo;
    }
}
