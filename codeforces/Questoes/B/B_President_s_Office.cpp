#include <bits/stdc++.h>

using namespace std;

int n, m;
bool isValid(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    char l;
    cin >> n >> m >> l;

    vector<string> mat(n);

    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }

    vector<char> vis;
    bool ok = false;
    bool valid = false;

    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] != '.' && mat[i][j] != l){
                if (isValid(i+1, j)) {
                    if (mat[i+1][j] == l) valid = true; 
                }
                if (isValid(i-1, j)) {
                    if (mat[i-1][j] == l) valid = true;;
                }
                if (isValid(i, j+1)) {
                    if (mat[i][j+1] == l) valid = true;
                }
                if (isValid(i, j-1)) {
                    if (mat[i][j-1] == l) valid = true; 
                }

                for (int k = 0; k < (int)vis.size(); k++){
                    if (mat[i][j] == vis[k]) {
                        ok = true;
                        break;
                    }
                }
                if (!ok && valid){
                    vis.push_back(mat[i][j]);
                    ans++;
                }
                ok = false;
                valid = false;
            }
        }
    }

    cout << ans << "\n";
}