#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<bool> vis(n);
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[arr[i]-1] = i;
    
    vector<int> aux(n);
    iota(aux.begin(), aux.end(), 1);

    for (int i = n-1; i >= 0; i--){
        vis[arr[i]-1] = true;
        if (arr[i] < arr[i-1]) break;
    }

    int ans = 0;
    while(!is_sorted(arr.begin(), arr.end())){
        // ver se os elementos na frente dele já foram visitados
        bool ok = false;
        for (int elem = arr[0]-1; elem >= 0; elem--){
            if (vis[elem]){
                vis[arr[0]-1] = true;
                int idx = pos[elem];
                arr.insert(arr.begin() + idx + 1, arr[0]);
                arr.erase(arr.begin());
                ok = true;
                // nova pos
                for (int i = 0; i < n; i++){
                    pos[arr[i]-1] = i;
                }
                break;
            }
        }
        if (!ok){
            for (int elem = arr[0]-1; elem < n; elem++){
                if (vis[elem]){
                    vis[arr[0]-1] = true;
                    int idx = pos[elem];
                    arr.insert(arr.begin() + idx, arr[0]);
                    arr.erase(arr.begin());
                    for (int i = 0; i < n; i++){
                        pos[arr[i]-1] = i;
                    }
                    break;
                }
            }
        }
        ans++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    solve();
}