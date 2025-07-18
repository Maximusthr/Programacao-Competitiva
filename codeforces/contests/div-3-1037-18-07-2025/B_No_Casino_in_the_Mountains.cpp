#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n); 
    for (auto &i : arr) cin >> i;

    int days = 0;
    int aux = 0;
    bool chegou = false;
    for (int i = 0; i < n; i++){
        if (chegou){
            chegou = false;
            continue;
        }
        if (arr[i] == 1){
            aux = 0;
        }
        else if (arr[i] == 0){
            aux++;
        }
        if (aux == k){
            days++;
            chegou = true;
            aux = 0;
        }
    }

    cout << days << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}