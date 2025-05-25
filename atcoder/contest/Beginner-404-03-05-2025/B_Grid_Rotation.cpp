//CS in time

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void rotate(vector<vector<char>> &s, int n){
    vector<vector<char>> res(n, vector<char> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res[j][n-i-1] = s[i][j];
        }
    }
    s = res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    vector<vector<char>> s(n, vector<char> (n));
    vector<vector<char>> t(n, vector<char> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> t[i][j];
        }
    }

    int dist = 0;
    vector<pair<int, int>> num;
    int ans = INF;

    for (int k = 0; k < 4; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (s[i][j] != t[i][j]) dist++;
            }
        }

        ans = min(ans, dist + k);
        dist = 0;
        rotate(s, n);
    }

    cout << ans << "\n";
}
