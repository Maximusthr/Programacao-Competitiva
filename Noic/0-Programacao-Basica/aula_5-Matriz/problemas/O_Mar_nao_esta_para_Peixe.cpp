#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 103;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<int>> mat(MAX, vector<int> (MAX));
    vector<vector<int>> prefix(MAX, vector<int> (MAX));

    for (int i = 0; i < n; i++){
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;

        mat[x1][y1]++;
        mat[x1][y2]--;
        mat[x2][y1]--;
        mat[x2][y2]++;
    }

    for (int i = 1; i < MAX; i++){
        for (int j = 1; j < MAX; j++){
            prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    int ans = 0;
    for (int i = 1; i < MAX; i++){
        for (int j = 1; j < MAX; j++){
            if (prefix[i][j] > 0) ans++;
        }
    }

    cout << ans << "\n";
}
