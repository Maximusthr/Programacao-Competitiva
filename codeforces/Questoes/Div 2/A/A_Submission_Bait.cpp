#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        map<int, int> v;

        for (int i = 0; i < n; i++){
            int x; cin >> x;
            v[x]++;
        }

        bool ok = false;
        for (auto [x, y] : v){
            if (y % 2){
                cout << "YES" << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) cout << "NO" << "\n";
    }
}
