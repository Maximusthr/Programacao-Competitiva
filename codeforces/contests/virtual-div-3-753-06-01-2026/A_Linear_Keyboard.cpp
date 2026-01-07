#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    string word; cin >> word;

    vector<int> pos(26);
    for (int i = 0; i < s.size(); i++){
        pos[s[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 1; i < word.size(); i++){
        ans += abs(pos[word[i]-'a'] - pos[word[i-1]-'a']);
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