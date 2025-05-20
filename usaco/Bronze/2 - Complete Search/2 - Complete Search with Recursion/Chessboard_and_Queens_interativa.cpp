// Ideia interativa

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int DIM = 8;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    vector<vector<bool>> blocked(DIM, vector<bool> (DIM));

    for (int r = 0; r < DIM; r++){
        string row; cin >> row;
        for (int c = 0; c < DIM; c++){
            blocked[r][c] = row[c] == '*';
        }
    }

    vector<int> queens(DIM);
    iota(queens.begin(), queens.end(), 0);

    int valid_num = 0;
    do{ 
        bool works = true;
        
        // verificar o bloqueio da celula
        for (int c = 0; c < DIM; c++){
            if (blocked[queens[c]][c]){
                works = false;
                break;
            }
        }

        // verificar a diagonal topo da esquerda até o topo da direita
        vector<bool> taken(DIM * 2 - 1);
        for (int c = 0; c < DIM; c++){
            // verifica se uma dama capturou a outra
            if (taken[c + queens[c]]) {
                works = false;
                break;
            }
            taken[c + queens[c]] = true;
        }

        // top-right to the bottom-left
        taken = vector<bool> (DIM * 2 - 1);
        for (int c = 0; c < DIM; c++){
            if (taken[queens[c] - c + DIM - 1]){
                works = false;
                break;
            }
            taken[queens[c] - c + DIM - 1] = true;
        }

        if (works) valid_num++;
    } while (next_permutation(queens.begin(), queens.end()));

    cout << valid_num << "\n";
}