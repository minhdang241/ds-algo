#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#define LOCAL
//#include "../debug.cpp"
#define REP(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
/**
A troop of Etruscan warriors is organized as follows. In the first row, there is only one warrior; then,
the second row contains two warriors; the third row contains three warriors, and so on. In general, each
row i contains i warriors.
We know the number of Etruscan warriors of a given troop. You have to compute the number of
rows in which they are organized.
Please note that there may be some remaining warriors (this could happen if they are not enough
to form the next row). For example, 3 warriors are organized in 2 rows. With 6 warriors you can form
3 rows; but you can also form 3 rows with 7, 8 or 9 warriors.
*/

ll solve(ll n) {
    // n**2 + n - 2s = 0
    // delta = b**2 - 4ac
    ll d = 1 - 4 * 1 * -2 * n;
    double sqrt_d = sqrt(abs(d));
    double v1 = (-1 + sqrt_d) / 2.0;
    double v2 = (-1 - sqrt_d) / 2.0;
    // cout << v1 << " " << v2 << endl;
    return floor(max(v1, v2));
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC;
    cin >> TC;
    ll n;
    REP(i,0,TC-1) {
        cin >> n;
        cout << solve(n) << endl;

    }

    return 0;
}
