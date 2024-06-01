#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    string s;
    cin >> n;
    cin >> s;
    vector<int> pos;
    REP(i,0,n-1) {
        cin >> p;
        pos.push_back(p);
    }
    int mi = INT_MAX;
    REP(i,0,n-1) {
        if (i+1 > pos.size()) break;

        if ((s[i] == 'R') && (s[i+1] == 'L')) {
            mi = min(mi, (pos[i+1] - pos[i]) / 2);
        }
    }
    if (mi == INT_MAX) {
        mi = -1;
    }     
    cout << mi;

    return 0;
}
