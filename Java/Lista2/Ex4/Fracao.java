import java.util.Scanner;

public class Fracao {
    private int numerador;
    private int denominador;

    public Fracao(int numerador, int denominador) {
        this.numerador = numerador;
        if (denominador <= 0){
            int val;
            do {
                Scanner sc = new Scanner(System.in);
                System.out.println("Valor do denominador inválido. Digite outro:");
                val = sc.nextInt();
            } while (val <= 0);
            this.denominador = val;
        } else {
            this.denominador = denominador;
        }
    }

    public Fracao adicao(Fracao f2) {
        int denominador = Fracao.mmc(this.denominador, f2.getDenominador());
        int numerador = ((denominador / this.denominador) * this.numerador) + ((denominador / f2.getDenominador()) * f2.getNumerador());
        Fracao soma = new Fracao(numerador,denominador);
        return soma;
    }

    public Fracao subtracao(Fracao f2) {
        int denominador = Fracao.mmc(this.denominador, f2.getDenominador());
        int numerador = ((denominador / this.denominador) * this.numerador) - ((denominador / f2.getDenominador()) * f2.getNumerador());
        return new Fracao(numerador,denominador);
    }

    public Fracao multiplicacao(Fracao f2) {
        int denominador = this.denominador * f2.getDenominador();
        int numerador = this.numerador * f2.getNumerador();
        return new Fracao(numerador,denominador);
    }

    public Fracao divisao(Fracao f2) {
        int denominador = this.denominador * f2.getNumerador();
        int numerador = this.numerador * f2.getDenominador();
        return new Fracao(numerador,denominador);
    }

    public void simplifica() {
        while (this.denominador % 2 == 0 && this.numerador % 2 == 0){
            this.denominador /= 2;
            this.numerador /= 2;
        }

        while (this.denominador % 3 == 0 && this.numerador % 3 == 0){
            this.denominador /= 3;
            this.numerador /= 3;
        }
    }

    public static int mdc(int a, int b) {
        while (b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public static int mmc(int a, int b) {
        return a * (b / Fracao.mdc(a, b));
    }

    public int getDenominador() {
        return denominador;
    }

    public int getNumerador() {
        return numerador;
    }
}
