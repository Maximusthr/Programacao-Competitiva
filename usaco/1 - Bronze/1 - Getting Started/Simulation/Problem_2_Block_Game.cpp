#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<string, string>> s;
    for (int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        s.push_back({a, b});
    }
        
    map<char, int> rep; // a b .. z
    string alf = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++){
        rep[alf[i]] = 0;
    }
    
    for (int i = 0; i < n; i++){
        map<char, int> w1;
        map<char, int> w2;
        for (int j = 0; j < s[i].first.size(); j++) w1[s[i].first[j]]++;
        for (int j = 0; j < s[i].second.size(); j++) w2[s[i].second[j]]++;

        map<char, int> w3;
        for (auto [x, y] : w1) w3[x] = y;
        for (auto [x, y] : w2) w3[x] = max(w3[x], y);

        for (auto [x, y] : w3) rep[x] += y;
    }

    for (auto [x, y] : rep){
        cout << y << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    solve();
}