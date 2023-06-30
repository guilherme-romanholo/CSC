package com.example.biblioteca.display;


/**
 * Classe pricipal onde começa a execução do programa
 * @author Guilherme Romanholo
 */
public class Main {

    /**
     * Método para a criação de um display
     * @param args null
     */
    public static void main(String[] args) {
        Display disp = new Display("src/main/resources/biblioteca.db");

        disp.telaInicio();
    }
}
