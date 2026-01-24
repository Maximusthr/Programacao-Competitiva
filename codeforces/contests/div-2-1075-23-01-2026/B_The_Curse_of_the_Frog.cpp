#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve?

struct P {
    ll a, b, c;  
};

void solve(){
    ll n, k; cin >> n >> k;
    vector<P> arr(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }

    ll roll = 0;
    ll coord = 0;
    for (int i = 0; i < n; i++){
        roll = max(roll, arr[i].a * arr[i].b - arr[i].c);
        coord += (arr[i].a*(arr[i].b-1));
    }
    
    k -= coord;
    if (k <= 0){
        cout << 0 << "\n";
        return;
    }
    if (roll <= 0){
        cout << -1 << "\n";
        return;
    }

    cout << (k + roll - 1)/roll << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}