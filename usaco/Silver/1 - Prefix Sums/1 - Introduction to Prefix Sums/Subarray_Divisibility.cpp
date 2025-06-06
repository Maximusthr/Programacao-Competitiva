#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<ll> arr(n+1);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];

        arr[i] += arr[i-1];
        arr[i] %= n;
        if (arr[i] < 0) arr[i] += n; 

    }

    map<ll, ll> v;
    for (int i = 1; i <= n; i++){
        v[arr[i]]++;
    }

    ll ans = 0;
    v[0]++;
    for (auto [x, y] : v){
        //if (x == 0) ans += y;
        ans += ((y-1)*(y))/2;
    }

    cout << ans << "\n";
}
