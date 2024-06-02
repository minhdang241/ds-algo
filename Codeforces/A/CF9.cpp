#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int y, w, cnt=0;
    cin >> y >> w;
    int maxP = max(y,w);
    REP(i,1,6) {
        if (i >= maxP) {
            ++cnt;
        }
    }
    int v = gcd(cnt, 6);
    cout << (cnt/v) << "/" << (6/v);


    return 0;
}
