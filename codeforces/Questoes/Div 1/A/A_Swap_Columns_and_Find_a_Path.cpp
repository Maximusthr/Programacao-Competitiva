#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<vector<int>> arr(2, vector<int> (n));

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int menor = -INF;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += max(arr[0][i], arr[1][i]);
        menor = max(menor, min(arr[0][i], arr[1][i]));
    }

    sum += menor;
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}