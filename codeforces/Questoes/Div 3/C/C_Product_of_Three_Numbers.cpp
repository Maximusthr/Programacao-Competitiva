#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    set<int> fatores;

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            fatores.insert(i);
            fatores.insert(n/i);
        }
    }

    if (fatores.size() < 3){
        cout << "NO" << "\n";
        return;
    }

    vector<int> fat = {fatores.begin(), fatores.end()};

    array<ll, 3> ans;
    ans[0] = fat[0];
    ans[1] = -1;

    for (int i = 1; i < fat.size(); i++){
        if (n % (1ll * ans[0] * fat[i]) == 0){
            ans[1] = fat[i];
            break;
        }
    }

    ans[2] = -1;

    ll maybe = ans[0] * ans[1];
    for (int i = 2; i < fat.size(); i++){
        ll talvez = maybe * fat[i];

        if (talvez == n){
            ans[2] = fat[i];
            break;
        }
        else if (talvez > n){
            break;
        }
    }

    if (ans[2] == -1){
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}