#include <bits/stdc++.h>
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v, cnt = 0;
        for (int j = 0; j < 3; j++) {
            cin >> v;
            cnt += v;
        }
        if (cnt >= 2) ++ans;
    }
    cout << ans;

    return 0;
}
