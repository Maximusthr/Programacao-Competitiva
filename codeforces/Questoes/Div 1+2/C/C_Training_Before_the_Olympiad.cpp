#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> prefix(n+1);
    vector<int> odd(n+1);

    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        if (x%2){
            odd[i]++;
        }

        prefix[i] += x + prefix[i-1];
        odd[i] += odd[i-1];
    }

    for (int i = 1; i <= n; i++){
        if (i > 1){
            prefix[i] -= (odd[i])/3;
            if (odd[i] % 3 == 1) prefix[i]--;
        }

        cout << prefix[i] << " ";
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