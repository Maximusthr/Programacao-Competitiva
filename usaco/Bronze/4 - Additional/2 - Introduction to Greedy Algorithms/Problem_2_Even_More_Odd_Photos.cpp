#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    int even = 0, odd = 0;
    
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x%2) odd++;
        else even++;
    }
    
    int ans = 0;
    bool par = true;
    while (even > 0 && odd > 0){
        if (even > 0 && par){
            ans++;
            par = false;
            even--;
        }
        else if (odd > 0 && !par){
            ans++;
            par = true;
            odd--;
        }
    }
    if (par && odd == 0 && par > 0) ans++; 
    
    while(odd > 0){
        if (par && odd >= 2){
            ans++;
            odd -= 2;
            par = false;
        }
        else if (!par && odd != 2){
            ans++;
            odd--;
            par = true;
        }
        if (par && odd == 1 || !par && odd == 2) break;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}
