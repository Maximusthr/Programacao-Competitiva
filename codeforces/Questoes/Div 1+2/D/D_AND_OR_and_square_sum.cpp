#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<ll> ());

    vector<vector<ll>> bits(n, vector<ll> (21));
    vector<int> bits_aux(21);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 21; j++){
            if (arr[i] & (1 << j)){
                bits[i][j]++;
                bits_aux[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 21; j++){
            if (bits[i][j]){
                if (bits_aux[j] <= 0){
                    bits[i][j] = 0;
                }
                else bits_aux[j]--;
            }
            else {
                if (bits_aux[j] > 0){
                    bits[i][j] |= 1;
                    bits_aux[j]--;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll v = 0;
        for (int j = 0; j < 21; j++){
            if (bits[i][j]){
                v += (1ll << j);
            }
        }

        ans += (v * v);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}