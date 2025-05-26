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

        if (n == 0) cout << 0 << " " << 0 << "\n";
        else if ((int)sqrt(n)*(int)sqrt(n) == n){
            cout << sqrt(n)-1 << " " << 1 << "\n";
        }
        else cout << "-1" << "\n";
    }
}