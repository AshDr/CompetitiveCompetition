struct SCC {
  vector<vector<int> > g, scc;
  // scc 是拓扑逆序，拓扑从后跑
  vector<int> dfn, low, stk, id;
  vector<bool> ins;
  int ts, n;

  SCC(const vector<vector<int> > &g) : g(g) {
    n = (int)g.size();
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    id.assign(n + 1, -1);
    ins.assign(n + 1, false);
    stk.reserve(n);
    ts = 0;
    build();
  }

  void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    stk.push_back(u);
    ins[u] = 1;
    for (auto j : g[u]) {
      if (!dfn[j]) {
        tarjan(j);
        low[u] = min(low[u], low[j]);
      } else if (ins[j])
        low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u]) {
      int scc_cnt = scc.size();
      scc.push_back({});
      int y;
      do {
        y = stk.back();
        stk.pop_back();
        id[y] = scc_cnt;
        ins[y] = 0;
        scc.back().push_back(y);
      } while (y != u);
    }
  }

  void build() {
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) {
        tarjan(i);
      }
    }
  }
};