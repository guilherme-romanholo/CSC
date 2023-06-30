package com.example.biblioteca.item;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Classe referente ao item do tipo Revista.
 * Herda da classe pai Item.
 * @author Guilherme Romanholo
 */
public class Revista extends Item {
    /**
     * Volume da revista
     */
    private int volume;
    /**
     * Número da revista
     */
    private int numero;

    /**
     * Método construtor da classe Revista
     * @param rs Result Set da consulta do banco de dados com as informações referentes ao Cd
     * @throws SQLException Caso não seja possível realizar a consulta para atribuir os valores
     */
    public Revista (ResultSet rs) throws SQLException {
        super(rs.getString("Titulo"),rs.getString("Autor"),rs.getInt("AnoPublicacao"),rs.getInt("QtdDisponivel"),rs.getInt("QtdEmprestada"));
        this.volume = rs.getInt("Volume");
        this.numero = rs.getInt("Numero");
    }

    /**
     * Método da classe pai sobreescrito.
     * Printa as informações extras referentes à Revista.
     */
    @Override
    public void printInfo() {
        System.out.println("===== Revista =====");
        super.printInfo();
        System.out.printf("Volume: %d\n",volume);
        System.out.printf("Número: %d\n\n",numero);
    }
}
