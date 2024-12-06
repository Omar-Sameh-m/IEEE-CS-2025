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
    ll cnt_a = 0, cnt_b = 0;
    ll i = 0;
    ll j = n - 1;
    ll sum_a = 0, sum_b = 0;

    while ((cnt_a + cnt_b) < n && i <= j)
    {
        if ((sum_a < sum_b) || (sum_a == 0 && sum_b == 0))
        {
            sum_a += v[i];
            cnt_a++;
            i++;
        }
        else if (sum_a > sum_b)
        {
            sum_b += v[j];
            cnt_b++;
            j--;
        }
        else if (sum_a == sum_b && (cnt_a + cnt_b == n - 1))
        {
            cnt_a += 1;

            break;
        }

        else
        {
            sum_a += v[i];
            cnt_a++;
            i++;
            sum_b += v[j];
            cnt_b++;
            j--;
        }
    }
    cout << cnt_a << " " << cnt_b << endl;

    return 0;
}