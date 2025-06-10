#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, q; cin >> n >> q;

    vector<vector<int>> forest(n+1, vector<int> (n+1));
    vector<vector<int>> prefix(n+1, vector<int> (n+1));

    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (s[i][j] == '*') forest[i+1][j+1] = 1;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            prefix[i][j] = forest[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    
    while(q--){
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;

        int valor = prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1];

        cout << valor << "\n";

    }
}
