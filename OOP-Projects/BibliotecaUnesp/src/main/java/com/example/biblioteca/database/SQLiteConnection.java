package com.example.biblioteca.database;

import java.sql.*;

/**
 * Classe para a integração do projeto com o banco de dados SQLite
 * @author Guilherme Romanholo
 */
public class SQLiteConnection {
    /**
     * Conexão com o banco de dados
     */
    private Connection conn;

    /**
     * Método construtor da classe de conexão
     */
    public SQLiteConnection() {
        this.conn = null;
    }

    /**
     * Método para realizar a conexão com o banco de dados
     * @param pathBancoDeDados Caminho do arquivo do banco de dados
     */
    public void conectar(String pathBancoDeDados) {
        try {
            conn = DriverManager.getConnection("jdbc:sqlite:" + pathBancoDeDados);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Método para encerrar a conexão com o banco de dados
     */
    public void desconectar() {
        try {
            if (conn != null)
                conn.close();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Getter para retornar a conexão estabelecida com o banco de dados
     * @return Conexão com o banco de dados
     */
    public Connection getConn() {
        return this.conn;
    }
}
