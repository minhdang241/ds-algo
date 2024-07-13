class SegmentTree:
    def __init__(self, arr):
        n = len(arr)
        self.nodes = [0 for _ in range(4*n)]
        self._build(0, arr, 0, len(arr)-1)
        self.arr = arr

    def _build(self, node, arr, start, end):
        if start == end:
            self.nodes[node] = arr[start]
        else:
            mid = (start + end) // 2
            self._build(2*node+1, arr, start, mid)
            self._build(2*node+2, arr, mid+1, end)
            self.nodes[node] = self.nodes[2*node+1] + self.nodes[2*node+2]

    def query(self, node, start, end, l,r):
        if r < start or l > end:
            return 0
        if l <= start and end <= r:
            return self.nodes[node]
        mid = (start+end) // 2 
        return self.query(2*node+1, start, mid, l, r) + self.query(2*node+2, mid+1, end, l, r)
    
    def update(self, idx, node, start, end, new_val):
        if start == end:
            self.arr[idx] = new_val
            self.nodes[node] = new_val
        else:
            mid = (start+end) // 2
            if start <= idx <= mid:
                self.update(idx, 2*node+1, start, mid, new_val)
            else:
                self.update(idx, 2*node+2, mid+1, end, new_val)
            self.nodes[node] = self.nodes[2*node+1] + self.nodes[2*node+2]
