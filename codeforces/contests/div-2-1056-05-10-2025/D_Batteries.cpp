#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int add = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n-i; j++){
            for (int k = j+add; k <= n; k++){
                cout << j << " " << k << endl;
                break;
            }
            int x; cin >> x;
            if (x == 1){
                return;
            }
        }
        add++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}