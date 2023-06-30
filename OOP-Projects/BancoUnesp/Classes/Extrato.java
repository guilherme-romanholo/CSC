import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 * <p>Classe utilizada para guardar as informações referentes ao extrato de uma conta</p>
 * @author Guilherme Romanholo Bofo
 */
public class Extrato {
    private LocalDateTime dataMov;
    private String tipo;
    private double valor;
    private Conta destino;
    private String operador;
    private double saldoMomento;

    /**
     * <p>Método construtor da classe extrato</p>
     * @param tipo Tipo da operação realizada
     * @param val Valor da movimentação
     * @param destino Conta de destino
     * @param operador Quem realizou a operação
     * @param saldoMomento Saldo da conta após a operação
     */
    public Extrato(String tipo, double val, Conta destino, String operador, Double saldoMomento) {
        this.tipo = tipo;
        this.valor = val;
        this.destino = destino;
        this.operador = operador;
        this.saldoMomento = saldoMomento;
        this.dataMov = LocalDateTime.now();
    }

    /**
     * <p>Função para printar as informações armazenadas no objeto do tipo Extrato</p>
     */
    public void printExtrato() {
        // Formatores da data e do horário da operação
        DateTimeFormatter fdate = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        DateTimeFormatter ftime = DateTimeFormatter.ofPattern("HH:mm:ss");

        // Output das informações do extrato
        System.out.println("==============================");
        System.out.printf("Tipo: %s\n",this.tipo);
        System.out.printf("Valor: R$%.2f\n",this.valor);
        System.out.println("Data: " + dataMov.format(fdate));
        System.out.println("Horário: " + dataMov.format(ftime));
        if (!this.tipo.equals("Saque")) {
            System.out.printf("Conta destino: %d\n",this.destino.getNumeroConta());
            System.out.printf("Nome do destinatário: %s\n",this.destino.getNome());
        }
        System.out.printf("Nome do operador: %s\n",this.operador);
        System.out.printf("Saldo: R$%.2f\n",this.saldoMomento);
        System.out.println("==============================");
    }
}
