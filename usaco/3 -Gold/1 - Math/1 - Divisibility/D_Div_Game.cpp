#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e7 + 5;

vector<int> crivo;
vector<bool> pode;

void solve(){
    ll n; cin >> n;
    
    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    set<ll> fatores;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0) {
            fatores.insert(i);
            if (n/i > MAX) continue;
            fatores.insert(n/i);
        }
    }

    if (fatores.size() == 0){
        cout << 1 << "\n";
        return;
    }

    int ans = 0;
    vector<ll> fat = {fatores.begin(), fatores.end()};

    vector<bool> foi(MAX);

    for (int i = 0; i < fat.size(); i++){
        if (!pode[fat[i]]) continue;
        
        if (n < fat[i]) break;
        
        if (n % fat[i] == 0){
            foi[fat[i]] = 1;
            n /= fat[i];
            ans++;
        }
    }

    bool ok = false;
    if (n == 1 || (n < MAX && foi[n])) ok = true;
    else {
        for (ll i = 2; i * i <= n; i++){
            if (n % i == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) ans++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);
    pode.resize(MAX, 1);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i + i; j < MAX; j += i){
                if (crivo[j] != 0) {
                    pode[j] = false;
                }
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    solve();
}