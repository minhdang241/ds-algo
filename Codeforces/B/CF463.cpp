#include <bits/stdc++.h>
#define LOCAL
//#include "../debug.cpp"
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
    int n;
    cin >> n;
    int ch = 0;
    int en = 0;
    int nh;
    int c = 0;
    REP(i,0,n-1) {
        cin >> nh;
        int diff = ch-nh;
        en += diff;
        if (en >= 0) {
            ch = nh;
            continue;
        } else {
            c += -en;
            en = 0;
        }
        ch = nh;
    }
    cout << c;

    return 0;
}
