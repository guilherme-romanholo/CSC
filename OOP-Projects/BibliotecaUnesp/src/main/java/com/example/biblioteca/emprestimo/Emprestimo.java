package com.example.biblioteca.emprestimo;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Date;

/**
 * Classe para o controle das informações referentes ao empréstimo
 * dos items
 * @author Guilherme Romanholo
 */
public class Emprestimo {
    /**
     * Título do item emprestado
     */
    private String itemEmprestado;
    /**
     * Data de empréstimo
     */
    private Date dataEmprestimo;
    /**
     * Data de devolução prevista para o item
     */
    private Date dataDevolucaoPrevista;
    /**
     * Data de devolução real para o item
     */
    private Date dataDevolucaoReal;

    /**
     * Método construtor para classe Emprestimo
     * @param rs Result Set da consulta do banco de dados com as informações referentes ao Emprestimo
     * @throws SQLException Caso não seja possível realizar a consulta para atribuir os valores
     */
    public Emprestimo(ResultSet rs) throws SQLException {
        this.dataEmprestimo = rs.getDate("DataEmprestimo");

        this.dataDevolucaoPrevista = rs.getDate("DataDevPrevista");

        if (rs.getDate("DataDevReal") == null){
            this.dataDevolucaoReal = null;
        } else {
            this.dataDevolucaoReal = rs.getDate("DataDevReal");
        }

        this.itemEmprestado = rs.getString("Item");
    }

    /**
     * Função para printar as informações referentes ao empréstimo
     */
    public void printEmprestimo() {
        System.out.printf("Item: %s\n", this.itemEmprestado);
        System.out.printf("Data de empréstimo: %td/%tm/%tY\n", this.dataEmprestimo, this.dataEmprestimo, this.dataEmprestimo);
        System.out.printf("Data de devolução prevista: %td/%tm/%tY\n", this.dataDevolucaoPrevista, this.dataDevolucaoPrevista, this.dataDevolucaoPrevista);

        if (this.dataDevolucaoReal == null) {
            System.out.println("Data de devolução real: Não devolvido");
        } else {
            System.out.printf("Data de devolução real: %td/%tm/%tY\n", this.dataDevolucaoReal, this.dataDevolucaoReal, this.dataDevolucaoReal);
        }

        System.out.println("=======================================");
    }

    /**
     * Getter para o título do item emprestado
     * @return Título do item
     */
    public String getItemEmprestado() {
        return this.itemEmprestado;
    }

    /**
     * Getter para a data de devolução prevista
     * @return Data de devolução prevista
     */
    public Date getDataDevolucaoPrevista() {
        return this.dataDevolucaoPrevista;
    }

    /**
     * Getter para data de devolução real
     * @return Data de devolução real
     */
    public Date getDataDevolucaoReal() {
        return this.dataDevolucaoReal;
    }
}
