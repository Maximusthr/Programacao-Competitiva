#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = stoi(s);

    if (n <= 9){
        cout << n << "\n";
        return;
    }

    int ans = (s.size()-1) * 9;

    for (int i = 1; i <= 9; i++) {
            string atual = "";
            
            for (int j = 0; j < s.size(); j++) {
                atual += '0' + i;
            }
 
            if (atual > s) break;
            else ans++;
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