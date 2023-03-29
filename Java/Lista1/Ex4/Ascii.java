import java.util.Scanner;

public class Ascii {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o caractere:");
        char c = sc.next().charAt(0);

        System.out.printf("%d\n", (int)c);

        sc.close();
    }
}