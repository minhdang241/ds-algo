#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    string name;
    cin >> name;
    unordered_set<char> cs;
    for (const auto&c : name) {
        cs.insert(c);
    }
    if (cs.size() % 2 == 0) cout <<  "CHAT WITH HER!";
    else cout << "IGNORE HIM!";

    return 0;
}
