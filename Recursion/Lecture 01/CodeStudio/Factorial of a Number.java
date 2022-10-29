// This Factorial only works small numbers like 1-15
import java.io.*;
import java.util.*;

class Solution {

    // this function fac() will return us the factorial of the number n
	static int fac(int n){
		if(n==0) return 1;
		
		// recursion call
		return n*fac(n-1); 
	}

	public static void main(String args[]) {
		// Write code here
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		if(n<0){
			System.out.println("Error");
		}
		else{
			System.out.println(fac(n));
		}
	}
}

/*
    time complexity : O(n)
    space complexity : O(n)
*/
