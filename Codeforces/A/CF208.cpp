#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    auto pos = s.find("WUB");
    while (pos != string::npos) {
        s.replace(pos, 3, " ");
        pos = s.find("WUB");
    }
    auto ss = istringstream(s);
    string w;
    while(ss >> w) {
        cout << w << " ";
    }
    return 0;
}
