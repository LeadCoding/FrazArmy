import java.util.*;
import java.io.*;
public class Solution {
    // this function fibo() will return us the nth fibonacci number
	public static int fibo(int n){

        // base condition
		if(n==1 || n==2) return 1;

        // recursion call that will return (n-1)th & (n-2)th fibo number which will then be added to give us the nth fibo number
		return fibo(n-1)+fibo(n-2); 
	}

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		System.out.println(fibo(n));
	}

}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
