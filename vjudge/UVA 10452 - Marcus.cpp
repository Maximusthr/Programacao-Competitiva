#include <bits/stdc++.h>

using namespace std;

int n, m; 
const int MAX = 9;
vector<string> g(MAX);
vector<string> path;

int pos_x[] = {-1, 0, 0};
int pos_y[] = {0, 1, -1};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m); 
}

string word = "IEHOVA#";
int pos = 0;

void dfs(int i, int j){
    // word to find -> IEHOVA -> #

    for (int a = 0; a < 3; a++){
        int cx = i + pos_x[a];
        int cy = j + pos_y[a];
        if (isValid(cx, cy) && word[pos] == g[cx][cy]){
            if (pos_x[a] == -1 && pos_y[a] == 0) path.push_back("forth");
            else if (pos_x[a] == 0 && pos_y[a] == 1) path.push_back("right");
            else if (pos_x[a] == 0 && pos_y[a] == -1) path.push_back("left");
            pos++;
            dfs(cx, cy);
        }
        else continue;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> g[i];
        }

        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j < m; j++){
                if (g[i][j] == '@'){
                    dfs(i, j);
                }
            }
            break;
        }

        for (int i = 0; i < (int)path.size(); i++){
            if (i == (int)path.size()-1) cout << path[i] << "\n";
            else cout << path[i] << " ";
        }


        g.assign(MAX, "");
        path.clear();
        pos = 0;
    }
}
