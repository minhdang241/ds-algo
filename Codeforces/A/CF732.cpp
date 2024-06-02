#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, r;
    cin >> c >> r;
    REP(i,1,10) {
        if ((i*c - r) % 10 == 0) {
            cout << i;
            return 0;
        }
        if ((i*c) % 10 == 0) {
            cout << i;
            return 0;
        }
    }

    return 0;
}
