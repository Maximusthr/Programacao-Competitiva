#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    if (a*2 <= b){
        cout << n*a << "\n";
    }
    else {
        int sum = 0;
        while (n > 1){
            sum += b;
            n -= 2;
        }
        if (n) sum += a;
        cout << sum << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}