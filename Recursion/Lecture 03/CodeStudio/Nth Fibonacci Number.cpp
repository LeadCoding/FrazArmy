#include <iostream>
using namespace std;

// this function fibo() will return us the nth fibonacci number
int fibo(int n)
{
    // base condition
    if (n == 1 || n == 2)
        return 1;

    //  recursion call that will give us the (n-1)th fibo number
    int ans1 = fibo(n - 1);

    // recursion call that will give us the (n-2)th fibo number
    int ans2 = fibo(n - 2);

    // will return the addition of (n-1)th & (n-2)th fibo number which is actually our nth fibo number that we need
    return ans1 + ans2;     
}
int main()
{
    // Write your code here.
    int n;
    cin >> n;
    n = fibo(n);
    cout << n;
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
