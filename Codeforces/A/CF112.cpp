#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
void toLower(string& s) {
    REP(i,0,s.size()) {
        s[i] = tolower(s[i]);
    }
}
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    cin >> x >> y;
    toLower(x);
    toLower(y);
    if (x == y) cout << 0;
    else if (x > y) cout << 1;
    else cout << -1;


    return 0;
}
