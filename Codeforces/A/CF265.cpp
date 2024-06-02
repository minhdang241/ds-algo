#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, c;
    cin >> s >> c;
    int p = 1, j = 0;
    REP(i,0,c.size()-1) {
        if (c[i] == s[j]) {
            ++p;
            ++j;
        };
    }
    cout << p;

    return 0;
}
