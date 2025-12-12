#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    int tem = 0;
    map<char, int> freq;
    for (int i = 0; i < n; i++){
        freq[s[i]]++;
        if (freq[s[i]] == 1) tem++;
    }

    vector<char> ans;
    
    while (tem){
        for (auto &[x, y] : freq){
            if (y > 0){
                ans.push_back(x);
                y--;
                if (y == 0) tem--;
            }
        }
    }

    for (auto i : ans) cout << i;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}