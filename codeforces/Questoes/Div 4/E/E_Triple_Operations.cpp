#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;
vector<int> pre_comp;
vector<int> prefix;

void solve(){
    int l, r; cin >> l >> r;

    cout << prefix[r] + prefix[l] - 2 * prefix[l-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    pre_comp.resize(MAX);
    prefix.resize(MAX);

    for (int i = 1; i < MAX; i++){
        int aux = i;
        while (aux > 0){
            aux /= 3;
            pre_comp[i]++;
        }
        prefix[i] += prefix[i-1] + pre_comp[i];
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}
