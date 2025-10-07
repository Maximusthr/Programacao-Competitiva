#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    tuple<int, int, int> ans = {0, 1, 1};
    for (int i = 0; i < n; i++){
        int inv = 0;
        for (int j = i+1; j < n; j++){
            if (arr[i] > arr[j]){
                inv++;
            }
            else if (arr[i] < arr[j]) {
                inv--;
            }

            if (inv > get<0>(ans)){
                ans = {inv, i+1, j+1};
            }
        }
    }

    cout << get<1>(ans) << " " << get<2>(ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}