#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n+1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[x]++;
    }
    
    vector<int> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    int ans = 1;
    for (int i = 2; i <= n; i++){
        int qtd = n - prefix[min(4*i-1, n)];
        qtd += arr[i];
        if (i*2 <= n) qtd += arr[i*2];
        if (i*3 <= n) qtd += arr[i*3];
        
        if (qtd >= n-k) ans = i;
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