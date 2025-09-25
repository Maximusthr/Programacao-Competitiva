#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    map<ll, int> a;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }

    int ans = 0;
    for (auto [x, y] : a){
        if (x > y) ans += y;
        else if (y > x) ans += y-x;
    }

    cout << ans << "\n";
}