#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int pos_X[] = {-1, 0, 0, 1, 1, -1, 1, -1};
int pos_Y[] = {0, -1, 1, 0, 1, -1, -1, 1};

vector<vector<char>> g;
int n, m;

bool isValid(int x, int y){    
    return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '#');
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;

    g.resize(n, vector<char> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (g[i][j] == '.'){
                int v = 0;
                for (int k = 0; k < 8; k++){
                    int cx = i + pos_X[k];
                    int cy = j + pos_Y[k];

                    if (isValid(cx, cy)){
                        v++;
                    }

                }
                g[i][j] = (v + '0');
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
}