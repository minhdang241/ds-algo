#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    int a, b;
    REP(i,0,n-1) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    int ans = 0;
    REP(i,0,n-1) {
        pair<int, int> p1 = v[i];
        REP(j,i+1,n-1) {
            pair<int, int> p2 = v[j];
            if (p1.first == p2.second) ++ans;
            if (p1.second == p2.first) ++ans;
        }
    }
    cout << ans;



    return 0;
}
