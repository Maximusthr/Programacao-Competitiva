#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    map<char, int> mapa;

    for (int i = 0; i < n; i++){
        mapa[s[i]]++;
    }

    string ans;

    // hahahaha
    
    for (auto [x, y] : mapa){
        while (y > 0){
            ans.push_back(x);
            y--;
        }
    }

    cout << ans << "\n";
}

int main(){
    solve();
}