#include "bits/stdc++.h"
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
template <typename A, typename B> 
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

string to_string(unordered_set<char> v) {
  bool first = true;
  string res = "{";
  for (const auto& c: v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(string(1, c));
  }
  res += "}";
  return res;
}

template <size_t N> string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}


template <typename A> 
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    if constexpr (std::is_same_v<typename A::value_type, char>) {
      res += string(1, x);
    } else {
      res += to_string(x);
    }
  }
  res += "}";
  return res;
}

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail> 
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define REP(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
struct segtree {
  int size;
  vi tree;

  segtree(int n) {
    tree.assign(4 * n, 0);
  }

  void build(vi& nums, int i, int start, int end) {
    if (start == end) {
      tree[i] = nums[start];
    } else {
      int mid = (start + end) / 2;
      build(nums, i * 2, start, mid);
      build(nums, i * 2 + 1, mid + 1, end);
      tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
  }

  int query(int i, int start, int end, int l, int r) {
    if (l <= start && r >= end) {
      return tree[i];
    } else if (r < start || l > end) {
      return 0;
    } else {
      int mid = (start + end) / 2;
      return query(i * 2, start, mid, l, min(mid, r)) + query(i * 2 + 1, mid + 1, end, max(l, mid+1), r);
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> v;
  REP(i, 1, n) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  auto tree = segtree(n);
  tree.build(v, 1, 0, n-1);

  REP(i, 1, q) {
    int l, r;
    cin >> l >> r;
    cout << tree.query(1, 0, n-1, l, r) << endl;
  }
  return 0;

}











