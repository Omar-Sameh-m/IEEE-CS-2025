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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int maxx = v[0], minn = v[0];
    int max_index = 0, min_index = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i] > maxx)
        {
            maxx = v[i];
            max_index = i;
        }
        if (v[i] <= minn)
        {
            minn = v[i];
            min_index = i;
        }
    }

    int ans = max_index + (n - 1 - min_index);
    if (max_index > min_index)
    {

        ans--;
    }

    cout << ans << endl;

    return 0;
}
