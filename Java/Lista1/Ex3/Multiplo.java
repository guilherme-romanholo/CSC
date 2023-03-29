import java.util.Scanner;

public class Multiplo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1, n2;

        System.out.println("Digite o valor de n1:");
        n1 = sc.nextInt();
        System.out.println("Digite o valor de n2:");
        n2 = sc.nextInt();

        if (n1 % n2 == 0)
            System.out.println("Múltiplos");
        else
            System.out.println("Não Múltiplos");

        sc.close();
    }
}