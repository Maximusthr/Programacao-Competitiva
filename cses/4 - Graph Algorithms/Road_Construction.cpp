#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<int> size;

    int m_siz = 1;
    int comp = 0;

    DSU (int n) : p(n), size(n, 1) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    };

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (size[a] > size[b]){
            swap(a, b);
        }
        p[a] = b;
        size[b] += size[a];
        m_siz = max(m_siz, size[b]);
        comp--;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);

        cout << dsu.comp << " " << dsu.m_siz << "\n";
    }
}