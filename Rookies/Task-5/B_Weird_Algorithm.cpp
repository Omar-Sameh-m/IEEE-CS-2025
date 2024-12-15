#include <bits/stdc++.h>
#define ll long long
using namespace std;
void recu(ll n)
{

    cout << n;

    if (n == 1)
    {
        cout << endl;
        return;
    }

    if (n % 2 == 0)
    {
        cout << " ";
        recu(n / 2);
    }
    else
    {
        cout << " ";
        recu((n * 3) + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

    recu(n);

    return 0;
}