#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int query(int x, int y){
    cout << "? " << x << " " << y << endl;

    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    
    int v = query(1, 2);
    int v2 = query(2, 3);
    int v3 = query(1, 3);

    if (v || v3){
        cout << "! " << 1 << endl;
        return;
    }
    if (v2){
        cout << "! " << 2 << endl;
        return;
    }

    for(int i = 4; i < 2*n; i += 2){
        if (query(i, i+1)){
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << 2*n << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}