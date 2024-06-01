#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    unordered_map<string, int> m;
    int n;
    cin >> n;
    REP(i,0,n-1) {
        cin >> t;
        m[t] += 1;
    }
    string ct;
    int cs = 0;
    for (const auto& p : m) {
        if (p.second > cs) {
            cs = p.second;
            ct = p.first;
        }
    }
    cout << ct;
    
    return 0;
}
