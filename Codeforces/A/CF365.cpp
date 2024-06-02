#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    int ans = 0;
    REP(i,1,n) {
        cin >> s;
        auto iss = istringstream(s);
        char c;
        set<int> st;
        vector<int> v;
        while (iss >> c) {
            st.insert(c - '0');
        }
        copy(st.begin(), st.end(), back_inserter(v));
        //for (const auto& val : v) {
        //    cout << val << " ";
        //}
        //cout << endl;

        sort(v.begin(), v.end());
        bool do_have = true;
        REP(j,0,k) {
            if (v[j] != j) {
                do_have = false;
                break;
            }
        }
        if (do_have) ans += 1;
    }
    cout << ans;

    return 0;
}
