#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    int aux = 0;
    vector<int> grupos;
    for (int i = 0; i < n; i++){
        if (s[i] == 'A') aux++;
        else {
            grupos.push_back(aux);
            aux = 0;
        }
    }
    grupos.push_back(aux);

    int ans = accumulate(grupos.begin(), grupos.end(), 0);
    ans -= *min_element(grupos.begin(), grupos.end());
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}