#include "bits/stdc++.h"
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
template <typename A, typename B> string to_string(pair<A, B> p);

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
  for (const auto &c : v) {
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

template <typename A> string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
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

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define REP(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class Solution {
private:
  int R, C;
  int ans{INT_MAX};

public:
  void flip(vector<vector<int>> &mat, int i, int j) {
    vector<vector<int>> vs{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto &v : vs) {
      int new_i = i + v[0];
      int new_j = j + v[1];
      if (new_i < R && new_i >= 0 && new_j < C && new_j >= 0) {
        mat[new_i][new_j] ^= 1;
      }
    }
  }
  bool check_mat(vector<vector<int>> &mat) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (mat[i][j] == 1)
          return false;
      }
    }
    return true;
  }
  void backtrack(set<tuple<int, int>> visit, vector<vector<int>> mat, int cnt) {
    if (visit.size() == 9) return;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        auto p = make_tuple(i, j);
        if (!visit.count(p)) {
          flip(mat, i, j);
          visit.insert(p);
          bool res = check_mat(mat);
          if (res) {
            ans = min(ans, cnt + 1);
            return;
          }
          backtrack(visit, mat, cnt + 1);
          flip(mat, i, j);
          visit.erase(p);
        }
      }
    }
  }
  int minFlips(vector<vector<int>> &mat) {
    R = mat.size();
    C = mat[0].size();
    int n_one{0};
    int res = check_mat(mat);
    if (res) {
      return 0;
    }
    set<tuple<int, int>> visit;
    backtrack(visit, mat, 0);
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};

int main() {
  auto sol = Solution();
  vector<vector<int>>mat{{ 1, 1, 1 }, { 1, 0, 1 }, { 0, 0, 0 }};
  sol.minFlips(mat);
  return 0;
}