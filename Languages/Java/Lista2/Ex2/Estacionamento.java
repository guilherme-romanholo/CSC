public class Estacionamento {
  private String placa;
  private String modeloCarro;
  private Tempo entrada;
  private Tempo saida;

  public Estacionamento() {
    this.placa = "";
    this.modeloCarro = "";
    this.entrada = null;
    this.saida = null;
  }

  public void dadosCarro() {
    System.out.printf("Placa: %s\n", this.placa);
    System.out.printf("Modelo: %s\n", this.modeloCarro);
    System.out.printf("Hora de entrada: ");
    this.entrada.imprimirTempo();
    System.out.printf("Hora de saída: ");
    this.saida.imprimirTempo();
  }

  public double valorPagar() {
    Tempo diff = new Tempo();
    diff.subtraiTempo(saida, entrada);
    return diff.getHoras() * 1.50;
  }

  // Setters
  public void setPlaca(String placa) {
    this.placa = placa;
  }

  public void setModeloCarro(String modeloCarro) {
    this.modeloCarro = modeloCarro;
  }

  public void setEntrada(Tempo entrada) {
    this.entrada = entrada;
  }

  public void setSaida(Tempo saida) {
    this.saida = saida;
  }

  // Getters
  public String getPlaca() {
    return placa;
  }

  public String getModeloCarro() {
    return modeloCarro;
  }

  public Tempo getEntrada() {
    return entrada;
  }

  public Tempo getSaida() {
    return saida;
  }
}
