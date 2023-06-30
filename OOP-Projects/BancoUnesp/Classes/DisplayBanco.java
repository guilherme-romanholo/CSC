import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * <p>Classe utilizada para ser o display de acesso que o usuário tem controle (frontend do programa)</p>
 * @author Guilherme Romanholo Bofo
 */
public class DisplayBanco {
    private Banco meuBanco;
    private String contasTxt;
    private String agenciasTxt;
    private String bancoTxt;

    /**
     * <p>Método construtor para montar o banco com todas as agências e contas</p>
     * @param agenciasTxt arquivo txt contendo as agências
     * @param contasTxt   arquivo txt contendo as contas
     * @param bancoTxt    arquivo txt contento o banco
     */
    public DisplayBanco(String agenciasTxt, String contasTxt, String bancoTxt) {
        Scanner sc;

        // Atribuição dos atributos
        this.agenciasTxt = agenciasTxt;
        this.contasTxt = contasTxt;
        this.bancoTxt = bancoTxt;

        // Leitura do arquivo banco.txt
        sc = DisplayBanco.tryCatchArquivo(bancoTxt);
        String linha = sc.nextLine();

        // Crianção do objeto no campo meuBanco
        this.meuBanco = new Banco(linha);
        sc.close();

        // Leitura do arquivo agencias.txt
        sc = DisplayBanco.tryCatchArquivo(agenciasTxt);

        // Criação das agencias
        while (sc.hasNextLine()) {
            linha = sc.nextLine();
            String[] campos = linha.split("#");
            this.meuBanco.cadastrarAgencia(campos[0], Integer.parseInt(campos[1]), campos[2]);
        }
        sc.close();

        // Leitura do arquivo contas.txt
        sc = DisplayBanco.tryCatchArquivo(contasTxt);

        // Criação das contas
        while (sc.hasNextLine()) {
            linha = sc.nextLine();
            String[] campos = linha.split("#");
            this.meuBanco.cadastrarConta(campos[0], campos[1], campos[2], campos[3], Double.parseDouble(campos[4]),
                    Integer.parseInt(campos[5]), Integer.parseInt(campos[6]), campos[7]);
        }
        sc.close();
    }

    // MÉTODOS PARA LOGIN

    /**
     * Método para login do usuário
     */
    public void login() {
        Scanner sc = new Scanner(System.in);
        int numConta, numAgencia;
        String senha;

        while (true) {
            // Limpa tela
            DisplayBanco.clearScreen();
            // Print banner + opções
            System.out.println("=================================");
            System.out.println("╔╗ ┌─┐┌┐┌┌─┐┌─┐  ╦ ╦┌┐┌┌─┐┌─┐┌─┐");
            System.out.println("╠╩╗├─┤││││  │ │  ║ ║│││├┤ └─┐├─┘  ");
            System.out.println("╚═╝┴ ┴┘└┘└─┘└─┘  ╚═╝┘└┘└─┘└─┘┴    ");
            System.out.println("=================================");
            System.out.print("\nEscolha uma opção:\n(1) Login\n(2) Sair\n\n>> ");

            if (sc.nextInt() == 1) {
                // Enquanto o usuário não é validado, suas credenciais são soclicitadas
                do {
                    System.out.print("\nDigite o número da sua agencia:\n\n>> ");
                    numAgencia = sc.nextInt();
                    System.out.print("\nDigite o número da sua conta:\n\n>> ");
                    numConta = sc.nextInt();
                    System.out.print("\nDigite a sua senha:\n\n>> ");
                    sc.nextLine();// Limpa buffer
                    senha = sc.nextLine();
                } while (!this.meuBanco.logarCliente(numAgencia, numConta, senha));
                this.telaUsuario(sc);
            } else {
                // Quebra o laço e encerra o programa
                break;
            }
        }
        sc.close();
    }

    /**
     * <p>Método para mostrar as opções para o usuário logado</p>
     * @param sc Scanner para leitura das opções
     */
    private void telaUsuario(Scanner sc) {
        int opc;

        while (true) {
            // Limpa tela
            DisplayBanco.clearScreen();
            // Mostra informações do usuário logado
            System.out.printf("=============================\nLogado como: %s\nAgência: %d, %s\nConta: %d\nCPF: %s\n",
                    this.meuBanco.getNameContaLogada(), this.meuBanco.getAgenciaContaLogada(),
                    this.meuBanco.getNomeAgenciaContaLogada(),
                    this.meuBanco.getNumeroContaLogada(), this.meuBanco.getCpfContaLogada());
            System.out.println("=============================");
            // Opções de operações do banco
            System.out.print(
                    "\nEscolha uma opção:\n(1) Consultar saldo\n(2) Depósito\n(3) Saque\n(4) Transferência\n(5) Pix\n(6) Consultar extrato\n(7) Alterar senha\n(8) Deslogar\n\n>> ");
            opc = sc.nextInt();
            // Switch case com as opções
            switch (opc) {
                case 1:
                    if (this.meuBanco.verificacao(sc))
                        this.operacaoSaldo();
                    break;
                case 2:
                    this.operacaoDeposito(sc);
                    break;
                case 3:
                    this.operacaoSaque(sc);
                    break;
                case 4:
                    this.operacaoTransferencia(sc);
                    break;
                case 5:
                    this.operacaoPix(sc);
                    break;
                case 6:
                    this.operacaoExtrato(sc);
                    break;
                case 7:
                    this.operacaoMudarSenha(sc);
                    break;
                case 8:
                    this.operacaoSair();
                    return;
                default:
                    break;
            }
            System.out.println("\nDigite alguma coisa para continuar ...");
            sc.nextLine(); // Limpa buffer
        }
    }

    // OPERAÇÕES

    /**
     * <p>Método para consulta de saldo</p>
     */
    private void operacaoSaldo() {
        System.out.printf("\nO seu saldo atual é de R$%.2f.\n", this.meuBanco.saldo());
    }

    /**
     * <p>Método para o depósito na conta</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoDeposito(Scanner sc) {
        double val;

        // Lê o valor do depósito
        System.out.print("\nDigite o valor do depósito:\n\n>> ");
        val = sc.nextDouble();

        // Motra o saldo após o depósito
        System.out.printf("\nValor depositado: R$%.2f\nSaldo Atual: R$%.2f\nSaldo após o despósito: R$%.2f\n", val,
                this.meuBanco.saldo(), this.meuBanco.saldo() + val);

        // Realiza a confirmação do depósito
        System.out.print("\nConfirmar depósito?\n(1) Sim\n(2) Não\n\n>> ");
        if (sc.nextInt() == 1) {
            // Valida a senha para finalizar o depósito
            if (this.meuBanco.verificacao(sc))
                this.meuBanco.realizarDeposito(val);
        } else {
            sc.nextLine(); // Limpa buffer
            System.out.println("Depósito cancelado!");
            return;
        }
        System.out.println("Depósito realizado com sucesso!");
    }

    /**
     * <p>Método para realizar o saque</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoSaque(Scanner sc) {
        double val;

        // Lê o valor do saque
        System.out.print("\nDigite o valor que deseja sacar:\n\n>> ");
        val = sc.nextDouble();

        // Mostra o saldo após o saque
        System.out.printf("\nValor do saque: R$%.2f\nSaldo Atual: R$%.2f\nSaldo após o saque: R$%.2f\n", val,
                this.meuBanco.saldo(), this.meuBanco.saldo() - val);

        // Confirma o saque
        System.out.print("\nConfirmar saque?\n(1) Sim\n(2) Não\n\n>> ");
        if (sc.nextInt() == 1) {
            // Verifica a senha
            if (this.meuBanco.verificacao(sc)) {
                // Verifica se o saldo é suficiente para sacar
                if (this.meuBanco.realizarSaque(val))
                    System.out.println("Saque realizado com sucesso!");
                else
                    System.out.println("Saldo insuficiente, o saque NÃO foi realizado!");
            }
        } else {
            sc.nextLine();
            System.out.println("Saque cancelado!");
        }
    }

    /**
     * <p>Método que realiza transferência entre contas</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoTransferencia(Scanner sc) {
        int numAgencia, numConta;
        double val;

        while (true) {
            // Input das informações da conta destino e o valor
            System.out.print("\nDigite o número da agência do destinatário:\n\n>> ");
            numAgencia = sc.nextInt();
            System.out.print("\nDigite o número da conta do destinatário:\n\n>> ");
            numConta = sc.nextInt();
            if (numConta == this.meuBanco.getNumeroContaLogada()){
                System.out.println("\nNão é possível fazer uma transferência para si mesmo, tente novamente.");
                sc.nextLine();
                return;
            }
            System.out.print("\nDigite o valor da transferencia:\n\n>> ");
            val = sc.nextDouble();

            // Mostra as informações em relação a transferência
            System.out.printf(
                    "\nValor da transferencia: R$%.2f\nSaldo após a transferencia: R$%.2f\nAgência de destino: %d\nConta de destino: %d\n",
                    val, this.meuBanco.saldo() - val, numAgencia, numConta);

            // Confirma a transferência
            System.out.print("\nConfirmar transferência?\n(1) Sim\n(2) Não\n\n>> ");
            if (sc.nextInt() == 1) {
                // Verificação da senha
                if (this.meuBanco.verificacao(sc)) {
                    // Verifica se o saldo é suficiente
                    if (this.meuBanco.saldo() < val) {
                        System.out.println("Valor insuficiente.");
                        return;
                    } else {
                        // Se o saldo é suficiente realiza a transferência
                        if (this.meuBanco.transferencia(numAgencia, numConta, val)) {
                            System.out.println("Transferencia realizada com sucesso!");
                            return;
                        }
                        System.out.println("Transferencia não pode ser realizada, tente novamente.");
                    }
                }
            } else {
                sc.nextLine(); // Limpa buffer
                System.out.println("Transferência cancelada!");
                return;
            }
        }
    }

    /**
     * <p>Método para realizar o Pix entre contas</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoPix(Scanner sc) {
        String cpf;
        double val;

        while (true) {
            // Input do usuário para a conta destino (chave cpf) e valor
            sc.nextLine();
            System.out.print("\nDigite a chave Pix do usuario para a transferencia (CPF):\n\n>> ");
            cpf = sc.nextLine();
            if (cpf.equals(this.meuBanco.getCpfContaLogada())){
                System.out.println("\nNão é possível fazer um Pix para si mesmo, tente novamente.");
                return;
            }
            System.out.print("\nDigite o valor do Pix:\n\n>> ");
            val = sc.nextDouble();

            // Mostra as informações referentes ao Pix
            System.out.printf(
                    "\nValor do Pix: R$%.2f\nSaldo após o Pix: R$%.2f\nNome do destinatário: %s\n",
                    val, this.meuBanco.saldo() - val, this.meuBanco.nomeDoDestino(cpf));

            // Confirma o Pix
            System.out.print("\nConfirmar Pix?\n(1) Sim\n(2) Não\n\n>> ");
            if (sc.nextInt() == 1) {
                // Verifica a senha
                if (this.meuBanco.verificacao(sc)) {
                    // Verifica se o saldo é suficiente
                    if (this.meuBanco.saldo() < val) {
                        System.out.println("Valor insuficiente.");
                        return;
                    } else {
                        // Se o saldo for suficiente realiza o Pix
                        if(this.meuBanco.pix(cpf, val)){
                            System.out.println("Pix realizado com sucesso!");
                            return;
                        }
                        System.out.println("Pix não foi efetuado, tente novamente.");
                    }
                }
            } else {
                sc.nextLine(); // Limpa buffer
                System.out.println("Pix cancelado!");
                return;
            }
        }
    }

    /**
     * <p>Método para consultar o extrato da conta</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoExtrato(Scanner sc) {
        // Verifica a senha
        if (this.meuBanco.verificacao(sc))
            this.meuBanco.extrato(); // Mostra o extrato da conta
    }

    /**
     * <p>Operação para alterar a senha do usuário</p>
     * @param sc Scanner para leitura de input do usuário
     */
    private void operacaoMudarSenha(Scanner sc) {
        String senha, novaSenha;

        // Input da senha atual
        System.out.print("Digite sua senha atual:\n\n>> ");
        sc.nextLine(); // Limpa buffer
        senha = sc.nextLine();
        // Pede a nova senha enquanto ela não se enquadra nos padrões (6 dígitos numéricos)
        do {
            System.out.print("Digite sua nova senha:\n\n>> ");
            novaSenha = sc.nextLine();
        } while (novaSenha.length() != 6 || !novaSenha.matches("[+-]?\\d*(\\.\\d+)?"));

        // Verifica a senha atual para mudar a senha
        if (this.meuBanco.mudarSenha(senha, novaSenha))
            System.out.println("Senha alterada com sucesso!");
        else
            System.out.println("Senha incorreta, tente novamente.");
    }

    /**
     * <p>Método para deslogar da conta</p>
     */
    private void operacaoSair() {
        this.meuBanco.deslogarConta();
    }

    // UTILIDADES

    /**
     * <p>Método para facilitar a chamada do Try_Catch dos arquivos lidos no programa</p>
     * @param nomeArq Arquivo que está sendo lido
     * @return Scanner referente ao arquivo que está sendo lido
     */
    private static Scanner tryCatchArquivo(String nomeArq) {
        // Abre o arquivo
        File arq = new File(nomeArq);
        Scanner sc = null;

        // Verifica se é possível fazer a leitura dele
        try {
            sc = new Scanner(arq);
        } catch (FileNotFoundException ex) {
            System.out.println("Erro na leitura de arquivo.");
        }

        return sc;
    }

    /**
     * <p>Método para facilitar a operação de limpar a tela durante o programa</p>
     */
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
