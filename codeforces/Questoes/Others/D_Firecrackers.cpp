#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;

    vector<int> tempos(m);
    for (auto &i : tempos) cin >> i;

    sort(tempos.begin(), tempos.end());
    
    int bombas = abs(a - b) - 1;
    int pegou = (a > b ? n - b : b - 1);

    auto ok = [&](int mid) -> bool {
        int time = 0;
        for (int i = mid; i >= 0; i--){
            int v = time + tempos[i];
            if (v >= pegou) return false;
            time++;
        }
        return (mid + 1 <= bombas);
    };

    int l = -1, r = m-1; 
    while (l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)) l = mid;
        else r = mid - 1;
    }

    if (l == -1) cout << 0 << "\n";
    else cout << l + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}