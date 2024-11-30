#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll size = s.size();
    vector<ll> diffs;
    for (int i = 0; i < size - 1; i++)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            diffs.push_back((v[i + 1] - v[i]));
        }
    }
    if (diffs.size() == 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        auto minn = min_element(diffs.begin(), diffs.end());
        cout << (*minn / 2);
    }
    return 0;
}
