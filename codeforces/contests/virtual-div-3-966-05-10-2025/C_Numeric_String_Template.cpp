#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int m; cin >> m;
    while(m--){
        string s; cin >> s;
        
        if (s.size() != n) {
            cout << "NO" << "\n";
            continue;
        }
        
        bool foi = true;

        map<int, set<char>> arr;
        map<char, set<int>> carac;
        for (int i = 0; i < s.size(); i++){
            carac[s[i]].insert(v[i]);

            if (carac[s[i]].size() != 1){
                foi = false;
                break;
            }

            arr[v[i]].insert(s[i]);
            if (arr[v[i]].size() > 1){
                foi = false;
                break;
            }
        }

        if (foi) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}