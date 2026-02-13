#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++){
        arr[i] = (arr[i-1] * a + b) % c;
    }

    ll result = 0;
    ll vals = 0;
    int wind = 0;
    for (int i = 0; i < n; i++){
        while(i < n && wind < k){
            vals ^= arr[i];
            i++;
            wind++;
        }
        result ^= vals;
        vals ^= arr[i-k];
        wind--;
        i--;
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}