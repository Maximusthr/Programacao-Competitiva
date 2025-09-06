#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    bool b = false;
    
    if (s[0] == 'B' || s[n-1] == 'B') b = true;
    for (int i = 1; i < n-1; i++){
        if (s[i] == s[i+1] && s[i] == 'B') b = true;
    }

    int aux = 0;
    vector<int> groups;
    for (int i = 0; i < n; i++){
        if (s[i] == 'A') aux++;
        else {
            if (aux > 0) groups.push_back(aux);
            aux = 0;
        }
    }
    if (aux > 0) groups.push_back(aux);

    if (!groups.size()){
        cout << 0 << "\n";
        return;
    }

    sort(groups.begin(), groups.end());
    
    int ans = 0;

    // tudo
    if (b) ans += groups[0];
    for (int i = 1; i < groups.size(); i++){
        ans += groups[i];
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