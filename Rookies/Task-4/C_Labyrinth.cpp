#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<tuple<int, int, char>> possible_moves = {{0, -1, 'L'}, {0, 1, 'R'}, {1, 0, 'D'}, {-1, 0, 'U'}};

bool isValid(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y]);
}

void BFS(int n, int m, vector<vector<char>> &grid, pair<int, int> start, pair<int, int> dest)
{
    queue<pair<int, int>> q;//pair queue
    vector<vector<bool>> visited(n, vector<bool>(m, false));//2d bool
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));//2d pair 
    vector<vector<char>> direction(n, vector<char>(m, ' '));//2d char

    q.push(start);//start node
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if (current == dest)
        {
            vector<char> path;
            pair<int, int> node = dest;

            while (node != start)
            {
                path.push_back(direction[node.first][node.second]);
                node = parent[node.first][node.second];
            }

            reverse(path.begin(), path.end());

            cout << "YES" << endl;
            cout << path.size() << endl;
            for (char dir : path)
            {
                cout << dir;
            }
            cout << endl;
            return;
        }

        for (auto [dx, dy, dir] : possible_moves)
        {
            int nx = current.first + dx;
            int ny = current.second + dy;

            if (isValid(nx, ny, n, m, grid, visited))
            {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                direction[nx][ny] = dir;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, dest;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                dest = {i, j};
            }
        }
    }

    BFS(n, m, grid, start, dest);

    return 0;
}