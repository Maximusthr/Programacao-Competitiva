#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    pair<int, int> ans = {0, 0};
    
    for (int i = 0; i < n; i++){
        if (s[i] == 'U') ans.second++;
        if (s[i] == 'D') ans.second--;
        if (s[i] == 'R') ans.first++;
        if (s[i] == 'L') ans.first--;

        if (ans.first == 1 && ans.second == 1){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}