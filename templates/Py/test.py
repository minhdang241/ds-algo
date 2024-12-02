class A:
  def __init__(self, d={}):
    self.d = d


if __name__ == "__main__":
  a = A()
  b = A()
  b.d["key"] = "value"
  assert a.d["key"] == "value"
