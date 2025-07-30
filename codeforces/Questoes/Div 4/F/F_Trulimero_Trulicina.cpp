#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;



void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(k);
    iota(arr.begin(), arr.end(), 1);

    vector<vector<int>> mat(n, vector<int> (m));

    int c = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mat[i][j] = arr[c%k];
            c++;
        }
    }

    if (m % k == 0){
        bool troquei = true;
        for (int i = 0; i < n; i++){
            if (!troquei){
                for (int j = 0; j < m-1; j++){
                    swap(mat[i][j], mat[i][j+1]);
                }
            }
            troquei ^= 1;
        }        
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << " \n"[j == m-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}