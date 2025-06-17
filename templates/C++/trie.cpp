#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  std::unordered_map<char, TrieNode *> children{};
  bool is_word = false;
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    auto p = root;
    for (const auto &c : word) {
      if (p->children.count(c) == 0)
        p->children[c] = new TrieNode();
      p = p->children[c];
    }
    p->is_word = true;
  }

  bool search(string word) {
    auto p = root;
    for (const auto &c : word) {
      if (p->children.count(c) == 0)
        return false;
      p = p->children[c];
    }
    return p->is_word;
  }

  bool startsWith(string prefix) {
    auto p = root;
    for (const auto &c : prefix) {
      if (p->children.count(c) == 0)
        return false;
      p = p->children[c];
    }
    return true;
  }
};
