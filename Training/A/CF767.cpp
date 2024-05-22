#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    vector<int> v1, v2;
    cin >> n;
    REP(i,1,n) {
        cin >> x;
        v1.push_back(x);
    }
    v2 = v1;
    sort(v2.rbegin(), v2.rend());
    int j = 0;
    unordered_set<int> s;
    REP(i,0,n-1) {
        if (v2[j] == v1[i]) {
            cout << v2[j];
            ++j;
            while (s.count(v2[j])) {
                cout << " " << v2[j];
                ++j;
            }
            cout << "\n";
        } else {
            s.insert(v1[i]);
            cout << "\n";
        }
    }

    return 0;
}
