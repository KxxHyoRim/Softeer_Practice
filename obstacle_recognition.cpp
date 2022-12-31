#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[25][25];
bool visited[25][25];

int dfs(int x, int y) {
    visited[y][x] = true;
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                int rtn = dfs(nx, ny);
                count += rtn;
            }
        }
    }
    return count;
}


int main() {

    cin >> n;

    for (int y = 0; y < n; y++) {
        string temp;
        cin >> temp;
        for (int x = 0; x < n; x++) {
            if (temp[x] == '0')
                map[y][x] = 0;
            else map[y][x] = 1;
        }
    }

    priority_queue<int> pq;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] == 1 && !visited[y][x]) {
                pq.push(-dfs(x, y));
            }
        }
    }

    cout << pq.size() << endl;
    while(!pq.empty()){
        cout << -pq.top() << "\n";
        pq.pop();
    }
    return 0;
}