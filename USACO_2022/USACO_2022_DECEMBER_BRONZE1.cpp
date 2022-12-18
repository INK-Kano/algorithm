/*
 * 정답
 * ==========================================================================
 * 1 4 6 7 8 9
 * ==========================================================================
 * 문제 설명
 * ==========================================================================
 * 소들의 대학이 있는데 총장이 등록금을 설정하려고 한다.
 * 학생들은 N만큼 있고, 각 학생은 최대 C[i]의 등록금을 내려고 한다.(C[i]를 초과하면 입학 안함)
 * 총장은 등록금을 최대로 받아내고 싶기 때문에 총 등록금이 최대가 되는 등록금과
 * 그 때 총 얼마의 등록금을 받을 수 있는지 구하여라.
 * ps. 여러 가지 경우가 가능할 때에는 최대가 되는 등록금이 가장 작은 값으로 하여라.
 * ==========================================================================
 * 예제
 * ==========================================================================
 * N = 4, C = [1, 6, 6, 4]일 때, 최대의 등록금이 되는 경우는 4와 6이 있다.
 * 등록금이 4일 때 -> 등록금이 4이고 3명이 등록할 수 있으므로 4 * 3 = 12
 * 등록금이 6일 때 -> 등록금이 6이고 2명이 등록할 수 있으므로 6 * 2 = 12
 * 이 중 답이 여러 개일 땐 등록금이 가장 작은 값을 구해야 하므로 등록금은 4이고, 총 등록금은 12이다.
 * ==========================================================================
 * 코드의 구현
 * ==========================================================================
 * 이분 탐색으로 구현하였다.
 * ==========================================================================
 * 문제점
 * ==========================================================================
 * 이분 탐색에서 left, right의 이동 조건을 잘못 짠듯 하다.
 */
#include <bits/stdc++.h>

#define in :
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using dv = vector<vector<int>>;

int main()
{
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

#ifdef NDEBUG
    freopen("input.txt", "r", stdin);
#endif

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll left = 0, right = arr.size() - 1;
    ll mid;

    ll ans = LONG_LONG_MIN, ans2 = 0;
    while (left <= right) {
        mid = (left + right) / 2;

        ll temp = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= arr[mid]) temp += arr[mid];
        }

        if (temp > ans) {
            ans = temp;
            ans2 = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << ' ' << ans2;

    return 0;
}