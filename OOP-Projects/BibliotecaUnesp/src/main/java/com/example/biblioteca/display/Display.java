package com.example.biblioteca.display;

import com.example.biblioteca.emprestimo.Emprestimo;
import com.example.biblioteca.excecoes.CadastroInvalidoException;
import com.example.biblioteca.excecoes.ItemIndisponivelException;
import com.example.biblioteca.item.*;

import java.time.Year;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Classe que controla o Display referente ao usuário, onde
 * ele vai interagir com o programa.
 * @author Guilherme Romanholo
 */
public class Display {
    /**
     * Caminho do banco de dados
     */
    String databaseLink;
    /**
     * Backend do display
     */
    DisplayBackend backend;

    /**
     * Método construtor da Classe Display
     * @param databaseLink Caminho do banco de dados
     */
    public Display(String databaseLink) {
        this.databaseLink = databaseLink;
        this.backend = new DisplayBackend(databaseLink);
    }

    /**
     * Mostra a tela inicial para o usuário efetuar o login, ou
     * realizar algum cadastro.
     */
    public void telaInicio() {
        int opc;
        Scanner sc = new Scanner(System.in);

        clearScreen();
        do {
            System.out.println("===== Bem vindo ao sistema da Biblioteca Unesp =====");
            System.out.print("(1) Fazer login\n(2) Cadastro de novo usuário\n(3) Cadastro de novo item\n(4) Sair\n> ");
            opc = sc.nextInt();

            switch (opc) {
                case 1:
                    login(sc);
                    break;
                case 2:
                    try {
                        cadastrarUsuario(sc);
                    } catch (CadastroInvalidoException e) {
                        System.out.println(e.getMessage());
                    }
                    break;
                case 3:
                    try {
                        cadastrarItem(sc);
                    } catch (CadastroInvalidoException e) {
                        System.out.println(e.getMessage());
                    }
                default:
                    break;
            }
        } while (opc != 4);
    }

    /**
     * Método para receber as informações do login de um determinado usuário
     * @param sc Scanner para a leitura das entradas
     */
    public void login(Scanner sc) {
        String username, senha;

        sc.nextLine();

        System.out.print("Digite o seu nome de usuário:\n> ");
        username = sc.nextLine();

        System.out.print("Digite o sua senha:\n> ");
        senha = sc.nextLine();

        if (this.backend.loginBackend(username, senha)) {
            System.out.println("Logado com sucesso!");
            this.telaUsuario(sc);
        } else {
            System.out.println("Credenciais incorretas, tente novamente.");
            System.out.println("Digite alguma coisa para continuar ...");
            sc.nextLine();
        }
    }

    /**
     * Método para receber as informações referentes ao
     * cadastro de um novo usuário
     * @param sc Scanner para a leitura das entradas
     * @throws CadastroInvalidoException Caso alguma informação for inválida, uma exceção é emitida
     */
    public void cadastrarUsuario(Scanner sc) throws CadastroInvalidoException{
        String curso, titulacao, departamento, secao;
        int periodo = -1;

        curso = titulacao = departamento = secao = null;

        sc.nextLine();

        System.out.print("Digite seu nome\n> ");
        String nome = sc.nextLine();

        System.out.print("Digite sua matrícula\n> ");
        String matricula = sc.nextLine();

        System.out.print("Escolha a opção:\n(1)Aluno\n(2)Professor\n(3)Assessor\n> ");
        int tipo = sc.nextInt();

        if (tipo < 1 || tipo > 3)
            throw new CadastroInvalidoException();

        sc.nextLine();

        if (tipo == 1) {
            System.out.print("Digite seu curso\n> ");
            curso = sc.nextLine();

            System.out.print("Digite seu período do curso (semestre)\n> ");
            periodo = sc.nextInt();

            sc.nextLine();

            if (periodo <= 0)
                throw new CadastroInvalidoException();
        } else if (tipo == 2) {
            System.out.print("Digite seu departamento\n> ");
            departamento = sc.nextLine();

            System.out.print("Digite sua titulação\n> ");
            titulacao = sc.nextLine();
        } else {
            System.out.print("Digite sua seção\n> ");
            secao = sc.nextLine();
        }

        System.out.println("====== Escolha seu usuário e senha =====");

        String username;
        do {
            System.out.print("Digite seu nome de usuário\n> ");
            username = sc.nextLine();
        } while (this.backend.verificaUsuarioExiste(username));

        System.out.print("Digite sua senha\n> ");
        String senha = sc.nextLine();

        if (this.backend.cadastrarUsuarioBackend(nome, matricula, tipo, curso, periodo, departamento, titulacao, secao, username, senha))
            System.out.println("Usuário cadastrado com sucesso!");
        else
            System.out.println("Não foi possível cadastrar o usuário.");

        System.out.println("Digite alguma coisa para continuar ...");
        sc.nextLine();
    }

    /**
     * Método que recebe as informações referentes ao cadastro de um novo item
     * @param sc Scanner para a leitura das entradas
     * @throws CadastroInvalidoException Caso alguma informação do cadastro esteja errada, emite uma execeção
     */
    public void cadastrarItem(Scanner sc) throws CadastroInvalidoException {
        String gravadora, editora, isbn;
        int volume, numero;

        gravadora = editora = isbn = null;
        volume = numero = -1;

        System.out.println("===== Sistema de cadastro de novo item =====");
        System.out.print("(1) CD\n(2) Livro\n(3) Revista\n> ");
        int tipo = sc.nextInt();

        if (tipo < 1 || tipo > 3)
            throw new CadastroInvalidoException();

        sc.nextLine();

        System.out.print("Digite o título\n> ");
        String titulo = sc.nextLine();

        System.out.print("Digite o autor\n> ");
        String autor = sc.nextLine();

        System.out.print("Digite o ano de publicação\n> ");
        int anoPub = sc.nextInt();

        int anoAtual = Year.now().getValue();

        if (anoPub > anoAtual)
            throw new CadastroInvalidoException();

        System.out.print("Digite a quantidade disponível\n> ");
        int qtdDisp = sc.nextInt();

        if (qtdDisp == 0)
            throw new CadastroInvalidoException();

        if (tipo == 1) {
            sc.nextLine();

            System.out.print("Digite o nome da gravadora\n> ");
            gravadora = sc.nextLine();

            System.out.print("Digite o volume\n> ");
            volume = sc.nextInt();

            if (volume < 0)
                throw new CadastroInvalidoException();

        } else if (tipo == 2) {
            sc.nextLine();

            System.out.print("Digite o nome da editora\n> ");
            editora = sc.nextLine();

            System.out.print("Digite o ISBN\n> ");
            isbn = sc.nextLine();
        } else {
            System.out.print("Digite o volume\n> ");
            volume = sc.nextInt();

            if (volume < 0)
                throw new CadastroInvalidoException();

            System.out.print("Digite o número\n> ");
            numero = sc.nextInt();

            if (numero < 0)
                throw new CadastroInvalidoException();
        }

        if (this.backend.cadastrarItemBackend(tipo, titulo, autor, anoPub, qtdDisp, editora, isbn, numero, volume, gravadora))
            System.out.println("Item cadastrado com sucesso!");
        else
            System.out.println("Não foi possível cadastrar o item!");

        System.out.println("Digite alguma coisa para continuar ...");
        sc.nextLine();
    }

    /**
     * Método que mostra a tela para o usuário após o login
     * @param sc Scanner para selecionar as opções
     */
    public void telaUsuario(Scanner sc) {
        int opc;
        do {
            clearScreen();
            System.out.println("===== Bem vindo ao sistema da biblioteca =====");
            System.out.printf("Nome : %s\n", this.backend.contaLogada.getNome());
            System.out.printf("Matricula : %s\n", this.backend.contaLogada.getMatricula());
            System.out.printf("Conta : %s\n", this.backend.contaLogada.getTipo());
            System.out.print("(1) Buscar Item\n(2) Realizar Empréstimo\n(3) Devolver Item\n(4) Listar Empréstimos\n(5) Verificar multas\n(0) Voltar\n> ");

            opc = sc.nextInt();

            switch (opc) {
                case 1 -> consultaItem(sc);
                case 2 -> realizarEmprestimo(sc);
                case 3 -> realizarDevolucao(sc);
                case 4 -> {
                    listarEmprestimos();
                    sc.nextLine();
                }
                case 5 -> pagarMulta(sc);
                default -> System.out.println("Operação inválida!");
            }

            System.out.println("Digite algo para continuar ...");
            sc.nextLine();

        } while (opc != 0);
    }

    /**
     * Método que recebe o título de um item para realizar uma consulta
     * @param sc Scanner para a entrada do título
     */
    public void consultaItem(Scanner sc) {
        String titulo = null;
        ArrayList<Item> items;

        sc.nextLine();

        System.out.print("Digite o título do item que está procurando\n> ");

        for(int i = 0; i<3;i++){
            try{
                titulo = sc.nextLine();
                break;
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
        }

        items = buscarItem(titulo);

        if (items == null)
            return;


        for (int i = 0; i < items.size(); i++) {
            System.out.printf("(%d) %s\n", i + 1, items.get(i).getTitulo());
        }
        System.out.println("(0) Voltar");
        System.out.print("Escolha o item para listar as informaçoes:\n> ");
        int op = sc.nextInt();

        if (op == 0) {
            return;
        }

        Item escolhido;

        try {
            escolhido = items.get(op - 1);
        } catch (Exception e) {
            ItemIndisponivelException ex = new ItemIndisponivelException();
            System.out.println(ex.getMessage());
            sc.nextLine();
            return;
        }

        if (escolhido instanceof Cd cd) {
            cd.printInfo();
        } else if (escolhido instanceof Revista revista) {
            revista.printInfo();
        } else if (escolhido instanceof Livro livro) {
            livro.printInfo();
        }

        sc.nextLine();
    }

    /**
     * Método para tratar a busca de um item realizada no backend
     * @param titulo Título do item buscado
     * @return Lista de items com os nomes parecidos com o escolhido pelo usuário
     */
    public ArrayList<Item> buscarItem(String titulo) {
        ArrayList<Item> items;

        try {
            items = this.backend.buscarItemBackend(titulo);
        } catch (ItemIndisponivelException e) {
            items = null;
            System.out.println(e.getMessage());
        }

        return items;
    }

    /**
     * Método para escolha de um item que será emprestado
     * @param sc Scanner para a entrada
     */
    public void realizarEmprestimo(Scanner sc) {
        sc.nextLine();

        System.out.print("Digite o nome do item que deseja realizar o empréstimo\n> ");
        String titulo = sc.nextLine();

        ArrayList<Item> items = buscarItem(titulo);

        if (items == null)
            return;

        for (int i = 0; i < items.size(); i++) {
            System.out.printf("(%d) %s\n", i + 1, items.get(i).getTitulo());
        }
        System.out.println("(0) Cancelar empréstimo");
        System.out.print("Escolha o item para realizar o empréstimo:\n> ");
        int op = sc.nextInt();

        if (op == 0) {
            System.out.println("Empréstimo cancelado com sucesso!");
            sc.nextLine();
            return;
        }

        Item escolhido;
        try {
            escolhido = items.get(op - 1);
        } catch (Exception e) {
            ItemIndisponivelException ex = new ItemIndisponivelException();
            System.out.println(ex.getMessage());
            return;
        }

        int dias;
        do {
            System.out.print("Digite a quantidade de dias do empréstimo:\n> ");
            dias = sc.nextInt();
            if (dias <= 0)
                System.out.println("Digite um valor correto para os dias;");
        } while (dias <= 0);

        if (escolhido instanceof Cd cd) {
            cd.printInfo();
        } else if (escolhido instanceof Revista revista) {
            revista.printInfo();
        } else if (escolhido instanceof Livro livro) {
            livro.printInfo();
        }

        sc.nextLine();

        System.out.print("Deseja realizar o empréstimo desse item?\n(1) Sim\n(2) Não\n> ");

        if (sc.nextInt() == 1) {
            items.get(op - 1).emprestimo(this.backend.contaLogada.getMatricula(), this.databaseLink, dias);
            System.out.println("Empréstimo realizado com sucesso!");
        } else {
            System.out.println("Empréstimo cancelado!");
        }
        sc.nextLine();
    }

    /**
     * Método para escolha de um item que será devolvido
     * @param sc Scanner para as entradas
     */
    public void realizarDevolucao(Scanner sc) {
        sc.nextLine();

        ArrayList<Emprestimo> emprestimos = this.backend.listarEmprestimosBackend(2);

        if (emprestimos == null) {
            System.out.println("Não há empréstimos para serem devolvidos!");
            return;
        }

        System.out.println("===== Escolha qual item deseja devolver =====");

        for (int i = 0; i < emprestimos.size(); i++) {
            System.out.printf("(%d) %s\n", i + 1, emprestimos.get(i).getItemEmprestado());
        }
        System.out.println("(0) Cancelar devolução");
        System.out.print("Escolha o item para realizar a devolução:\n> ");
        int op = sc.nextInt();

        if (op == 0) {
            System.out.println("Devolução cancelada com sucesso!");
            return;
        }

        try {
            emprestimos.get(op - 1).printEmprestimo();
        } catch (Exception e) {
            ItemIndisponivelException ex = new ItemIndisponivelException();
            System.out.println(ex.getMessage());
            return;
        }

        System.out.print("O seguinte empréstimo será devolvido, deseja confirmar?\n(1) Sim\n(2) Não\n> ");

        if (sc.nextInt() == 1) {
            ArrayList<Item> items = buscarItem(emprestimos.get(op - 1).getItemEmprestado());
            items.get(0).devolucao(this.backend.contaLogada.getMatricula(), this.databaseLink, emprestimos.get(op - 1));
            System.out.println("Devolução realizada com sucesso!");
        } else {
            System.out.println("Devolução cancelada!");
        }
        sc.nextLine();
    }

    /**
     * Método para listar os empréstimos de um usuário
     */
    public void listarEmprestimos() {
        System.out.printf("===== Empréstimos do usuário(a) %s =====\n", this.backend.contaLogada.getNome());

        ArrayList<Emprestimo> emprestimos = this.backend.listarEmprestimosBackend(1);

        if (emprestimos == null) {
            System.out.println("Não há empréstimos para esse usuário!");
            return;
        }

        for (Emprestimo emprestimo : emprestimos) {
            emprestimo.printEmprestimo();
        }
    }

    /**
     * Método para mostrar quais multas o usuário deve pagar
     * @param sc Scanner para as entradas
     */
    public void pagarMulta(Scanner sc) {
        sc.nextLine();

        ArrayList<Emprestimo> multas = this.backend.listarEmprestimosBackend(3);

        if (multas == null) {
            System.out.println("Não há multas para serem pagas!");
            return;
        }

        System.out.println("===== Escolha qual multa deseja pagar =====");

        for (int i = 0; i < multas.size(); i++) {
            System.out.printf("(%d) %s\nValor = R$ %.2f\n\n", i + 1, multas.get(i).getItemEmprestado(), this.backend.contaLogada.calcularMulta(multas.get(i).getDataDevolucaoReal(), multas.get(i).getDataDevolucaoPrevista()));
        }
        System.out.println("(0) Cancelar pagamento");
        System.out.print("Escolha a multa para realizar o pagamento:\n> ");
        int op = sc.nextInt();

        if (op == 0) {
            System.out.println("Pagamento cancelado com sucesso!");
            return;
        }

        try {
            System.out.printf("Valor a ser pago: R$ %.2f\n", this.backend.contaLogada.calcularMulta(multas.get(op - 1).getDataDevolucaoReal(), multas.get(op - 1).getDataDevolucaoPrevista()));
            multas.get(op - 1).printEmprestimo();
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Multa escolhida inválida!");
            return;
        }

        System.out.print("A seguinte multa será paga, deseja confirmar?\n(1) Sim\n(2) Não\n> ");

        if (sc.nextInt() == 1) {
            this.backend.pagarMultaBackend(multas.get(op - 1).getItemEmprestado());
            System.out.println("Pagamento realizado com sucesso!");
        } else {
            System.out.println("Pagamento cancelado!");
        }
        sc.nextLine();
    }

    /**
     * Método para limpar a tela do terminal
     */
    public static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
}
