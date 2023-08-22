import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Matrizes teste = new Matrizes();
        Matrizes teste2 = new Matrizes();
        Scanner sc = new Scanner(System.in);

        teste.setCol(2); 
        teste.setLin(2);
        teste.alloc();
        System.out.println("Digite os valores da matriz 1");
        for (int i = 0; i < teste.getLin(); i++) {
            for (int j = 0; j < teste.getCol(); j++) {
               teste.setMat(i,j,sc.nextDouble()); 
            }
        }
        teste.printMat();
 
        teste2.setCol(2);
        teste2.setLin(2);
        teste2.alloc();
        System.out.println("Digite os valores da matriz 2");
        for (int i = 0; i < teste2.getLin(); i++) {
            for (int j = 0; j < teste2.getCol(); j++) {
               teste2.setMat(i,j,sc.nextDouble()); 
            }
        }
        teste2.printMat();

        teste.multMat(teste2);

        sc.close();
    }
}