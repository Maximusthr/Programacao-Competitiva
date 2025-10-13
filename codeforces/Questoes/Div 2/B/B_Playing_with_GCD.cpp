#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return (a * b)/__gcd(a, b);
} 

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    arr[n] = 1;

    vector<int> b(n+2, 1);;
    for (int i = 1; i <= n; i++){
        b[i] = lcm(arr[i], arr[i-1]);
    }   

    for (int i = 1; i < n; i++){
        if (__gcd(b[i], b[i+1]) != arr[i]){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}