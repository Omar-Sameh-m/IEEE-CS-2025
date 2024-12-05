#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool can(int x, int n, int k)
{
    int t_sum = 0, c_sum = x;
    while (c_sum > 0)
    {
        t_sum += c_sum;
        if (t_sum >= n)
        {
            return true;
        }
        c_sum /= k;
    }
    return t_sum >= n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int low = 1, high = n, result = n;
    while (low <= high)
    {
        int mid = low + (high - mid) / 2;
        if (can(mid, n, k))
        {
            high = mid - 1;
            result = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << result << endl;

    return 0;
}