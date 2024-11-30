#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

    char c;
    cin >> c;
    string to_translate;
    cin >> to_translate;
    if (c == 'R')
    {
        int size = to_translate.size();
        for (int i = 0; i < size; i++)
        {
            int idx = keyboard.find(to_translate[i]);
            cout << keyboard[--idx];
        }
    }
    else
    {
        int size = to_translate.size();
        for (int i = 0; i < size; i++)
        {
            int idx = keyboard.find(to_translate[i]);
            cout << keyboard[++idx];
        }
    }

    return 0;
}
