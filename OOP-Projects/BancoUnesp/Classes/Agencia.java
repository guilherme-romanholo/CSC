import java.util.ArrayList;

/**
 * <p>Classe utilizada para instânciar as agências do Banco</p>
 */
public class Agencia {
  private int codigo;
  private String nome;
  private String endereco;
  private ArrayList<Conta> contas;

  /**
   * <p>Método construtor da classe agência</p>
   * @param codigo Código da agência
   * @param nome Nome da agência
   * @param endereco Endereço da agência
   */
  public Agencia(int codigo, String nome, String endereco) {
    this.setNome(nome);
    this.setCodigo(codigo);
    this.setEndereco(endereco);
    this.contas = new ArrayList<Conta>();
  }

  /**
   * <p>Método para buscar uma conta da agência</p>
   * @param numConta Número da conta procurada
   * @return Conta procurada caso seja encontrada, ou null caso a conta não exista
   */
  public Conta buscarConta(int numConta) {
    for (Conta conta : this.contas) {
      if (conta.getNumeroConta() == numConta)
        return conta;
    }
    return null;
  }

  /**
   * <p>Sobrecarga do método buscarConta anterior, utilizado para buscar a conta durante o login do cliente</p>
   * @param numConta Número da conta procurada
   * @param senha Senha da conta
   * @return Conta procurada caso seja encontrada, ou null caso a conta não exista
   */
  public Conta buscarConta(int numConta, String senha) {
      for (Conta conta : this.contas) {
        if ((conta.getNumeroConta() == numConta) && (senha.equals(conta.getSenha()))) 
          return conta;
      }
    return null;
  }

  /**
   * <p>Sobrecarga do método buscarConta, utilizado para buscar a conta pelo Cpf</p>
   * @param Cpf Cpf da conta procurada
   * @return Conta procurada caso seja encontrada, ou null caso a conta não exista
   */
  public Conta buscarConta(String Cpf) {
    for (Conta conta : this.contas) {
      if (Cpf.equals(conta.getCpf())) 
        return conta;
    }
    return null;
  }

  /**
   * <p>Adiciona a conta a lista de contas da agência</p>
   * @param conta Conta para ser adicionada
   */
  public void cadastrarConta(Conta conta) {
    this.contas.add(conta);
  }

  /**
   * <p>Método setter para o código da agência</p>
   * @param codigo Código para ser settado
   */
  public void setCodigo(int codigo) {
    this.codigo = codigo;
  }

  /**
   * <p>Método setter para o nome da agência</p>
   * @param nome Nome para ser settado
   */
  public void setNome(String nome) {
    this.nome = nome;
  }

  /**
   * <p>Método setter para o endereço da agência</p>
   * @param endereco Endereço para ser settado
   */
  public void setEndereco(String endereco) {
    this.endereco = endereco;
  }

  /**
   * <p>Método getter para o nome da agência</p>
   * @return Nome da agência
   */
  public String getNome() {
    return nome;
  }
}
