#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1003;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;

    vector<vector<int>> mat(MAX, vector<int> (MAX));

    while(n--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
        mat[x1][y1]++;
        mat[x2][y2]++;
        mat[x2][y1]--;
        mat[x1][y2]--;
    }

    vector<vector<int>> prefix(MAX, vector<int> (MAX));

    int ans = 0;
    for (int i = 1; i < MAX; i++){
        for (int j = 1; j < MAX; j++){
            prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            if (prefix[i][j] == k) ans++;
        }
    }

    cout << ans << "\n";
}

