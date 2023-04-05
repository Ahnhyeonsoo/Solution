#include <iostream>
#include <queue>
#include <vector>
#include <windows.h>
using namespace std;

const int N = 5;
int map[N][N] = { 0 };
bool visited[N][N] = { false };

struct Node {
    int x;
    int y;
    int step;
    vector<pair<int, int>> path;
};

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void print_map(int sx, int sy, int ex, int ey, vector<pair<int, int>> path) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i == sx && j == sy) || (i == ex && j == ey)) {
                cout << 1 << " ";
            }
            else {
                bool on_path = false;
                for (auto p : path) {
                    if (p.first == i && p.second == j) {
                        on_path = true;
                        break;
                    }
                }
                if (on_path) {
                    set_color(10);
                    cout << 0 << " ";
                    set_color(7);
                }
                else {
                    cout << 0 << " ";
                }
            }
        }
        cout << endl;
    }
}

int bfs(int sx, int sy, int ex, int ey) {
    queue<Node> q;
    q.push({ sx, sy, 0, {{sx, sy}} });
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == ex && cur.y == ey) {
            print_map(sx, sy, ex, ey, cur.path);
            return cur.step;
        }

        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                vector<pair<int, int>> new_path(cur.path);
                new_path.push_back({ nx, ny });
                q.push({ nx, ny, cur.step + 1,new_path });
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    int sx = 0, sy = 0;
    int ex = 4, ey = 4;
    cout << bfs(sx, sy, ex, ey) << endl;
    return 0;
}