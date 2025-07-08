#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<string>> arr(3, vector<string> (n));
    map<string, int> qtd;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            qtd[arr[i][j]]++;
        }
    }

    vector<int> ans(3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            if (qtd[arr[i][j]] == 3) continue;
            
            if (qtd[arr[i][j]] == 2) ans[i]++;
            else ans[i] += 3;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}