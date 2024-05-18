#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt=0;
    string s;
    cin >> n >> s;
    char pre = '\0';
    REP(i,0,n-1) {
        if (pre == '\0') {
            pre = s[i];
        } else {
            if (s[i] == pre) {
                ++cnt;
            } else {
                pre = s[i];
            }
        }
    }
    cout << cnt;

    return 0;
}
