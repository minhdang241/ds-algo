#include <bits/stdc++.h>
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
    int n,m;
    cin >> n >> m;
    int a, b;
    vii v;
    REP(i,0,m-1) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [] (const ii p1, const ii p2) {
        return p1.second > p2.second;
    });
    ll ans  = 0;
    int i = 0;
    while (n > 0) {
        int number_of_packs = min(n, v[i].first);
        v[i].first -= number_of_packs;
        n -= number_of_packs;
        ans += number_of_packs * v[i].second;
        if (i < v.size() && v[i].first == 0) i++;
        if (i >= v.size()) break;
    }
    cout << ans;
    return 0;
}
