#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<ll> dif(n+2);

    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        dif[l]++;
        dif[r+1]--;
    }

    for (int i = 1; i <= n; i++){
        dif[i] += dif[i-1];
    }

    sort(dif.begin(), dif.end());

    cout << dif[n/2 + 2] << "\n";
}
