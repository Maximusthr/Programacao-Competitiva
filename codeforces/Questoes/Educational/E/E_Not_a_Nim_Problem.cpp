#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e7+5;

vector<int> grundy(MAX);

void solve(){
    int n; cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans ^= grundy[x];
    }

    cout << (ans ? "Alice" : "Bob") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int primos = 1;
    grundy[1] = 1;
    for (ll i = 3; i < MAX; i++){
        if (i % 2 == 0) continue;
        if (grundy[i] == 0) {
            grundy[i] = ++primos;
            for (ll j = i * i; j < MAX; j += i){
                if (j % 2 == 0 || grundy[j] != 0) continue;
                grundy[j] = grundy[i];
            }
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}