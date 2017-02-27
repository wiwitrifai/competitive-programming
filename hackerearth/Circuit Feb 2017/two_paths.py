#!/bin/python3


class Dsu:
    def __init__(self, n):
        self.n = n
        self.p = [-1] * n
    def find(self, x):
        if self.p[x] < 0:
            return x;
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    def merge(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return False
        if self.p[u] < self.p[v]:
            u, v = v, u
        self.p[v] += self.p[u]
        self.p[u] = v
        return True

class Graph():
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in range(n)]
        self.counter = 0
        self.low = [-1] * n
        self.num = [-1] * n
        self.node = []
        self.comp = [-1] * n
        self.ncomp = 0

    def add(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def scc(self, v, bef = -1):
        self.node.append(v)
        self.low[v] = self.num[v] = self.counter
        self.counter += 1
        for u in self.adj[v]:
            if self.num[u] == -1:
                self.scc(u, v)
            if u != bef and self.low[v] > self.low[u]:
                self.low[v] = self.low[u]
        if self.low[v] == self.num[v]:
            while True:
                u = self.node.pop()
                self.comp[u] = self.ncomp;
                if u == v:
                    break
            self.ncomp += 1

class Tree:
    def __init__(self, n):
        self.n = n
        self.adj = [[] for i in range(n)]
        self.counter = 0
        self.le = [-1] * n
        self.ri = [-1] * n

    def add(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)
    
    def dfs(self, v, par = -1):
        # print(v, end=', ')
        self.le[v] = self.counter
        self.counter += 1
        for u in self.adj[v]:
            if u == par or self.le[u] != -1: continue
            self.dfs(u, v)
        self.ri[v] = self.counter
        # print(v, end=', ')
        self.counter += 1

    def ancestor(self, u, v):
        return self.le[u] <= self.le[v] and self.ri[v] <= self.ri[u]
    def path(self, a, b, c):
        if self.ancestor(a, c):
            return self.ancestor(a, b) and self.ancestor(b, c)
        elif self.ancestor(c, a):
            return self.ancestor(c, b) and self.ancestor(b, a)
        else:
            return ancestor(b, a) != ancestor(b, c)

def main():
    n, m, q = map(int, input().strip().split())
    edge = [tuple(map(lambda x: int(x)-1, input().strip().split())) for _ in range(m)]
    dsu = Dsu(n)
    for e in edge:
        if e[2] == 0:
            dsu.merge(e[0], e[1])
    
    # convert component conected by white-edge to one vertex
    white = [-1] * n
    ng = 0
    for i in range(n):
        if dsu.find(i) == i:
            white[i] = ng
            ng += 1
    for i in range(n):
        white[i] = white[dsu.find(i)]

    # convert black-edge graph to tree based scc
    g = Graph(ng)
    for e in edge:
        if e[2] == -1:
            u, v = white[e[0]], white[e[1]]
            if u == v: continue
            g.add(u, v)
    for i in range(ng):
        if g.comp[i] == -1:
            g.scc(i)

    tree = Tree(g.ncomp)
    for v in range(ng):
        for u in g.adj[v]:
            if g.comp[u] < g.comp[v]:
                 tree.add(g.comp[u], g.comp[v])

    for i in range(tree.n):
        if tree.le[i] == -1:
            tree.dfs(i)
    for _ in range(q):
        a = list(map(lambda x : int(x)-1, input().strip().split()))

        # print('q : ', a[0], a[1], a[2], a[3])
        for i in range(4):
             a[i] = white[a[i]]

        # print('w : ', a[0], a[1], a[2], a[3])
        if a[2] == a[3]:
            print('No')
        elif a[1] == a[0]:
            print('Yes')
        else:
            if a[1] == a[2] and a[0] == a[3]:
                print('No')
                continue
            if a[0] == a[2] and a[1] == a[3]:
                print('No')
                continue
            # print('g : ', a[0], a[1], a[2], a[3])
            for i in range(4):
                a[i] = g.comp[a[i]]
            if a[0] == a[1]:
                print('Yes')
                continue
            # print('t : ', a[0], a[1], a[2], a[3])
            # print(tree.path(a[0], a[2], a[1]), tree.path(a[0], a[3], a[1]))
            if tree.path(a[0], a[2], a[1]) and tree.path(a[0], a[3], a[1]):
                print('No')
            else:
                print('Yes')

if __name__ == "__main__":
    main()