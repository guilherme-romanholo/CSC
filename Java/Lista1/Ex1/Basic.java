import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Basic {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Vector<Integer> v = new Vector<>(3);
        int mult = 0;

        for (int i = 0; i < 3; i++) {
            System.out.printf("Digite o valor de n%d: \n", i+1);
            v.add(sc.nextInt());
            mult += v.get(i);
        }

        System.out.println("Soma " + v.stream().mapToInt(Integer::valueOf).sum());
        System.out.println("Media " + v.stream().mapToInt(Integer::valueOf).sum()/v.size());
        System.out.println("Produto " + mult);
        System.out.println("Maior " + Collections.max(v));
        System.out.println("Menor " + Collections.min(v));

        sc.close();
    }
}