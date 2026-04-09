#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    vector<int> b(m);
    map<int, int> freq;
    for (auto &i : b){
        cin >> i;
        freq[i]++;
    } 

    map<int, int> mapa;

    int count = 0;
    int ans = 0;
    int qtd = 0;

    for (int i = 0, j = 0; i < n; i++){
        while (qtd < m && j < n){
            mapa[arr[j]]++;
            if (freq.count(arr[j])){
                if (mapa[arr[j]] <= freq[arr[j]]) count++;
            }
            qtd++;
            j++;
        }
        if (count >= k) ans++;
        if (j == n) break;

        mapa[arr[i]]--;
        if (freq.count(arr[i]) && mapa[arr[i]] < freq[arr[i]]){
            count--;
        }
        qtd--;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}