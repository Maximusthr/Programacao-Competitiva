#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    string s2 = s;
    sort(s2.begin(), s2.end());

    if (s == s2){
        cout << "Bob" << "\n";
        return;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (s[i] != s2[i]){
            ans.push_back(i+1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Alice" << "\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}