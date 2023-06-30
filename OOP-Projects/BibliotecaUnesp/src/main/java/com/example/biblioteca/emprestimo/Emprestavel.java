package com.example.biblioteca.emprestimo;

/**
 * Interface para implementação dos métodos de empréstimo
 * @author Guilherme Romanholo
 */
public interface Emprestavel {
    /**
     * Método para o empréstimo de um item
     * @param matricula Número de matrícula do usuário
     * @param bancoDeDados Caminho do banco de dados
     * @param dias Quantidade de dias de duração do empréstimo
     */
    void emprestimo(String matricula, String bancoDeDados, int dias);

    /**
     * Método para a devolução de um item
     * @param matricula Número de matrícula do usuário
     * @param bancoDeDados Caminho do banco de dados
     * @param emprestimo Objeto referente ao empréstimo à ser devolvido
     */
    void devolucao(String matricula, String bancoDeDados, Emprestimo emprestimo);
}
