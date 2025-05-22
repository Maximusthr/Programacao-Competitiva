#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;
//int mat[MAX][MAX] = {};
//int mat[MAX][MAX]; // usando memset

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    int n; cin >> n;
    
    //memset(mat, 0, sizeof(mat));
    vector<vector<int>> mat(MAX, vector<int> (MAX));

    for (int i = 0; i < n; i++){
        int ini, end, b; cin >> ini >> end >> b;

        for (int j = ini; j <= end; j++){
            mat[i][j] = b;
        }
    }

    int ans = 0;

    for (int i = 0; i < MAX; i++){
        int temp = 0;
        for (int j = 0; j < MAX; j++){
            temp += mat[j][i];
        }

        ans = max(ans, temp);
    }

    cout << ans << "\n";
}
