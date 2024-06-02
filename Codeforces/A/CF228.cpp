#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_set<int> s;
    int x;
    REP(i,0,3) {
        cin >> x;
        s.insert(x);
    }
    cout << (4 - s.size());


    return 0;
}
