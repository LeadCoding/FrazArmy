#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    cout << n << endl;
    if (n == 0)
        return 1;
    int partialAns = factorial(n - 1);
    return n * partialAns;
}

int main()
{
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << "Error";
    }
    else
    {
        cout << factorial(n);
    }
    return 0;
}
