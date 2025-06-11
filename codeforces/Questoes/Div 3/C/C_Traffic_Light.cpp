#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    char c; cin >> c;

    string s; cin >> s;

    if (c == 'g'){
        cout << 0 << "\n";
        return;
    }
    int ans = 0;

    int longest = 0;
    bool achou = false;
    for (int i = 0; i < n*2; i++){
        if (s[i % n] == c && !achou){
            achou = true;
            longest++;
            continue;
        }
        if (s[i % n] == 'g' && achou){
            achou = false;
            ans = max(ans, longest);
            longest = 0;
        }
        if (achou) longest++;
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