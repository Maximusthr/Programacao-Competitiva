#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<int> bit;

    BIT (int _n) : n(_n), bit(n+1) {}

    void update(int i, int v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    int sum(int i){
        int ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

void solve(){
    int k, q; cin >> k >> q;

    vector<int> todos;
    todos.push_back(k);

    vector<pair<int, int>> queries(q);
    for (int i = 0;  i < q; i++){
        cin >> queries[i].first >> queries[i].second;
        todos.push_back(queries[i].first);
        todos.push_back(queries[i].second);
    }

    vector<int> copy = todos;
    sort(copy.begin(), copy.end());
    copy.resize(unique(copy.begin(), copy.end()) - copy.begin());

    auto compress = [&](int x) -> int {
        return lower_bound(copy.begin(), copy.end(), x) - copy.begin();
    };

    map<int, int> valor;
    for (int i = 0; i < todos.size(); i++){
        valor[compress(todos[i])] = todos[i];
    }


    BIT bit(2*q+1);

    bit.update(compress(k), 1);

    int qtd = 1;

    for (int i = 0; i < q; i++){
        int x = compress(queries[i].first);
        int y = compress(queries[i].second);
        qtd += 2;

        bit.update(x, 1);
        bit.update(y, 1);

        int l = 0, r = 2 * q + 1;
        while(l < r){
            int mid = l + (r-l)/2;
            if (bit.query(0, mid) >= (qtd+1)/2) r = mid;
            else l = mid + 1;
        }
        cout << valor[l] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}