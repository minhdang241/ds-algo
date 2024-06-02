#include <bits/stdc++.h>
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 0;
    cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'A') ++r;
        else --r;
    }

    if (r == 0) cout << "Friendship";
    else if (r > 0) cout << "Anton";
    else cout << "Danik";
    return 0;
}
