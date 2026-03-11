#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n = 8;
    vector<string> s(n);
    for (auto &i : s) cin >> i;

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };

    int dx[6] = {1, -1, 0, -1, -1, 0};
    int dy[6] = {1, 1, 1, 0, -1, -1};

    for (int k = 0; k < 4*n; k++){
        bool achou = false;
        set<pair<int, int>> foi;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (foi.count({i, j})) continue;
                if (s[i][j] == 'M'){
                    achou = true;
                    for (int l = 0; l < 6; l++){
                        int cx = dx[l] + i;
                        int cy = dy[l] + j;

                        if (isValid(cx, cy) && s[cx][cy] == '.'){
                            s[cx][cy] = 'M';
                            foi.insert({cx, cy});
                        }
                        else if (isValid(cx, cy) && s[cx][cy] == 'A'){
                            cout << "WIN" << "\n";
                            return;
                        }
                    }
                }
            }
        }

        if (!achou){
            cout << "LOSE" << "\n";
            return;
        }
        
        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j < n; j++){
                if (s[i][j] == 'S'){
                    if (i+1 < n){
                        s[i+1][j] = 'S';
                    }
                    s[i][j] = '.';
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}