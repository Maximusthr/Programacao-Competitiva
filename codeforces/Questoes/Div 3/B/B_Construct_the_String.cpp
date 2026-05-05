#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    string ans;
    char c = 'a';
    for (int i = 0; i < b; i++){
        ans.push_back(c);
        c++;
    }

    for (int i = ans.size(); i < n; i++){
        ans.push_back(ans[i % b]);
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