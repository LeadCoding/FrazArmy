class Solution {
  public:
    int fib(int n) {
        
      // base condition
      if (n == 0)
        return 0;

      if (n == 1 || n == 2)
        return 1;

      //  recursion call that will give us the (n-1)th fibo number
      int ans1 = fib(n - 1);

      // recursion call that will give us the (n-2)th fibo number
      int ans2 = fib(n - 2);

      // will return the addition of (n-1)th & (n-2)th fibo number which is actually our nth fibo number that we need
      return ans1 + ans2; 
    }
};

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
