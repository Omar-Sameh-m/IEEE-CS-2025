#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            auto start = (v.begin() + i + 1);
            auto low = lower_bound(start, v.end(), (l - v[i])) - v.begin();
            auto high = upper_bound(start, v.end(), (r - v[i])) - v.begin();
            cnt += (high - low);
        }
        cout << cnt << endl;
    }

    return 0;
}