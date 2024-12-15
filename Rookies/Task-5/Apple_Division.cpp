#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll diff(vector<ll> &v, int n, int index, ll g1, ll g2)
{

    if (index == n)
    {
        return abs(g1 - g2);
    }

    ll g1_val = diff(v, n, index + 1, g1 + v[index], g2);

    ll g2_val = diff(v, n, index + 1, g1, g2 + v[index]);

    return min(g1_val, g2_val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    ll ans = diff(v, n, 0, 0, 0);

    cout << ans << endl;

    return 0;
}