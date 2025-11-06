#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    map<char, queue<int>> mapa;
    vector<bool> original(n);

    for (int i = 0; i < n; i++){
        mapa[s[i]].push(i);
        if (s[i] == '1') original[i] = true;
    }

    string copy = s;

    for (int i = 0; i < n; i++){
        if (copy[i] == '0' && copy[i] == s[i]){
            if (mapa['1'].size() == 0) break;

            swap(copy[i], copy[mapa['1'].front()]);
            mapa['0'].pop();
            mapa['1'].pop();
        }
        else if (copy[i] == s[i]) {
            if (mapa['0'].size() == 0) break;

            swap(copy[i], copy[mapa['0'].front()]);
            mapa['0'].pop();
            mapa['1'].pop();
        }
    }

    int ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (copy[i-pos] == s[i-pos]){
            ans++;
            pos++;
        }
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