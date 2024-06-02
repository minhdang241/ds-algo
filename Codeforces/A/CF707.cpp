#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    char c;
    set<char> s{'W', 'B', 'G'};
    REP(i,0,n-1) {
        REP(j,0,m-1) {
            cin >> c;
            if (s.count(c) == 0) {
                cout << "#Color";
                return 0;
            }

        }
    }
    cout << "#Black&White";


    return 0;
}
