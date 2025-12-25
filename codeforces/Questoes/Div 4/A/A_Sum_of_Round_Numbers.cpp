#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> ans;

    int v = 1;
    while (n > 0){
        int m = n % 10;
        if (m != 0) {
            ans.push_back(m * pow(10, (v-1)));
        }
        v++;
        n /= 10;
    }
    
    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}