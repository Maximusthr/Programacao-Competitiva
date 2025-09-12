#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    string aux = "FBFFBFFBFBFFBFFBFBFFBFFBFB";
    
    for (int i = 0; i <= aux.size()-n; i++){
        string temp = aux.substr(i, n);
        if (s == temp){
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