package com.example.biblioteca.display;

import com.example.biblioteca.database.SQLiteConnection;
import com.example.biblioteca.emprestimo.Emprestimo;
import com.example.biblioteca.excecoes.ItemIndisponivelException;
import com.example.biblioteca.usuario.*;
import com.example.biblioteca.item.*;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Classe que possui os métodos de backend para o Display do programa.
 * @author Guilherme Romanholo
 */
public class DisplayBackend {
    /**
     * Caminho do arquivo do banco de dados
     */
    private final String databaseLink;

    /**
     * Conta do usuário logado
     */
    protected Usuario contaLogada;

    /**
     * Método construtor para classe DisplayBackend
     * @param databaseLink Caminho do banco de dados
     */
    public DisplayBackend(String databaseLink) {
        this.databaseLink = databaseLink;
        this.contaLogada = null;
    }

    /**
     * Método de backend para verificação se o login é válido
     * @param username Username da pessoas que está logando
     * @param senha Senha da conta que será logada
     * @return Valor booleano se foi possível logar na conta
     */
    public boolean loginBackend(String username, String senha) {
        String query = "SELECT * FROM Usuarios WHERE Username = ? AND Senha = ?";

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        PreparedStatement pstmt;
        ResultSet rs;
        boolean login = false;

        try {
            pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, username);
            pstmt.setString(2, senha);
            rs = pstmt.executeQuery();
            if (rs.next()){
                login = true;
                this.inicializaContaLogada(rs);
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();

        return login;
    }

    /**
     * Método de backend para realizar o cadastro de novo usuário no banco de dados
     * @param nome Nome do usuário
     * @param matricula Matrícula do usuário
     * @param tipo Tipo da conta (Aluno, Professor. Assessor)
     * @param curso Curso caso seja Aluno (pode ser null caso não seja)
     * @param periodo Período caso seja Aluno (pode ser null caso não seja)
     * @param departamento Departamento caso seja Professor (pode ser null caso não seja)
     * @param titulacao Titulação caso seja Professor (pode ser null caso não seja)
     * @param secao Seção caso seja Assessor Técnico (pode ser null caso não seja)
     * @param username Nome de usuário para login no sistema
     * @param senha Senha do usuário para login no sistema
     * @return Valor booleano se foi possível cadastrar o novo usuário
     */
    public boolean cadastrarUsuarioBackend(String nome, String matricula, int tipo, String curso, int periodo, String departamento, String titulacao, String secao, String username, String senha) {
        boolean cadastro = false;
        String query = "INSERT INTO Usuarios (Nome, Matricula, Tipo, Curso, Periodo, Departamento, Titulacao, Secao, Username, Senha) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, nome);
            pstmt.setString(2, matricula);
            pstmt.setInt(3, tipo);
            pstmt.setString(4, curso);
            pstmt.setInt(5, periodo);
            pstmt.setString(6, departamento);
            pstmt.setString(7, titulacao);
            pstmt.setString(8, secao);
            pstmt.setString(9, username);
            pstmt.setString(10, senha);
            pstmt.executeUpdate();
            cadastro = true;
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();

        return cadastro;
    }

    /**
     * Método de backend para o cadastro de um novo item no banco de dados
     * @param tipo Tipo do item (1 - Cd,2 - Livro,3 - Revista)
     * @param titulo Título do item
     * @param autor Autor do item
     * @param anoPub Ano de publicação do item
     * @param qtdDisp Quantidade de item disponível no estoque
     * @param editora Editora (caso seja um Livro)
     * @param isbn ISBN (caso seja um livro)
     * @param numero Número (caso seja revista)
     * @param volume Volume (caso seja cd ou revista)
     * @param gravadora Gravadora (caso seja cd)
     * @return Valor booleano se foi possível realizar o cadastro
     */
    public boolean cadastrarItemBackend(int tipo, String titulo, String autor, int anoPub, int qtdDisp, String editora, String isbn, int numero, int volume, String gravadora) {
        boolean cadastro = false;
        String query = "INSERT INTO Items (Tipo, Titulo, Autor, AnoPublicacao, QtdDisponivel, Editora, Isbn, Numero, Volume, Gravadora, QtdEmprestada) VALUES (?,?,?,?,?,?,?,?,?,?,?)";

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setInt(1, tipo);
            pstmt.setString(2, titulo);
            pstmt.setString(3, autor);
            pstmt.setInt(4, anoPub);
            pstmt.setInt(5, qtdDisp);
            pstmt.setString(6, editora);
            pstmt.setString(7, isbn);
            pstmt.setInt(8, numero);
            pstmt.setInt(9, volume);
            pstmt.setString(10, gravadora);
            pstmt.setInt(11, 0);
            pstmt.executeUpdate();
            cadastro = true;
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();

        return cadastro;
    }

    /**
     * Método para buscar um item no banco de dados com base no seu título
     * @param titulo Título do item que vai ser buscado
     * @return Array com os items com nome similar
     * @throws ItemIndisponivelException Caso o item não esteja disponível no banco de dados
     */
    public ArrayList<Item> buscarItemBackend(String titulo) throws ItemIndisponivelException {
        ArrayList<Item> items = new ArrayList<>();
        String query = "SELECT * FROM Items WHERE Titulo LIKE ?";

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, "%" + titulo + "%");
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                do {
                    if (rs.getInt("Tipo") == 1) {
                        Cd item = new Cd(rs);
                        items.add(item);
                    } else if (rs.getInt("Tipo") == 2) {
                        Livro item = new Livro(rs);
                        items.add(item);
                    } else {
                        Revista item = new Revista(rs);
                        items.add(item);
                    }
                } while (rs.next());
            } else {
                connection.desconectar();
                throw new ItemIndisponivelException();
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();

        return items;
    }

    /**
     * Método para buscar os empréstimos no banco de dados
     * @param flag 1 - Buscar com base no nome de usuário
     *             2 - Buscar vendo se o item ainda não foi devolvido
     *             3 - Buscar vendo se o item tem multa pendente
     * @return Array com os empréstimo encontrados
     */
    public ArrayList<Emprestimo> listarEmprestimosBackend(int flag) {
        ArrayList<Emprestimo> emprestimos = null;
        String query = null;

        if (flag == 1)
            query = "SELECT * FROM Emprestimos WHERE Usuario = ?";
        else if (flag == 2)
            query = "SELECT * FROM Emprestimos WHERE Usuario = ? AND ItemDevolvido = 0";
        else if (flag == 3)
            query = "SELECT * FROM Emprestimos WHERE Usuario = ? AND ItemDevolvido = 1 AND MultaPaga = 0";


        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, this.contaLogada.getMatricula());
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                emprestimos = new ArrayList<>();
                do {
                    emprestimos.add(new Emprestimo(rs));
                } while (rs.next());
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return emprestimos;
    }

    /**
     * Método de backend para realizar o pagamento da multa/ quitação da dívida
     * @param item Nome do item que vai ter a multa paga
     */
    public void pagarMultaBackend(String item) {
        String query = "UPDATE Emprestimos SET MultaPaga = 1 WHERE Usuario = ? AND Item = ?" ;

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, this.contaLogada.getMatricula());
            pstmt.setString(2, item);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Método para verificar se já existe um usuário no banco de dados
     * com o username especificado
     * @param username Nome de usuário para ser verificado
     * @return Valor booleano se foi encontrado ou não
     */
    public boolean verificaUsuarioExiste(String username) {
        boolean existe = false;
        String query = "SELECT * FROM Usuarios WHERE Username = ?";

        SQLiteConnection connection = new SQLiteConnection();
        connection.conectar(this.databaseLink);

        try {
            PreparedStatement pstmt = connection.getConn().prepareStatement(query);
            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();
            if (rs.next()){
                existe = true;
                System.out.println("Username já existe, tente novamente.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        connection.desconectar();

        return existe;
    }

    /**
     * Método para inicializar a conta logada do atributo da classe
     * @param rs Result Set com os valores da conta encontrados no banco de dados
     * @throws SQLException Caso exista algum problema na consulta do banco de dados
     */
    public void inicializaContaLogada(ResultSet rs) throws SQLException {
        switch (rs.getInt("Tipo")) {
            case 1 -> this.contaLogada = new Aluno(rs);
            case 2 -> this.contaLogada = new Professor(rs);
            case 3 -> this.contaLogada = new AssessorTecnico(rs);
        }
    }
}
