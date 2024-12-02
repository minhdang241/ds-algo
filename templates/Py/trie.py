class TrieNode:
  def __init__(self):
    self.is_word = False
    self.children = dict()


class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word):
    cur = self.root
    for c in word:
      if c in cur.children:
        cur = cur.children[c]
      else:
        new_node = TrieNode()
        cur.children[c] = new_node
        cur = new_node
    cur.is_word = True

  def search(self, word) -> bool:
    cur = self.root
    for c in word:
      if c not in cur.children:
        return False
      else:
        cur = cur.children[c]
    return cur.is_word

  def startsWith(self, prefix) -> bool:
    cur = self.root
    for c in prefix:
      if c not in cur.children:
        return False
      else:
        cur = cur.children[c]
    return True
