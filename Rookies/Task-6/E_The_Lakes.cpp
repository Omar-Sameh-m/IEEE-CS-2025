#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool valid(int x, int y, vector<vector<int>> &a, vector<vector<bool>> &visited)
{
    return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (a[x][y] > 0) && (!visited[x][y]);
}

int dfs(int x, int y, vector<vector<int>> &a, vector<vector<bool>> &visited)
{
    visited[x][y] = 1;
    int path = a[x][y];

    for (int i = 0; i < 4; i++)//four directions
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny, a, visited))
        {
            path += dfs(nx, ny, a, visited);
        }
    }

    return path;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (a[i][j] > 0 && !visited[i][j])
                {

                    ans = max(ans, dfs(i, j, a, visited));
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
