int n;

vector<int> start(n), end(n);    

int time = 0;
auto dfs = [&](auto &&self, int u, int p) -> void {
    start[u] = time++;
    for (auto v : g[u]){
        if (v == p) continue;
        self(self, v, u);
    }
    end[u] = time;
};

dfs(dfs, 0, -1);