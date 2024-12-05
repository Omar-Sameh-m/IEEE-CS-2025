#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    ll maxx = 0;
    for (int i = 0; i < n; i++)
    {

        auto it = lower_bound(b.begin(), b.end(), a[i]);
        ll dist = LONG_LONG_MAX;

        if (it != b.end())
        {
            dist = abs(a[i] - *it);
        }

        if (it != b.begin())
        {
            dist = min(dist, abs(a[i] - *(it - 1)));
        }

        maxx = max(maxx, dist);
    }

    cout << maxx << endl;

    return 0;
}
