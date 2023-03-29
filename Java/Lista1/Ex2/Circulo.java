import java.util.Scanner;

public class Circulo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double raio;

        System.out.println("Digite o raio:");
        raio = sc.nextDouble();

        System.out.printf("Diâmetro: %.2lf\n",2*raio);
        System.out.printf("Área: %.2lf\n",Math.PI*raio*raio);
        System.out.printf("Comprimento: %.2lf\n",2*Math.PI*raio);
        
       sc.close(); 
    }
}