#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 70;

void solve(){
    ll n; cin >> n;

    vector<vector<int>> bin(MAX, vector<int> (64));

    set<int> pos;

    for (int i = 62; i >= 0; i--){
        if (n & (1ll << i)){
            bin[0][i] = 1;
        }
        else pos.insert(i);
    }

    int foi = -1;
    for (int i = 1; i < MAX; i++){
        bool usou = false;
        for (int j = 0; j <= 62; j++){
            if (pos.count(j)) continue;
            if (!usou && foi < j){
                bin[i][j] = 0;
                usou = true;
                foi = j;
            }
            else bin[i][j] = bin[0][j];
        }
    }

    vector<ll> ans;
    for (int i = 0; i < MAX; i++){
        ll aux = 0;
        for (int j = 62; j >= 0; j--){
            if (bin[i][j] == 1){
                aux += (1ll << j);
            }
        }
        if (i > 0 && (aux == ans[0] || aux == 0)) break;
        ans.push_back(aux);
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}