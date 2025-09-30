#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> prefix(n+1, vector<int> (31));
    for (int i = 1; i <= n; i++){
        for (int j = 30; j >= 0; j--){
            if (arr[i] & (1 << j)){
                prefix[i][j] = prefix[i-1][j] + 1;
            }
            else prefix[i][j] = prefix[i-1][j];
        }
    }

    int q; cin >> q;
    while(q--){
        int l, k; cin >> l >> k;

        if (arr[l] < k){
            cout << -1 << " ";
            continue;
        } 

        int lll = l, r = n;
        while (lll < r){
            int mid = lll + (r-lll+1)/2;
            
            int qtd = 0;
            for (int i = 30; i >= 0; i--){
                if (prefix[mid][i] - prefix[l-1][i] == mid - l + 1){
                    qtd += (1 << i);
                }
            }

            if (qtd >= k){
                lll = mid;
            }
            else r = mid - 1;
        }

        cout << lll << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}