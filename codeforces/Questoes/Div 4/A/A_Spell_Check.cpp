#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    
    int n; cin >> n;

    string s; cin >> s;
    //Timur

    map<char, int> vis;

    for (int i = 0; i < n; i++){
        vis[s[i]]++;
    }

    if (n == 5 && vis['T'] == 1 && vis['i'] == 1 && vis['m'] == 1 && vis['u'] == 1 && vis['r'] == 1) {
        cout << "YES" << "\n";
        return;
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