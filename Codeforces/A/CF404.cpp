#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // vector<vector<char>> m;
    char c;
    char anchor='\0';
    set<char> s;
    string ans = "YES";
    REP(i,0,n-1) {
        REP(j,0,n-1) {
            cin >> c;
            if (i==0 && j == 0) anchor = c;
            if (i==j) {
                if (c != anchor) ans =  "NO";
            } else if ((i+j) == (n-1)) {
                if (c != anchor) ans = "NO";
            } else {
                if (c == anchor) ans = "NO";
                s.insert(c);
            }
        }
    }
    if (s.size() > 1) ans = "NO";
    cout << ans;
    return 0;
}










