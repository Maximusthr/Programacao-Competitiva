#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    if (n%2){
        cout << "NO" << "\n";
        return;
    }

    string ans;
    for (int i = 0; i < n; i++){
        if (s[i] == s[i+1]){
            i++;
            continue;
        }
        else {
            if (s[i] == ans.back()){
                ans.pop_back();
            }
            else ans.push_back(s[i]);
        }
    }

    if (ans.size() > 0) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}