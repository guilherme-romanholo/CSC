public class Main {
  public static void main(String[] args) {
    Tempo t1 = new Tempo(12, 12, 12);
    Tempo t2 = new Tempo(15, 15, 15);
    Tempo t3 = new Tempo();

    t1.somaTempo(t2);
    t3.somaTempo(t1, t2);

    t1.imprimirTempo();
    t2.imprimirTempo();
    t3.imprimirTempo();
  }
}
