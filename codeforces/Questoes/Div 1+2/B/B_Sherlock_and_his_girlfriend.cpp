#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

void solve(){
    vector<int> crivo(MAX, true);
    
    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }
    
    int n; cin >> n;

    vector<int> ans;
    bool tem_1 = 0, tem_2 = 0;
    for (int i = 2; i <= n+1; i++){
        if (crivo[i]) {
            ans.push_back(1);
            tem_1 = 1;
        }
        else {
            ans.push_back(2);
            tem_2 = 2;
        }
    }

    if (tem_1 && tem_2) cout << 2 << "\n";
    else cout << 1 << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}