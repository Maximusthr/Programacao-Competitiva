#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    n *= 2;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < m; i++){
        set<string> gen;
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                
            }
        }

        ans += (int)gen.size();
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}