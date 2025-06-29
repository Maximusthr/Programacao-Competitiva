#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    map<char, int> letras;
    letras[s[0]]++;
    letras[s[n-1]]++;

    for (int i = 1; i < n-1; i++){
        if (letras[s[i]] > 0){
            cout << "YES" << "\n";
            return;
        }
        else letras[s[i]]++;
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