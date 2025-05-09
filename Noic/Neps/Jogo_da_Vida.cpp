#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, q;
vector<string> mat(n);
vector<string> copy_mat(n);

int pos_x[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int pos_y[8] = {1, -1, 0, 0, -1, 1, 1, -1};

bool isValid(int x, int y){
    return ((x >= 0 && x < n) && (y >= 0 && y < n));
}

void dfs(int u, int v){
    bool vivo = false;
    if (mat[u][v] == '1') vivo = true;

    int vis_vivo = 0;

    for (int i = 0; i < 8; i++){
        int cx = pos_x[i] + u;
        int cy = pos_y[i] + v;
        
        if (isValid(cx, cy)){
            if (mat[cx][cy] == '1') vis_vivo++;
        }
    }
    if (vivo && (vis_vivo < 2 || vis_vivo > 3)) copy_mat[u][v] = '0';
    else if (!vivo && vis_vivo == 3) copy_mat[u][v] = '1';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> q;
    mat.resize(n);
    copy_mat.resize(n);

    for (int i = 0; i < n; i++){
        cin >> mat[i];
    }

    copy_mat = mat;

    while(q--){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dfs(i, j);
            }
        }
        mat = copy_mat;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}
