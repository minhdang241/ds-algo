#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, p = 0, r = 0;
    cin >> n;
    REP(i,0,n-1) {
        cin >> v; 
        if (v >= 0) {
            p += v;
        } else {
            if (abs(v) <= p) p-=abs(v);
            else ++r;
        }

    }
    cout << r;
    return 0;
}
