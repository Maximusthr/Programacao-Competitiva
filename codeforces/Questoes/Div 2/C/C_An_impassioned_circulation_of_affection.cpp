#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q;
    string s;
    cin >> n >> s >> q;

    while(q--){
        int m;
        char c;
        cin >> m >> c;

        int ans = 0;

        int l = 0, r = 0;
        while(l < n && r < n){
            while(r < n){
                if (s[r] != c){
                    if (m > 0){
                        m--;
                        r++;
                    } 
                    else break;
                }
                else r++;
            }
            ans = max(ans, r-l);
            if (s[l++] != c) m++;
        }

        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}