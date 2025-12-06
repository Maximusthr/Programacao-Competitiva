#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int ans = 0;
    bool active = false;
    int aux = 0;
    for (int i = 0; i < n; i++){
        while(active){
            aux++;
            if (s[i] == '1'){
                aux = 0;
                i++;
                continue;
            }
            i++;
            if (aux == k){
                active = false;
                break;
            }
        }
        if (aux == k){
            aux = 0;
            i--;
            continue;
        }
        if (s[i] == '1'){
            active = true;
        }
        else ans++;
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