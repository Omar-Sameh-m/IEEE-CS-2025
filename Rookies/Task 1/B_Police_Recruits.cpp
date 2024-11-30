#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (auto i : v)
    {
        if (i != -1)
        {
            cnt += i;
        }
        else
        {
            if (cnt == 0)
            {
                ans++;
            }
            else
            {
                cnt--;
            }
        }
    }
    cout << ans;

    return 0;
}
