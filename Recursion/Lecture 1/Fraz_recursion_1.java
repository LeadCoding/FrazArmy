import java.io.*;
import java.util.*;

class Main {
    static int factorial(int n) {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n < 0) {
            System.out.println("Error");
        }
        else{
        System.out.println(factorial(n));
        }
    }
}
