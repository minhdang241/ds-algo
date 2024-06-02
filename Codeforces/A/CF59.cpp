#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
void lower(string& s) {
    REP(i,0,s.size()) {
        s[i] = tolower(s[i]);
    }
}
void upper(string& s) {
    REP(i,0,s.size()) {
        s[i] = toupper(s[i]);
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int l = 0, u = 0;
    cin >> s;
    for (const auto& c: s) {
        if (c <= 122 && c >= 97) ++l;
        else ++u;
    }
    if (l >= u) lower(s);
    else upper(s);
    cout << s;


    return 0;
}
