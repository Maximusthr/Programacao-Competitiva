#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, s;

    int casos = 1;
    while(cin >> c >> s){
        if (casos != 1) cout << "\n";

        //vector<int> chambers(c);
        vector<int> specimens;
        int maior = 0;
        int soma = 0;
        for (int i = 0; i < s; i++){
            int aux; cin >> aux;
            if (maior < aux) maior = aux;
            soma += aux;
            specimens.push_back(aux);
        }
        
        vector<int> copia = specimens;
        sort(copia.begin(), copia.end());

        vector<vector<int>> camaras(c);
        int j = 0;
        int pos = 0;
        int par = 0;
        int tamanho = (int)copia.size();
        int meio = tamanho/2;

        vector<int> excluidos;
        bool retorno = false;
        if (tamanho % 2 == 1){
            for (int i = 0; i < tamanho; i++){      
                retorno = false; 
                while ((int)copia.size() > meio){
                    for (int a = 0; a < (int)excluidos.size(); a++){
                        if (specimens[i] == excluidos[a]) {
                            retorno = true;
                            break;
                        }
                    }
                    if (retorno) break;


                    if (specimens[i] == maior){
                        if ((int)camaras[j].size() > 0) j++;
                        else {
                            camaras[j].push_back(specimens[i]);
                            specimens.erase(specimens.begin() + i);
                            i--;
                            j++;
                        }
                        break;
                    }

                    else {
                        // procurar o specimens e o seu respectivo par.
                        for (int k = 0; k < tamanho; k++){
                            if (specimens[i] == copia[k]){
                                pos = k;
                                break;
                            }
                        }

                        if (pos >= meio){
                            par = pos/2;
                            camaras[j].push_back(specimens[i]);
                            camaras[j].push_back(copia[par]);
                            excluidos.push_back(copia[par]);
                            copia.erase(copia.begin() + (par));
                        }
                        else if (pos < meio){
                            par = (int)copia.size()-pos-1;
                            camaras[j].push_back(specimens[i]);
                            camaras[j].push_back(copia[par]);
                            excluidos.push_back(copia[par]);
                            copia.erase(copia.begin() + (par));
                        }
                        j++;
                        break;
                    }
                }          
            }
        }


        double AM = (double)soma / c;
        double IMBA = 0;
        double somatorio = 0;

        cout << "Set #" << casos << "\n";
        for (int i = 0; i < c; i++){
            cout << i << ": ";
            for (int j  = 0; j < (int)camaras[i].size(); j++){
                if (j == (int)camaras[i].size()-1) cout << camaras[i][j] << "\n";
                else cout << camaras[i][j] << " ";
                somatorio += (double)camaras[i][j];
            }
            IMBA += abs(somatorio - AM);
            somatorio = 0;
        }
        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << IMBA << "\n";

        casos++;
    }
}
