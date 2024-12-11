#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<pair<int, int>> possible_moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y, int n, int m)
{
    return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

void find_path(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited, int n, int m)
{
    visited[x][y] = true;

    for (auto i : possible_moves)
    {
        int nx = x + i.first;
        int ny = y + i.second;

        if (isValid(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == '.')
        {
            find_path(nx, ny, grid, visited, n, m);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                find_path(i, j, grid, visited, n, m);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}