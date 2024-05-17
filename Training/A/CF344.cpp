#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> m;
    string s;
    int r = 0;
    char prev = -1;

    REP(i, 1, n) {
        cin >> s;
        if (prev == -1) {
            prev = s.back();
            ++r;
        } else {
            if (s.front() != prev) {
                prev = s.back();
            } else {
                ++r;
                prev = s.back();
            }
        }
    }
    cout << r;

    return 0;
}
