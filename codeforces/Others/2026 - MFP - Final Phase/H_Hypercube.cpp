#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> pos(n);
    for (auto &i : pos) cin >> i;

    vector<int> queries(q);
    for (auto &i : queries) cin >> i;

    for (int i = 0; i < q; i++){
        int x = queries[i];

        if (x > pos.back()){
            cout << x - pos[n - 2] << "\n";
            continue;
        }
        else if (x < pos[0]){
            cout << pos[1] - x << "\n";
            continue;
        }

        auto v = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
        int b = pos[v] - pos[v-1];

        if (v+1 < n){
            b = min(b, pos[v+1] - x);
        }
        if (v-2 >= 0){
            b = min(b, x - pos[v-2]);
        }


        cout << b << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}