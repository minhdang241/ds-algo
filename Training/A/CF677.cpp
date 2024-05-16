#include <bits/stdc++.h>
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h, x, ans=0;
    cin >> n >> h;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > h) ans += 2;
        else ans += 1;
    }
    cout << ans;
    return 0;
}
