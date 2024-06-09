#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#define LOCAL
// #include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    char x,o,y;
    unordered_map<char, vector<char>> char_m;
    REP(i,0,2) {
        cin >> x >> o >> y;
        if (o == '>') {
            char_m[y].push_back(x);
        } else {
            char_m[x].push_back(y);
        }
    }
    int cnt = 0;
    char first;
    for(const auto& p : char_m) {
        if (p.second.size() == 1) {
            cnt++;
        }
        if (p.second.size() == 2) {
            first = p.first;
            break;
        }
    }
    if (cnt == 3) {
        cout << "Impossible";
        return 0;
    }
    vector<char> p = char_m[first];
    if (char_m[p[0]].size() == 0) {
        cout << first << p[1] << p[0];
    } else {
        cout << first << p[0] << p[1];
    }
    return 0;
}
