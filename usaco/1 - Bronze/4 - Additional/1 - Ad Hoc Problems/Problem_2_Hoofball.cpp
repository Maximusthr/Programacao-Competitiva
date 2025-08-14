#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<int> vis(n);
    vis[0] = 1;
    vis[n-1] = n-2;

    for (int i = 1; i < n-1; i++){
        int dist_left = arr[i] - arr[i-1];
        int dist_right = arr[i+1] - arr[i];

        if (dist_left <= dist_right) vis[i] = i-1;
        else vis[i] = i+1;
    }

    // pontos solitarios
    // pontos de ciclos que sejam solitarios

    int ans = 0;
    vector<int> incoming(n);
    for (int i = 0; i < n; i++) incoming[vis[i]]++;
    
    for (int i = 0; i < n; i++) if (incoming[i] == 0) ans++;


    for (int i = 0; i < n-1; i++){
        if (vis[i] == i+1 && vis[i+1] == i){
            if (vis[i] == i+1 && vis[i+1] == i) {
                if (incoming[i] == 1 && incoming[i+1] == 1) ans++;
            }
        }
    }

    cout << ans << "\n";
}