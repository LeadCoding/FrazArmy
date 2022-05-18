import java.io.*;
import java.util.*;

class Main {
    static int factorial(int n) {
        System.out.println(n);
        if (n == 1)
            return 1;
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n < 0) {
            System.out.println("Error");
        }
        System.out.println(factorial(n));
    }
}