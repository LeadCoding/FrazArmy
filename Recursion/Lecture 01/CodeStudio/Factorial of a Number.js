// this function fac() will return us the factorial of the number n
function fact(n) {
  /* Write your code here */
  if (n == 0) return 1;
  if (n < 0) return "Error";
  
  // recursion call
  else return n * fact(n - 1); 
}

/*
    time complexity : O(n)
    space complexity : O(n)
*/
