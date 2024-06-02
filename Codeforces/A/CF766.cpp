#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() > s2.size()) {
        cout << s1.size();
    } else if (s1.size() < s2.size()) {
        cout << s2.size();
    } else {
        if (s1 == s2) cout << -1;
        else cout << s1.size();
    }

    return 0;
}
