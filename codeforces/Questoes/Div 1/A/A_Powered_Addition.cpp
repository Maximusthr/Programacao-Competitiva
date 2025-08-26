#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    
    for (auto &i : arr) cin >> i;

    int maior = arr[0];
    int tempo = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < maior){
            tempo = max(tempo, maior-arr[i]);
        }
        maior = max(arr[i], maior);
    }

    if (tempo == 0) cout << 0 << "\n";
    else cout << 32 - __builtin_clz(tempo) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}