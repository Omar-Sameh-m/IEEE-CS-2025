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

    ll max_books = 0;
    ll current_sum = 0;
    ll left = 0;

    for (ll right = 0; right < n; right++)
    {
        current_sum += v[right];

        while (current_sum > t)
        {
            current_sum -= v[left];
            left++;
        }

        max_books = max(max_books, (right - left + 1)); //(right - left + 1) الي هي عدد الكتب الي اتقرت مجموعهم اقل من الفري تايم
    }

    cout << max_books << endl;

    return 0;
}
