#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll left = 0;
    ll diff = 5;
    ll cnt = 0;
    sort(v.begin(), v.end());
    for (int right = 0; right < n; right++)
    {
        if (abs(v[right] - v[left]) > diff)
        {

            left++;
        }
        else
        {
            cnt = max(cnt, ((right - left) + 1));
        }
    }

    cout << cnt << endl;

    return 0;
}