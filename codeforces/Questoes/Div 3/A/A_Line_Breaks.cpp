#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int w, m; cin >> w >> m;

    vector<string> words(w);

    for (int i = 0; i < w; i++){
        cin >> words[i];
    }

    int ans = 0;
    for (int i = 0; i < w; i++){
        m -= words[i].size();
        if (m >= 0) ans++;
        else {
            break;
        }
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