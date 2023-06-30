package com.example.biblioteca.usuario;

import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

/**
 * Classe referente ao Usuario do tipo Professor.
 * Herda da classe pai Usuario.
 * @author Guilherme Romanholo
 */
public class Professor extends Usuario {
    /**
     * Departamento do professor
     */
    private String departamento;
    /**
     * Titulação do professor
     */
    private String titulacao;

    /**
     * Método construtor da classe Professor
     * @param rs Result Set da consulta do banco de dados com as informações referentes ao Cd
     * @throws SQLException Caso não seja possível realizar a consulta para atribuir os valores
     */
    public Professor(ResultSet rs) throws SQLException {
        super(rs.getString("Nome"),rs.getString("Matricula"),rs.getString("Username"),rs.getString("Senha"),rs.getInt("Tipo"));
        this.departamento = rs.getString("Departamento");
        this.titulacao = rs.getString("Titulacao");
    }

    /**
     * Método herdado da classe pai, calcula a multa com um
     * aumento de 25% em relação ao Aluno.
     * @param devReal Data de devolução real do item
     * @param devPrev Data prevista para devolução do item
     * @return Valor a ser pago
     */
    @Override
    public double calcularMulta(Date devReal, Date devPrev) {
        LocalDate ld1 = devReal.toLocalDate();
        LocalDate ld2 = devPrev.toLocalDate();
        long diff = ChronoUnit.DAYS.between(ld2, ld1);
        return (5 * diff) * (1.25) ;
    }
}
