#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int y;
    int x;
};

int maze[26][26];
int visited[26][26];
int N;
int res = 0;
int sizeofb = 0;
vector<int> reslist;
const int direct[4][2] = {
    -1, 0,
    1, 0,
    0, -1,
    0, 1};

void bfs(Point now)
{
    visited[now.y][now.x] = 1;
    queue<Point> q;
    q.push(now);
    sizeofb++;
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + direct[i][0];
            int nx = now.x + direct[i][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx] == 1)
                continue;
            if (maze[ny][nx] == 0)
                continue;
            q.push({ny, nx});
            visited[ny][nx] = 1;
            sizeofb++;
        }
    }
}

int main(int argc, char **argv)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temps;
        cin >> temps;
        for (int j = 0; j < N; j++)
        {
            maze[i][j] = temps[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 1)
            {
                continue;
            }
            if (maze[i][j] == 0)
            {
                continue;
            }
            res++;
            sizeofb = 0;
            bfs({i, j});
            reslist.push_back(sizeofb);
        }
    }
    sort(reslist.begin(), reslist.end());
    cout << res << '\n';
    for (auto temp : reslist)
    {
        cout << temp << '\n';
    }
    return 0;
}