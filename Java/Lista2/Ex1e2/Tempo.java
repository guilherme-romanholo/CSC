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
    this.setHoras(hh);
    this.setMinutos(mm);
    this.setSegundos(ss);
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
    if (horas >= 0 && horas < 24)
      this.horas = horas;
    else
      this.horas = 0;
  }

  public void setMinutos(int minutos) {
    if (minutos >= 0 && minutos < 60)
      this.minutos = minutos;
    else
      this.minutos = 0;
  }

  public void setSegundos(int segundos) {
    if (segundos >= 0 && segundos < 60)
      this.segundos = segundos;
    else
      this.segundos = 0;
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

  public void subtraiTempo(Tempo t1, Tempo t2) {
    this.horas = t1.getHoras() - t2.getHoras();
    this.minutos = t1.getMinutos() - t2.getMinutos();
    this.segundos = t1.getSegundos() - t2.getSegundos();
  }
}
