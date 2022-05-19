import java.util.*;
class Test2{
    public static int fibo(int n){
        if(n == 1 || n==2){
            return 1;
        }
        return fibo(n-1) + fibo(n-2);
    }
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(fibo(n));
	}
}