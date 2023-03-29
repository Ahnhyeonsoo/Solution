#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if (!visited[next_node]) {
            dfs(graph, visited, next_node);
        }
    }
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start_node) {
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if (!visited[next_node]) {
                visited[next_node] = true;
                q.push(next_node);
            }
        }
    }
}

DWORD WINAPI CheckEscape(LPVOID lpParam) {
    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE) < 0) {
            exit(0);
        }
        Sleep(10);
    }
}

int main() {
    int n, m, start_node;
    cin >> n >> m >> start_node;

    CreateThread(NULL, 0, CheckEscape, NULL, 0, NULL);

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(n + 1, false);

    dfs(graph, visited, start_node);
    cout << endl;

    visited.assign(n + 1, false);
    bfs(graph, visited, start_node);
    cout << endl;

    return 0;
}