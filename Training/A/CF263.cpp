#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<= b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v;
    REP(i,0,4) {
        REP(j,0,4) {
            cin >> v;
            if (v == 1) {
                cout << abs(i-2) + abs(j-2);
            }
        }
    }

    return 0;
}
