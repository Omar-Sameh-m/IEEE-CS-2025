#include <bits/stdc++.h>
#define ll long long
using namespace std;

void permutations(string &s, int start, set<string> &result)
{
    if (start == s.size())
    {
        result.insert(s);
        return;
    }

    for (int i = start; i < s.size(); i++)
    {
        swap(s[start], s[i]);
        permutations(s, start + 1, result);
        swap(s[start], s[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    set<string> result;
    permutations(s, 0, result);

    cout << result.size() << endl;
    for (auto i : result)
    {
        cout << i << endl;
    }

    return 0;
}
