import java.util.*;
import java.lang.*;

class Power {
    public static long Pow(int X, int N) {
        if (N == 0)
            return 1;
        long temp = Pow(X, N / 2);
        if (N % 2 == 1)
            return temp * temp * X;
        return temp * temp;
    }

    public static void main(String[] args) {
        int x = 0;
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        int n = 0;
        n = sc.nextInt();
        System.out.println(Pow(x, n));
    }

}