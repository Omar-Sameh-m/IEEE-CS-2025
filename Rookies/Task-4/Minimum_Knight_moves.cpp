#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int board_size = 8;
vector<pair<int, int>> possible_moves = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

bool isValid(int x, int y)
{
    return (x >= 0) && (x < board_size) && (y >= 0) && (y < board_size);
}

int knightMinMoves(string start, string destination)
{
    if (start == destination)
    {
        return 0;
    }

    int start_x = start[0] - 'a', start_y = start[1] - '1';
    int dest_x = destination[0] - 'a', dest_y = destination[1] - '1';

    queue<pair<int, int>> q;
    vector<vector<int>> visited(board_size, vector<int>(board_size, 0));

    q.push({start_x, start_y});
    visited[start_x][start_y] = 1;

    int moves = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto [current_x, current_y] = q.front();
            q.pop();

            if (current_x == dest_x && current_y == dest_y)
                return moves;

            for (auto [dx, dy] : possible_moves)
            {
                int new_x = current_x + dx;
                int new_y = current_y + dy;

                if (isValid(new_x, new_y) && !visited[new_x][new_y])
                {
                    visited[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        ++moves;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string start, destination;
        cin >> start >> destination;
        cout << knightMinMoves(start, destination) << endl;
    }

    return 0;
}