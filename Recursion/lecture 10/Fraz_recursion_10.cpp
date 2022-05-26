#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll query(ll x)
{
    cout << "? " << x << endl;
    cout << flush;
    cin >> x;
    return x;
}

void helper(vector<int> &v, int i, vector<int> &subSet, vector<vector<int>> &ans)
{
    if (i == v.size())
    {
        ans.push_back(subSet);
        return;
    }
    // include the ith element
    subSet.push_back(v[i]);
    helper(v, i + 1, subSet, ans);
    // not including the ith element
    subSet.pop_back();
    while (i + 1 < v.size() && v[i] == v[i + 1])
        i++;
    helper(v, i + 1, subSet, ans);
}

vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> subSet;
    helper(v, 0, subSet, ans);
    sort(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    
}

int main()
{

    int t = 1;
    cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {
        solve();
    }

    return 0;
}