#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    vector<int> pos(n+1);
    vector<int> aux(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[i] = arr[i];
        aux[arr[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <=n; i++){
        if ((pos[i] == i) || (pos[arr[i]] == i)) continue;
        ans++;
        
        int a = aux[i];
        int b = pos[i];
        swap(arr[aux[i]], arr[pos[i]]);

        int v1 = arr[aux[i]];
        int v2 = arr[pos[i]];

        pos[aux[i]] = v1;
        pos[arr[i]] = v2;
        aux[v2] = b;
        aux[v1] = a;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}