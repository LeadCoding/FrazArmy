class Solution
{
public:
  double myPow(double x, int n)
  {
    // base condition
    if (n == 0)
      return 1;

    // when n is negative then this if-statement will be execute
    if (n < 0)
    {
      x = 1 / x;
      n = abs(n);
    }
    double temp = myPow(x, n / 2);

    // if N is odd then we will have to multiply X
    if (n % 2 == 1)
      return temp * temp * x;

    return temp * temp;
  }
};

/*
    time complexity : O(log n)
    space complexity : O(log n)
*/