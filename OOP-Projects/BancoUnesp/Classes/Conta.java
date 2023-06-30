import java.util.ArrayList;
import java.util.Stack;

/**
 * <p>Classe utilizada para guardar as informações referentes a conta do usuário</p>
 * @author Guilherme Romanholo Bofo
 */
public class Conta {
  private int numeroAgencia;
  private double saldo;
  private String nome;
  private String endereco;
  private String cpf;
  private String dataNasc;
  private int numeroConta;
  private String senha;
  private ArrayList<Extrato> extratos;

  /**
   * <p>Método construtor da classe Conta</p>
   * @param numAgencia Número da agência da conta
   * @param nome Nome do dono da conta
   * @param endereco Endereço do dono da conta
   * @param cpf Cpf do dono da conta
   * @param saldo Saldo da conta
   * @param dataNasc Data de nascimento do dono da conta
   * @param numConta Número da conta
   * @param senha Senha da conta
   */
  public Conta(int numAgencia, String nome, String endereco, String cpf, double saldo, String dataNasc, int numConta, String senha) {
    this.nome = nome;
    this.dataNasc = dataNasc;
    this.endereco = endereco;
    this.cpf = cpf;
    this.saldo = saldo;
    this.numeroAgencia = numAgencia;
    this.numeroConta = numConta;
    this.senha = senha;
    this.extratos = new ArrayList<Extrato>();
  }


  /**
   * <p>Método para depósito, incrementando o saldo da conta</p>
   * @param val Valor depositado
   */
  public void depositar(double val) {
    this.saldo += val;
  }

  /**
   * <p>Método para saque, decrementando o saldo da conta</p>
   * @param val Valor sacado
   * @return Valor lógico se é possível sacar um determinado valor ou não
   */
  public boolean sacar(double val) {
    if (val > this.saldo) {
      return false;
    }
    this.saldo -= val;
    return true;
  }

  /**
   * <p>Método que compara uma senha digitada com a senha da conta</p>
   * @param senhaComparar Senha digitada pelo usuário
   * @return Valor lógico se as duas senhas são iguais ou não
   */
  public boolean validarSenha(String senhaComparar) {
    return senhaComparar.equals(this.senha);
  }

  /**
   * <p>Método para alterar a senha da conta</p>
   * @param senhaAtual Senha atual da conta
   * @param senhaNova Senha nova para a conta
   * @return Valor lógico se foi possível ou não alterar a senha da conta
   */
  public boolean setSenha(String senhaAtual, String senhaNova) {
    if (senhaAtual.equals(this.senha)) {
      this.senha = senhaNova;
      return true;
    }
    return false;
  }

  /**
   * <p>Método para printar o extrado da conta</p>
   */
  public void printExtrato() {
    // Verifica se conta possui operações já realizadas
    if (this.extratos.isEmpty()){
      System.out.println("Conta sem extrato, realize alguma operação!");
      return;
    }

    // Printa o extrato
    for (Extrato extrato : extratos) {
      extrato.printExtrato();
    }
  }

  /**
   * <p>Adiciona o extrato para lista de extratos da conta</p>
   * @param tipo Tipo da operação
   * @param val Valor da movimentação
   * @param destino Conta de destino
   * @param operador Nome do operador
   * @param saldoMomento Saldo da conta após a operação
   */
  public void addExtrato(String tipo, double val, Conta destino, String operador, double saldoMomento) {
    this.extratos.add(new Extrato(tipo,val,destino,operador,saldoMomento));
  }

  /**
   * <p>Getter do número da agência da conta</p>
   * @return Número da agência
   */
  public int getNumeroAgencia() {
    return numeroAgencia;
  }

  /**
   * <p>Getter do saldo da conta</p>
   * @return Valor do saldo
   */
  public double getSaldo() {
    return saldo;
  }

  /**
   * <p>Getter do nome do proprietário da conta</p>
   * @return Nome do proprietário da conta
   */
  public String getNome() {
    return nome;
  }

  /**
   * <p>Getter do Cpf da conta</p>
   * @return Número do Cpf
   */
  public String getCpf() {
    return cpf;
  }

  /**
   * <p>Getter do número da conta</p>
   * @return Número da conta
   */
  public int getNumeroConta() {
    return numeroConta;
  }

  /**
   * <p>Getter da senha da conta</p>
   * @return Valor da senha
   */
  public String getSenha() {
    return senha;
  }
}
