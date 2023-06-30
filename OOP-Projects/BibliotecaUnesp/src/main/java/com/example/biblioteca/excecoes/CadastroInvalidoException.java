package com.example.biblioteca.excecoes;

/**
 * Classe referente a execeção para quando o cadastro de um item
 * ou usuário for inválido
 * @author Guilherme Romanholo
 */
public class CadastroInvalidoException extends Exception {
    /**
     * Método construtor da execeção
     */
    public CadastroInvalidoException() {
        super("Informações inválidas para o cadastro!");
    }
}
