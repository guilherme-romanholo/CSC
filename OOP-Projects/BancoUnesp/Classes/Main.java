/**
 * <p>Classe Main para rodar o programa principal</p>
 */
public class Main {

  /**
   *<p>Método por onde o programa deve começar</p>
   */
  public static void main(String[] args) {
    // Criação de uma instância da classe DisplayBanco, passando o caminho dos arquivos
    String banco = "../Arquivos/banco.txt";
    String agencias = "../Arquivos/agencias.txt";
    String contas = "../Arquivos/contas.txt";
    DisplayBanco disp = new DisplayBanco(agencias, contas, banco);

    // Chamada do método login para o usuário
    disp.login();
  }
}
