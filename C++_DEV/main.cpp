// 23747
#include <bits/stdc++.h>

#define in :
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using dv = vector<vector<int>>;
void pv(const vector<int>& arr) { for (auto item : arr) cout << item << ' '; cout << '\n'; }

int n, m;
string s;
string arr[1001];
char ans[1001][1001];
bool check[1001][1001];

bool isSafe(int x, int y) {
    return (0 <= x and x < n) and (0 <= y and y < m);
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void bfs(int x, int y) {
    queue<pii> q;
    ans[x][y] = '.';
    check[x][y] = true;
    q.push({x, y});

    while (!q.empty()) {
        auto [nowX, nowY] = q.front();
        q.pop();

        check[nowX][nowY] = true;
        for (int i = 0; i < 4; i++) {
            int nx = nowX + dx[i];
            int ny = nowY + dy[i];

            if (isSafe(nx, ny) and !check[nx][ny] and arr[nx][ny] == arr[nowX][nowY] and ans[nx][ny] != '.') {
                ans[nx][ny] = '.';
                q.push({nx, ny});
            }
        }
    }
}

void solve(int startX, int startY) {
    int nowX = startX, nowY = startY;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U') nowX--;
        else if (s[i] == 'D') nowX++;
        else if (s[i] == 'L') nowY--;
        else if (s[i] == 'R') nowY++;
        else {
            if (ans[nowX][nowY] != '.') bfs(nowX, nowY);
        }
    }

    ans[nowX][nowY] = '.';
    for (int i = 0; i < 4; i++) {
        int nx = nowX + dx[i];
        int ny = nowY + dy[i];
        if (isSafe(nx, ny)) ans[nx][ny] = '.';
    }
}

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

#ifdef NDEBUG
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = '#';
        }
    }
    for (int i = 0; i < n; i++) cin >> arr[i];

    int x, y;
    cin >> x >> y;
    cin >> s;

    x--, y--;
    solve(x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}