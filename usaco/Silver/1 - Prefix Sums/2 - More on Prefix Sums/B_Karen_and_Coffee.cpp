#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k, q; cin >> n >> k >> q;

    vector<pair<int, int>> rec(n);
    for (auto &[x, y] : rec) cin >> x >> y;

    vector<int> dif(MAX);
    for (int i = 0; i < n; i++){
        dif[rec[i].first]++;
        dif[rec[i].second + 1]--;
    }

    for (int i = 1; i < MAX; i++){
        dif[i] += dif[i-1];
    }

    vector<int> prefix(MAX);
    for (int i = 1; i < MAX; i++){
        prefix[i] += prefix[i-1];
        if (dif[i] >= k) prefix[i]++;
    }

    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;

        cout << prefix[r] - prefix[l-1] << "\n";
    }
}