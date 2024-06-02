#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,b,d, td = 0, ans = 0;
    cin >> n >> b >> d;
    int v;
    REP(i,0,n-1) {
        cin >> v;
        if (v > b) continue;
        td += v;
        if (td > d) {
            td = 0;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
