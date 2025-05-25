#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<vector<int>> mat (n, vector<int> (n));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        int sum = (n*2) * ((n*2) + 1)/2;

        int sum_aux = 0;
        deque<int> perm;
        for (int i = 0, j = 0; j < n; j++){
            perm.push_back(mat[i][j]);
            sum_aux += mat[i][j];
        }
        for (int i = n-1, j = 1; j < n; j++){
            perm.push_back(mat[i][j]);
            sum_aux += mat[i][j];
        }   

        perm.push_front(sum-sum_aux);

        for (int i = 0; i < n*2; i++){
            cout << perm[i] << " ";
        }
        cout << "\n";
    }
}
