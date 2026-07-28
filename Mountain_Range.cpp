#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;

struct SegTree {
    vector<pair<int, int>> seg;
    int n;

    SegTree(int n) : n(n) {
        seg.resize(4 * n);
    }

    void build(const vector<int>& arr, int p, int l, int r) {
        if (l == r) {
            seg[p] = {arr[l], l};
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * p, l, mid);
        build(arr, 2 * p + 1, mid + 1, r);
        
        // Mantém o índice mais à esquerda em caso de empate (por padrão)
        if (seg[2 * p].first >= seg[2 * p + 1].first) {
            seg[p] = seg[2 * p];
        } else {
            seg[p] = seg[2 * p + 1];
        }
    }

    pair<int, int> query(int a, int b, int p, int l, int r) {
        if (a > r || b < l) return {-1, -1};
        if (l >= a && b >= r) return seg[p];

        int mid = (l + r) / 2;
        pair<int, int> esq = query(a, b, 2 * p, l, mid);
        pair<int, int> dir = query(a, b, 2 * p + 1, mid + 1, r);

        if (esq.first >= dir.first) return esq;
        return dir;
    }
};

int solve_cartesian(int l, int r, SegTree& seg, int n) {
    if (l > r) return 0;
    if (l == r) return 1;

    // 1. Encontra qual é o valor máximo absoluto e o seu primeiro índice
    pair<int, int> max_mnt = seg.query(l, r, 1, 0, n - 1);
    int max_val = max_mnt.first;

    // 2. Coleta TODOS os índices que possuem esse mesmo valor máximo
    vector<int> max_indices;
    int curr_l = l;
    while (curr_l <= r) {
        pair<int, int> curr = seg.query(curr_l, r, 1, 0, n - 1);
        
        // Se o maior valor no restante do intervalo for menor, acabaram os empates
        if (curr.first != max_val) break; 
        
        max_indices.push_back(curr.second);
        curr_l = curr.second + 1; // Prepara para buscar o próximo à direita
    }

    // 3. Divide o array nos vales (intervalos estritamente menores que max_val)
    int max_profundidade_vales = 0;
    
    // Processa o vale ANTES do primeiro máximo
    max_profundidade_vales = max(max_profundidade_vales, solve_cartesian(l, max_indices[0] - 1, seg, n));
    
    // Processa os vales ENTRE os máximos iguais
    for (int i = 0; i < (int)max_indices.size() - 1; i++) {
        max_profundidade_vales = max(max_profundidade_vales, 
                                     solve_cartesian(max_indices[i] + 1, max_indices[i+1] - 1, seg, n));
    }
    
    // Processa o vale DEPOIS do último máximo
    max_profundidade_vales = max(max_profundidade_vales, solve_cartesian(max_indices.back() + 1, r, seg, n));

    // A resposta é a montanha atual (1) + a rota mais longa encontrada nos vales
    return 1 + max_profundidade_vales;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    SegTree seg(n);
    seg.build(h, 1, 0, n - 1);

    cout << solve_cartesian(0, n - 1, seg, n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    solve();
    return 0;
}