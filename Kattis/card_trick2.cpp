#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#define LOCAL
// #include "../misc/debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    unordered_map<int, deque<int>> m;

    for (int i=13; i > 0; i--) {
        deque<int> q{i};
        for (int v = i - 1; v > 0; v--) {
            q.push_front(v);
            REP(j,1,v) {
                int fv = q.back();
                q.pop_back();
                q.push_front(fv);
            }
        }
        m[i] = q;
    }
    // debug(m);

    int n;
    REP(i,0,t-1) {
        cin >> n;
        for (const auto& v : m[n]) {
            cout << v << " ";
        }
        cout << endl;
    } 
    return 0;
}
