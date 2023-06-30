import java.util.ArrayList;
import java.util.Scanner;

/**
 * <p>Classe utilizada para funcionar como o Backend do DisplayBanco</p>
 * @author Guilherme Romanholo Bofo
 */
public class Banco {
  private String name;
  private int numero;
  private String cnpj;
  private String endereco;
  private Conta contaLogada;
  private ArrayList<Agencia> agencias;

  /**
   * <p>Método construtor da classe banco</p>
   * @param bancoTxt Recebe a linha do arquivo com as informações do banco
   */
  public Banco(String bancoTxt) {
    String[] campos = bancoTxt.split("#");

    this.name = campos[0];
    this.numero = Integer.parseInt(campos[1]);
    this.cnpj = campos[2];
    this.endereco = campos[3];
    this.agencias = new ArrayList<Agencia>();
  }

  /**
   * <p>Método de backend para realizar o login do usuário</p>
   * @param numAgencia Número da agência da conta do usuário
   * @param numConta Número da conta do usuário
   * @param senha Senha da conta do usuário
   * @return True se conseguiu logar, False se as credenciais estão erradas
   */
  public boolean logarCliente(int numAgencia, int numConta, String senha) {
    Agencia agencia;

    // Busca a agência do usuário
    agencia = this.buscarAgencia(numAgencia);

    // Verificação se a agência digitada existe
    if (agencia == null)
      return false;

    // Busca a conta para atribuir ao campo contaLogada
    this.contaLogada = agencia.buscarConta(numConta, senha);

    // Verifica se a conta foi encontrada para efetuar o login
    if (this.contaLogada == null) {
      System.out.println("Conta/senha incorreto(s), tente novamente.");
      return false;
    } else {
      System.out.println("Logado com sucesso!");
      return true;
    }
  }

  /**
   * <p>Faz um append da agência na lista de agências do objeto do tipo Banco</p>
   * @param agencia Recebe a instância da agência
   */
  public void cadastrarAgencia(Agencia agencia) {
    this.agencias.add(agencia);
  }

  /**
   * <p>Método para instanciar um objeto do tipo agência e dar append na lista de agências</p>
   * @param nome Nome da agência
   * @param codigo Código da agência
   * @param endereco Endereço da agência
   */
  public void cadastrarAgencia(String nome, int codigo, String endereco) {
    Agencia agencia = new Agencia(codigo, nome, endereco);
    this.cadastrarAgencia(agencia);
  }

  /**
   * <p>Método para criar uma instância do tipo Conta e realizar sua inserção na lista de contas da agência</p>
   * @param nome Nome do dono da conta
   * @param dataNasc Data de nascimento do dono da conta
   * @param endereco Endereço do dono da conta
   * @param cpf Cpf do dono da conta
   * @param saldo Saldo do dono da conta
   * @param numAgencia Número da agência da conta
   * @param numConta Número da conta cadastrada
   * @param senha Senha da conta cadastrada
   */
  public void cadastrarConta(String nome, String dataNasc,  String endereco, String cpf,  double saldo, int numAgencia, int numConta, String senha) {
    Conta conta = new Conta(numAgencia, nome, endereco, cpf,saldo ,dataNasc, numConta, senha);
    this.setContaDaAgencia(conta, numAgencia);
  }

  /**
   * <p>Função para verificar se é o dono da conta realizando as operações solicitando sua senha</p>
   * @param sc Scanner para leitura de dados
   * @return True se a senha é correta, False se a senha é incorreta
   */
  public boolean verificacao(Scanner sc) {
    // Pede a senha do usuário
    System.out.print("\nDigite sua senha:\n\n>> ");
    sc.nextLine(); // limpa buffer

    // Chama um método para validar a senha digitada
    if (this.contaLogada.validarSenha(sc.nextLine())) {
      return true;
    } else {
      System.out.println("Senha incorreta, tente novamente!");
      return false;
    }
  }

  /**
   * <p>Recebe o código de uma agência e busca para ver se ela existe</p>
   * @param codigo Código da agência
   * @return Retorna a agência caso ela exista, ou null caso não exista
   */
  public Agencia buscarAgencia(int codigo) {
    Agencia agencia;
    // Try_catch para ver se existe uma agência no determinado índice da lista
    try {
      agencia = this.agencias.get(codigo);
    } catch (Exception e) {
      System.out.println("A agencia não existe, tente novamente!");
      agencia = null;
    }
    return agencia;
  }

  /**
   * <p>Método para buscar uma conta por meio do Cpf</p>
   * <p>Utilizado na operação do Pix</p>
   * @param chaveCpf Cpf da conta que será buscada
   * @return Retorna a conta caso seja encontrada, ou null caso não seja
   */
  public Conta buscarComCpf(String chaveCpf) {
    Conta conta;
    // for_each para buscar a conta
    for (Agencia agencia : this.agencias) {
      conta = agencia.buscarConta(chaveCpf);
      if (conta != null)
        return conta;
    }
    return null;
  }

  /**
   * <p>Função para receber o nome de uma pessoa com base no seu Cpf</p>
   * @param cpf Cpf da conta procurada
   * @return Retorna o nome da pessoa
   */
  public String nomeDoDestino(String cpf) {
    Conta conta = buscarComCpf(cpf);

    if (conta == null)
      return "";
    else
      return conta.getNome();
  }

  // Operações

  /**
   * <p>Backend da operacao de saque</p>
   * @param val Valor a ser sacado
   * @return Retorna um valor lógico se foi possível ou não efetuar o saque
   */
  public boolean realizarSaque(double val) {
    // Vê se é possivel sacar
    if (this.contaLogada.sacar(val))
    {
      // Adiciona a operação no extrato da conta
      this.contaLogada.addExtrato("Saque", val, contaLogada, this.contaLogada.getNome(), this.contaLogada.getSaldo());
      return true; 
    }
    return false;
  }

  /**
   * <p>Backend para a operação de depósito</p>
   * @param val Valor a ser depositado
   */
  public void realizarDeposito(double val) {
    // Deposita o valor
    this.contaLogada.depositar(val);
    // Adiciona a operação ao extrato
    this.contaLogada.addExtrato("Depósito", val, contaLogada, this.contaLogada.getNome(),this.contaLogada.getSaldo());
  }

  /**
   * <p>Backend para a operação de consulta do saldo</p>
   * @return Retorna o valor do saldo
   */
  public double saldo() {
    return this.contaLogada.getSaldo();
  }

  /**
   * <p>Backend para a operação de transferência</p>
   * @param numAgencia Número da agência de destino
   * @param numConta Número da conta de destino
   * @param val Valor a ser transferido
   * @return Retorna um valor lógico se foi possível ou não realizar a transferência
   */
  public boolean transferencia(int numAgencia, int numConta, double val) {
    Agencia agencia = this.buscarAgencia(numAgencia);
    Conta conta;

    // Verifica se a agência destino existe
    if (agencia == null)
      return false;

    // Busca a conta destino
    conta = agencia.buscarConta(numConta);

    // Verifica se conta destino existe
    if (conta == null) {
      System.out.println("Conta não encontrada!");
      return false;
    }

    // Retira o valor da contaLogada
    if (this.contaLogada.sacar(val)){
      // E deposita o valor na conta destino da transferência
      conta.depositar(val);
      // Adiciona o extrato tanto na contaLogada quanto na conta destino
      this.contaLogada.addExtrato("Transferência", val, conta, this.contaLogada.getNome(),this.contaLogada.getSaldo());
      conta.addExtrato("Transferência", val, conta, this.contaLogada.getNome(),conta.getSaldo());
    }

    return true;
  }

  /**
   * <p>Backend para a operação do Pix</p>
   * @param chaveCpf Cpf do destino do Pix
   * @param val Valor do pix
   * @return Retorna um valor lógico se foi possível ou não realizar o Pix
   */
  public boolean pix(String chaveCpf, double val) {
    // Busca a conta destino com o cpf
    Conta conta = buscarComCpf(chaveCpf);

    // Caso não encontre a conta destino
    if (conta == null) {
      System.out.println("Chave inválida!");
      return false;
    }

    // Retira o valor da contaLogada
    if (this.contaLogada.sacar(val)){
      // Deposita o valor na conta destino
      conta.depositar(val);
      // Adiciona o extrato na contaLogada e na conta destino
      this.contaLogada.addExtrato("Pix", val, conta, this.contaLogada.getNome(),this.contaLogada.getSaldo());
      conta.addExtrato("Pix", val, conta, this.contaLogada.getNome(),conta.getSaldo());
    }

    return true;
  }

  /**
   * <p>Método de backend para imprimir o extrato na tela pelo DisplayBanco</p>
   */
  public void extrato() {
    this.contaLogada.printExtrato();
  }

  /**
   * <p>Método de backend para a operação mudar senha</p>
   * @param senha Senha atual do usuário
   * @param novaSenha Nova senha
   * @return Valor lógico se foi possível ou não alterar a senha
   */
  public boolean mudarSenha(String senha, String novaSenha) {
    return this.contaLogada.setSenha(senha, novaSenha);
  }

  /**
   * <p>Backend para a operação deslogar, settando contaLogada para null</p>
   */
  public void deslogarConta() {
    this.contaLogada = null;
  }

  /**
   * <p>Método para adicionar uma conta a lista de contas de uma determinada agência</p>
   * @param conta Conta para ser adicionada
   * @param numAgencia Código da agência em que a conta será adicionada
   */
  public void setContaDaAgencia(Conta conta, int numAgencia) {
    Agencia agencia = this.buscarAgencia(numAgencia);
    agencia.cadastrarConta(conta);
  }

  /**
   * <p>Método get para o nome do usuário da conta logada</p>
   * @return Nome do usuário da conta logada
   */
  public String getNameContaLogada() {
    return this.contaLogada.getNome();
  }

  /**
   * <p>Método get para o número da conta logada</p>
   * @return Número da conta logada
   */
  public int getNumeroContaLogada() {
    return this.contaLogada.getNumeroConta();
  }

  /** 
   * <p>Método get para o cpf da conta logada</p>
   * @return Cpf da conta logada
   */
  public String getCpfContaLogada() {
    return this.contaLogada.getCpf();
  }

  /**
   * <p>Método get para o número da agência da conta logada</p>
   * @return Número da agêcia da conta logada
   */
  public int getAgenciaContaLogada() {
    return this.contaLogada.getNumeroAgencia();
  }

  /**
   * <p>Método get para o nome da agência da conta logada</p>
   * @return Nome da agência da conta logada
   */
  public String getNomeAgenciaContaLogada() {
    Agencia agencia = this.buscarAgencia(this.contaLogada.getNumeroAgencia());
    return agencia.getNome();
  }
}
