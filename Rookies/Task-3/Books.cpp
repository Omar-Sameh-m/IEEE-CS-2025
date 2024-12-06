#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int left = 0;
    ll current_sum = 0;
    ll ans = 0;
    for (ll right = 0; right < n; right++)
    {
        current_sum += v[right];
        while (current_sum > t)
        {
            current_sum -= v[left];
            left++;//كاني بنقص كتاب 
        }

        ans = max(ans, (right - left + 1));
    }
    cout << ans;

    return 0;
}