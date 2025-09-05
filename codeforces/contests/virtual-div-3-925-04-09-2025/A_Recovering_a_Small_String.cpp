#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    int v1 = 0, v2 = 0, v3 = 0;
    for (int i = 1; i <= 26; i++){
        v1 = i;
        for (int j = 1; j <= 26; j++){
            v2 = j;
            for (int k = 1; k <= 26; k++){
                v3 = k;
                if (v1 + v2 + v3 == n){
                    char a = v1 + 96;
                    char b = v2 + 96;
                    char c = v3 + 96;
                    cout << a << b << c << "\n";
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}