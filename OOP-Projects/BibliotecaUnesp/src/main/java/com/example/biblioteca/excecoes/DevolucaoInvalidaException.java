package com.example.biblioteca.excecoes;

/**
 * Classe referente a execeção para quando não é possível
 * realizar a devolução de um item
 * @author Guilherme Romanholo
 */
public class DevolucaoInvalidaException extends Exception {
    /**
     * Método construtor da execeção
     */
    public DevolucaoInvalidaException() {
        super("Não é possível devolver um item não emprestado!");
    }
}
