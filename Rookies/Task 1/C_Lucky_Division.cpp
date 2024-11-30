#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool is_devisible(int n)
{
    return (n % 4 == 0) || (n % 7 == 0) ||
           (n % 44 == 0) || (n % 47 == 0) ||
           (n % 74 == 0) || (n % 77 == 0) ||
           (n % 444 == 0) || (n % 447 == 0) ||
           (n % 474 == 0) || (n % 777 == 0);
}

bool isLucky(int n)
{
    string s = to_string(n);
    for (char c : s)
    {
        if (!(c == '4' || c == '7'))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    if (is_devisible(n) || isLucky(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
