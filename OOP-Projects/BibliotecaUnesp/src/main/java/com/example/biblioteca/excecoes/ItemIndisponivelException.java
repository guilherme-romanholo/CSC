package com.example.biblioteca.excecoes;

/**
 * Classe referente a execeção para quando um item não
 * está disponível para empréstimo
 * @author Guilherme Romanholo
 */
public class ItemIndisponivelException extends Exception{
    /**
     * Método construtor da execeção
     */
    public ItemIndisponivelException() {
        super("Item não está disponível!");
    }
}
