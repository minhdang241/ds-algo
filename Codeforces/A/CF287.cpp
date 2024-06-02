#include <bits/stdc++.h>
#define LOCAL
//#include "../debug.cpp"
#define REP(i,a,b)for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    string s;
    REP(i,0,3) {
        cin >> s;
        v.push_back(s);
    }
    vector<pair<int,int>> dx{{0,0},{0,1},{1,0},{1,1}};
    REP(i,0,3) {
        REP(j,0,3) {
            int ni,nj;
            int black = 0, white = 0;
            for (const auto&p : dx) {
                ni = i + p.first;
                nj = j + p.second;
                if ((ni <= 3) && (nj <= 3)) {
                    if (v[ni][nj] == '#') black++;
                    else white++;
                }
            }
            if ((black == 4) || (white == 4) || (black == 3 && white == 1) || (black == 1 && white == 3)) {
                cout << "YES";
                return 0;
            }

        }
    }

    cout << "NO";
    return 0;
}
