#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    while (cin >> x) {
        if (x == 0) return 0;
        int cnt = 0;
        REP(i,1,sqrt(x)) {
            if (x % i == 0) {
                ++cnt;
            }
        }
        if (cnt != 2 == 0) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}
