#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, r, b; cin >> n >> r >> b;

    int mn = r/(b+1);
    int ext = r % (b+1);

    for (int i = 0; i < b + 1; i++){
        for (int j = 0; j < mn; j++){
            cout << 'R';
        }
        if (ext > 0){
            cout << 'R';
            ext--;
        }
        if (i < b){
            cout << 'B';
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}