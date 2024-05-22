#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    REP(i,0,n-1) {
        cin >> s;
        if (s.size() > 10) {
            s=s.replace(1, s.size()-2, to_string(s.size()-2));
        }
        cout << s << endl;
    }

    return 0;
}
