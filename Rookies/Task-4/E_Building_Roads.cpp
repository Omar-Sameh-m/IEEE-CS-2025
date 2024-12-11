#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<bool> visited(n, false);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans.push_back(i);
            dfs(i, adj, visited);
        }
    }

    int k = ans.size() - 1;
    cout << k << endl;

    for (int i = 1; i < ans.size(); i++)
    {
        cout << (ans[i - 1] + 1) << " " << (ans[i] + 1) << endl;
    }

    return 0;
}