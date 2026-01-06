#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    ll ans = 0;
    map<int, int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans += arr[i-x];
        arr[i+x]++;
    }

    cout << ans << "\n";
}