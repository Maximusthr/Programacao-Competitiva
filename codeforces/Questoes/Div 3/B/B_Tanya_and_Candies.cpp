#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n+1); 
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    // quando entrega um doce
    // todos os outros doces sao deslocados
    // uma casa (ou seja, par vira impar e impar vira par)
    
    vector<int> pref_even(n+1), pref_odd(n+1);
    for (int i = 1; i <= n; i++){
        if (i % 2){
            pref_odd[i] = pref_odd[i-1] + arr[i];
            pref_even[i] = pref_even[i-1];
        }
        else {
            pref_even[i] = pref_even[i-1] + arr[i];
            pref_odd[i] = pref_odd[i-1];
        }
    }

    vector<int> suffix_even(n+2), suffix_odd(n+2);
    for (int i = n; i > 0; i--){
        if (i % 2 == 0){
            suffix_even[i] = suffix_even[i+1] + arr[i];
            suffix_odd[i] = suffix_odd[i+1];
        }
        else {
            suffix_odd[i] = suffix_odd[i+1] + arr[i];
            suffix_even[i] = suffix_even[i+1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int v = pref_even[i] + suffix_odd[i];
        int v2 = pref_odd[i] + suffix_even[i];
        
        if (v - arr[i] == v2 - arr[i]) ans++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}