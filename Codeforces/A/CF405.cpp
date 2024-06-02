#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v;
    cin >> n;
    vector<int> a;
    REP(i,0,n-1) {
        cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());
    REP(i,0,n-1) {
        cout << a[i] << " ";
    }

    return 0;
}
