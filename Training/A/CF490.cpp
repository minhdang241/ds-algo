#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    unordered_map<int, vector<int>> m;
    REP(i,0,n-1) {
        cin >> x;
        if (m.find(x) == m.end()) {
            m[x] = {i+1};
        } else m[x].push_back(i+1);
        //cout << x << " " << m[x].size() << endl;
    }
    int maxTeam=5000;
    if (m.size() != 3) {
        cout << 0; 
        return 0;
    }
    for (const auto& p: m) {
        maxTeam = min(maxTeam, (int) p.second.size());
    }
    cout << maxTeam << "\n";
    REP(i,0,maxTeam-1) {
        for (const auto& p: m) {
            vector<int> v = p.second;
            cout << v[(int)v.size()-i-1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
