#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    int n; cin >> n;

    struct v {
        ll a, x, b, y;
    };

    vector<v> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].x >> arr[i].b >> arr[i].y;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].a > arr[i].b){
            ans += arr[i].a - arr[i].b;
            arr[i].a = arr[i].b;
        }
        if(arr[i].x > arr[i].y){
            ans += arr[i].x - arr[i].y + arr[i].a;
            arr[i].x = arr[i].y;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}