package com.example.biblioteca.item;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Classe referente ao item do tipo Livro.
 * Herda da classe pai Item.
 * @author Guilherme Romanholo
 */
public class Livro extends Item {
    /**
     * Editora do livro
     */
    private String editora;
    /**
     * ISBN do livro
     */
    private String isbn;

    /**
     * Método construtor da classe Livro
     * @param rs Result Set da consulta do banco de dados com as informações referentes ao Cd
     * @throws SQLException Caso não seja possível realizar a consulta para atribuir os valores
     */
    public Livro(ResultSet rs) throws SQLException {
        super(rs.getString("Titulo"),rs.getString("Autor"),rs.getInt("AnoPublicacao"),rs.getInt("QtdDisponivel"),rs.getInt("QtdEmprestada"));
        this.editora = rs.getString("Editora");
        this.isbn = rs.getString("Isbn");
    }

    /**
     * Método da classe pai sobreescrito.
     * Printa as informações extras referentes ao Livro.
     */
    @Override
    public void printInfo() {
        System.out.println("===== Livro =====");
        super.printInfo();
        System.out.printf("Editora: %s\n",editora);
        System.out.printf("ISBN: %s\n\n",isbn);
    }
}
