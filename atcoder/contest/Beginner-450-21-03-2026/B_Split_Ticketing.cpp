#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n+1, vector<int> (n+1));
    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    // tripleta
    // a < b <c
    // de forma que (a, b) + (b, c) < (a, c)

    for (int i = 1; i < n; i++){
        for (int j = i+1; j <= n; j++){
            ll custo = arr[i][j];
            for (int k = j+1; k <= n; k++){
                custo += arr[j][k];
                if (custo < arr[i][k]){
                    cout << "Yes" << "\n";
                    return;
                }
                custo -= arr[j][k];
            }
        }
    }

    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}