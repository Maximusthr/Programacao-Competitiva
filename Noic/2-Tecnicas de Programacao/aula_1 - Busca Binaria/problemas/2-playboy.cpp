#include <bits/stdc++.h>

using namespace std;

vector<int> altura;
vector<int> consulta;
int x, y;

int menor_buscab(int x, int y){
    int ini = 0, fim = x;
    int meio;

    int ans = -1;
    while(ini <= fim){
        meio = (ini+fim)/2;
        if (meio == x) break;
        if (altura[meio] < y){
            ans = altura[meio];
            ini = meio+1;
        } else fim = meio-1;
    }

    return ans;
}

int maior_buscab(int x, int y){
    int ini = 0, fim = x;
    int meio;

    int ans = -1;
    while(ini <= fim){
        meio = (ini+fim)/2;
        if (meio == x) break;
        if (altura[meio] > y){
            ans = altura[meio];
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }

    return ans;
}

int main(){
    cin >> x;
    for (int i = 0; i < x; i++){
        int aux; cin >> aux;
        altura.push_back(aux);
    }

    cin >> y;
    for (int i = 0; i < y; i++){
        int aux; cin >> aux;
        consulta.push_back(aux);
    }

    int menor_ans = -1;
    int maior_ans = -1;
    for (int i = 0; i < y; i++){
        
        menor_ans = menor_buscab(x, consulta[i]);
        maior_ans = maior_buscab(x, consulta[i]);

        if (menor_ans == -1 && maior_ans == -1) cout << "X X\n";
        else if (menor_ans == -1) cout << "X " << maior_ans << "\n";
        else if (maior_ans == -1) cout << menor_ans << " X\n";
        else cout << menor_ans << " " << maior_ans << "\n";
    }
}
