public class Main {
  public static void main(String[] args) {
    Estacionamento carro = new Estacionamento();

    carro.setPlaca("BRA2E19");
    carro.setModeloCarro("HB20");
    carro.setEntrada(new Tempo(12, 35, 56));
    carro.setSaida(new Tempo(13, 23, 46));

    carro.dadosCarro();

    System.out.printf("Valor a pagar do estacionamento: R$%.2f\n", carro.valorPagar());

  }
}
