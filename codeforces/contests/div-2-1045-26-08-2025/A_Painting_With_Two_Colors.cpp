#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    if (n == a && n == b){
        cout << "YES" << "\n";
        return;
    }

    if (n%2 && a%2 && b%2){
        cout << "YES" << "\n";
        return;
    }
    if (n%2 == 0 && a%2 == 0 && b % 2 == 0){
        cout << "YES" << "\n";
        return;
    }
    if (n%2 == 0 && a%2 && b%2 == 0){
        if (b > a){
            cout << "YES" << "\n";
            return;
        }
    }
    if (n%2){
        if (a % 2 == 0 && b % 2 && b > a){
            cout << "YES" << "\n";
            return;
        }
    }
    // if (n % 2 == 0 && a%2 && b%2){
    //     cout << "NO" << "\n";
    //     return;
    // }

    cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}