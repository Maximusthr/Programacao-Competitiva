#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int menor = *min_element(arr.begin(), arr.end());
    int maior = INF;

    for (int i = 0; i < n; i++){
        if (arr[i] == menor) continue;
        
        if (arr[i] - menor <= menor) {
            cout << menor << "\n";
            return;
        }
        else maior = min(maior, arr[i] - menor);
    }
    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}