#include <bits/stdc++.h>
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, ans = 0;
    cin >> x >> y;
    
    while (x <= y) {
        x*=3;
        y*=2;
        ans += 1;
    }
    cout << ans;

    return 0;
}
