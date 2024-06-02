#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, f=0, x=0;
    vector<int> s;
    cin >> n;
    REP(i,0,n-1) {
        cin >> v;
        s.push_back(v);
    }
    int l = 0, r = n-1, t = 0;
    while (l <= r) {
        if (s[l] >= s[r]) {
            if (t % 2 == 0) f += s[l];
            else x += s[l];
            ++l;
        } else {
            if (t % 2 == 0) f += s[r];
            else x += s[r];
            --r;
        }
        ++t;

    }
    cout << f << " " << x;
    return 0;
}
