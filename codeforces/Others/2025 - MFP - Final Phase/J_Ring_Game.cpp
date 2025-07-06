#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll pr, pa; cin >> pr >> pa;
    ll a; cin >> a;

    if (a <= 1){
        cout << 0 << "\n";
        return 0;
    }

    cout << max(pr, pa) * (a/2 + (a%2)) * min(pr, pa) * (a/2) << "\n";
}