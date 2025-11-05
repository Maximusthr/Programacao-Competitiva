#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int maior(int n){
    int m = 0;
    while (n > 0){
        m = max(n % 10, m);
        n /= 10;
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int ans = 0;
    while(n > 0){
        n -= maior(n);
        ans++;
    }
    cout << ans << "\n";
}