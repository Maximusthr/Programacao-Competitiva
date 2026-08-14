#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n <= 9){
        cout << n << "\n";
    }
    else if (n >= 10 && n <= 17){
        cout << n % 10 + n/10 << "" << 9 << "\n";
    }
    else if (n >= 18 && n <= 24){
        cout << abs(24 - n - 7) << "" << 89 << "\n";
    }
    else if (n >= 25 && n <= 30){
        cout << abs(30 - n - 5) + 1 << "" << 789 << "\n";
    }
    else if (n >= 31 && n <= 35){
        cout << abs(35 - n - 4) + 1 << "" << 6789 << "\n";
    }
    else if (n >= 36 && n <= 39){
        cout << abs(39 - n - 3) + 1 << "" << 56789 << "\n";
    }
    else if (n >= 40 && n <= 42){
        cout << abs(42 - n - 2) + 1 << "" << 456789 << "\n";
    }
    else if (n == 43){
        cout << 13456789 << "\n";
    }
    else if (n == 44){
        cout << 23456789 << "\n";
    }
    else cout << 123456789 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
