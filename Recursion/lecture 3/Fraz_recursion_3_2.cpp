#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    int partialAns1 = fibo(n - 1);
    int partialAns2 = fibo(n - 2);
    return partialAns1 + partialAns2;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
}
