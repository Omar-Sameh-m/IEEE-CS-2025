#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    ll diff;
    cin >> n >> diff;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        auto it = lower_bound((v.begin() + i + 1), v.end(), (v[i] + diff));
        if (it != v.end() && ((*it - v[i]) <= diff))
        {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}