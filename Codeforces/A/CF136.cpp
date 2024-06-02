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
    unordered_map<int, int> m;
    int x;
    REP(i,1,n) {
        cin >> x;
        m[x] = i;
    }
    REP(i,1,n) {
        cout << m[i] << " ";
    }

    return 0;
}
