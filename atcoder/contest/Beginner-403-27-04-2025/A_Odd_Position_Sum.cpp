#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;
    int ans = 0;
    for (int i = 0; i < x; i++){
        if (i % 2 == 0) {
            int a; cin >> a;
            ans += a;
        }
        else {
            int a; cin >> a;
        }
    }

    cout << ans << "\n";

}