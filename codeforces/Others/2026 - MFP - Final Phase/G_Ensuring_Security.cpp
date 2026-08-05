#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, r, k; cin >> n >> r >> k;

    if (k == 0){
        cout << n << "\n";
        return;
    }

    k *= 2 + 1;

    vector<int> pos(r);
    set<int> tem;
    for (int i = 0; i < r; i++){
        cin >> pos[i];
        tem.insert(pos[i]);
    }

    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        sum++;
        if (tem.count(i) || i == n){
            ans += (sum + k - 1)/k;
            sum = 0;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}