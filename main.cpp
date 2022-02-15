// 23048
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
void pv(const vector<int>& arr) { for (auto item : arr) cout << item << ' '; cout << '\n'; }

int n, m;
vector<string> arr;

bool isSafe(int x, int y) {
    return (0 <= x and x < n) and (0 <= y and y < m);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(pair<int, int> start) {
    deque<pair<int, int>> q;
    q.push_back(start);

    vector<vector<int>> check(n, vector<int>(m, 0));
    check[q.front().first][q.front().second] = 1;

    int ans = INT_MIN;
    while (!q.empty()) {
        auto& [x, y] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isSafe(nx, ny)) {
                if (arr[nx][ny] == 'L' and check[nx][ny] == 0) {
                    check[nx][ny] = check[x][y] + 1;
                    q.push_back({nx, ny});
                    if (ans < check[nx][ny]) ans = check[nx][ny];
                }
            }
        }
    }

    if (ans == INT_MIN) return 0;
    return ans - 1;
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n; cin >> n;
    vector<ll> arr(n + 1, 0);
    arr[0] = 0; arr[1] = 1;

    ll now_col = 2;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            for (int j = i; j <= n; j += i) {
                arr[j] = now_col;
            }
            now_col++;
        }
    }


    cout << now_col - 1 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}