package com.example.biblioteca.usuario;

import java.sql.Date;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

/**
 * Classe abstrata que possui as informações compartilhadas por
 * todos os usuários.
 * @author Guilherme Romanholo
 */
public abstract class Usuario {
    /**
     * Nome real do usuário
     */
    private String nome;
    /**
     * Número de matrícula do usuário
     */
    private String matricula;
    /**
     * Username de login do usuário
     */
    private String username;
    /**
     * Senha para login do usuário
     */
    private String senha;
    /**
     * Tipo da conta
     * 1 - Aluno
     * 2 - Professor
     * 3 - Assessor Técnico
     */
    private int tipo;

    /**
     * Método construtor da classe Usuario,para suas classes filho
     * @param nome Nome real do usuário
     * @param matricula Número de matrícula
     * @param username Username para login
     * @param senha Senha para login
     * @param tipo Tipo da conta
     */
    public Usuario(String nome, String matricula, String username, String senha,int tipo) {
        this.nome = nome;
        this.matricula = matricula;
        this.username = username;
        this.senha = senha;
        this.tipo = tipo;
    }

    /**
     * Método para o calcúlo da multa na devolução dos itens
     * @param devReal Data de devolução real do item
     * @param devPrev Data de devolução prevista do item
     * @return Valor da multa
     */
    public abstract double calcularMulta(Date devReal, Date devPrev);

    /**
     * Getter para o nome real
     * @return nome
     */
    public String getNome() {
        return nome;
    }

    /**
     * Getter para o número de matrícula
     * @return matricula
     */
    public String getMatricula() {
        return matricula;
    }

    /**
     * Getter para o tipo da conta
     * @return 1 - Aluno, 2 - Professor, 3 - Assessor Técnico
     */
    public String getTipo() {
        if(tipo == 1)
            return "Aluno";
        else if (tipo == 2)
            return "Professor";
        else
            return "Assesor Técnico";
    }
}
