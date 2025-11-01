#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    double n; cin >> n;

    if (4 * n > n * n){
        cout << "N" << "\n";
        return;
    }

    double a = (n + sqrtl(n*n - 4*n))/2;

    cout << fixed << setprecision(10);
    cout << "Y " << a << " " << n - a << "\n";
  
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}