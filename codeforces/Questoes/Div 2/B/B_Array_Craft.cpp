#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, p, s; cin >> n >> p >> s;

    vector<int> arr(n+1);
    arr[s] = 1;
    arr[p] = 1;

    bool alter = 0;
    for (int i = p+1; i <= n; i++){
        if (!alter) arr[i] = -1;
        else arr[i] = 1;
        alter ^= 1;
    }

    alter = 0;
    for (int i = s-1; i >= 1; i--){
        if (!alter) arr[i] = -1;
        else arr[i] = 1;
        alter ^= 1;
    }

    for (int i = s; i <= p; i++){
        arr[i] = 1;
    }

    for (int i = 1; i <= n; i++){
        cout << arr[i] << " \n"[i == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}