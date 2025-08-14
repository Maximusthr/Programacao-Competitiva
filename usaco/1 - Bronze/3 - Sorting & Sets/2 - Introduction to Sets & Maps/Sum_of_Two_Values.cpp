#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    vector<int> arr(n+1);
    map<int, int> ind;
    map<int, int> duplo;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (ind[arr[i]]) {
            duplo[arr[i]] = i;
            continue;
        }
        ind[arr[i]] = i;
    }

    for (int i = 1; i <= n; i++){
        if (k - arr[i] <= 0) continue;
        if (ind[k - arr[i]]){
            if (k-arr[i] == arr[i]) {
                if (duplo[arr[i]] > 0) {
                    cout << i << " " << duplo[arr[i]] << "\n"; 
                    return;
                }
                else continue;
            }
            cout << i << " " << ind[k-arr[i]] << "\n";
            return;
        }
    }

    cout << "IMPOSSIBLE" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}
