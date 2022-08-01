class Solution {
    public int fib(int n) {
        // base condition
        if(n==0)
            return 0;
		if(n==1 || n==2)
            return 1;

        // recursion call that will return (n-1)th & (n-2)th fibo number which will then be added to give us the nth fibo number
		return fib(n-1)+fib(n-2); 
    }
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
