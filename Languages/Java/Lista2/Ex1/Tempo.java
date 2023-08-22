public class Tempo {
  // Atributos
  private int horas;
  private int minutos;
  private int segundos;

  // Construtores
  public Tempo() {
    this.horas = 0;
    this.minutos = 0;
    this.segundos = 0;
  }

  public Tempo(int hh, int mm, int ss) {
    this.horas = hh;
    this.minutos = mm;
    this.segundos = ss;
  }

  // Getters
  public int getHoras() {
    return horas;
  }

  public int getMinutos() {
    return minutos;
  }

  public int getSegundos() {
    return segundos;
  }

  // Setters
  public void setHoras(int horas) {
    this.horas = horas;
  }

  public void setMinutos(int minutos) {
    this.minutos = minutos;
  }

  public void setSegundos(int segundos) {
    this.segundos = segundos;
  }

  // Outros métodos
  public void imprimirTempo() {
    System.out.printf("%d:%d:%d\n", this.horas, this.minutos, this.segundos);
  }

  public void somaTempo(Tempo t2) {
    this.horas += t2.getHoras();
    this.minutos += t2.getMinutos();
    this.segundos += t2.getSegundos();
  }

  public void somaTempo(Tempo t1, Tempo t2) {
    this.horas = t1.getHoras() + t2.getHoras();
    this.minutos = t1.getMinutos() + t2.getMinutos();
    this.segundos = t1.getSegundos() + t2.getSegundos();
  }

  public void subtraiTempo(Tempo t2) {
    this.horas -= t2.getHoras();
    this.minutos -= t2.getMinutos();
    this.segundos -= t2.getSegundos();
  }
}
