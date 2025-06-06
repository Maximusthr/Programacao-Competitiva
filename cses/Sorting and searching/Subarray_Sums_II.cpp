#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = 0;
    ll prefix_sum = 0;
    map<ll, int> rastreio;

    rastreio[0]++;
    for (int x : arr){
        prefix_sum += x;

        ans += rastreio[prefix_sum - k];

        rastreio[prefix_sum]++;
    }

    cout << ans << "\n";
}