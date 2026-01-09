#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;
vector<int> crivo;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    map<int, int> divs;

    for (int i = 0; i < n; i++){
        while (arr[i] > 1){
            int v = crivo[arr[i]];
            divs[v]++;

            arr[i] /= v;
        }
    }

    for (auto [x, y] : divs){
        if (y % n != 0){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    crivo.resize(MAX);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}