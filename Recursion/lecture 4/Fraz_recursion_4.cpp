#include <bits/stdc++.h>
using namespace std;

long long Pow(int X, int N)
{
    if (N == 0)
        return 1;
    long long temp = Pow(X, N / 2);
    if (N % 2 == 1)
        return temp * temp * X;
    return temp * temp;
}

int main()
{
    long long x;
    cin >> x;
    long long n;
    cin >> n;
    cout << Pow(x, n) ;
}
