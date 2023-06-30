package com.example.biblioteca.item;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Classe referente ao item do tipo Cd.
 * Herda da classe pai Item.
 * @author Guilherme Romanholo
 */
public class Cd extends Item {
    /**
     * Volume do Cd
     */
    private int volume;
    /**
     * Gravadora do Cd
     */
    private String gravadora;

    /**
     * Método construtor da classe Cd
     * @param rs Result Set da consulta do banco de dados com as informações referentes ao Cd
     * @throws SQLException Caso não seja possível realizar a consulta para atribuir os valores
     */
    public Cd(ResultSet rs) throws SQLException {
        super(rs.getString("Titulo"),rs.getString("Autor"),rs.getInt("AnoPublicacao"),rs.getInt("QtdDisponivel"),rs.getInt("QtdEmprestada"));
        this.volume = rs.getInt("Volume");
        this.gravadora = rs.getString("Gravadora");
    }

    /**
     * Método da classe pai sobreescrito.
     * Printa as informações extras referentes ao Cd.
     */
    @Override
    public void printInfo() {
        System.out.println("===== Cd =====");
        super.printInfo();
        System.out.printf("Volume: %d\n",volume);
        System.out.printf("Gravadora: %s\n\n",gravadora);
    }
}
