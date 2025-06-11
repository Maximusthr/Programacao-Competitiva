#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;
    string y; cin >> y;

    bool ok = false;
    int pos_slice = 0;

    string A;
    string B;
    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] == '|') ok = true;
        else if (!ok) 
            A += x[i];
        else 
            B += x[i];
    }

    int tam_A = (int)A.size();
    int tam_B = (int)B.size();
    int tam_Y = (int)y.size(), tam_real = (int)y.size();

    if (tam_A > tam_B){
        if (tam_A - tam_B <= tam_Y){
            int k = 0;
            while (tam_B != tam_A){
                B += y[k];
                k++;
                tam_B++;
                tam_Y--;
            }
            int aux = 0;
            int sub = tam_Y;
            if (tam_Y > 0 && tam_Y % 2 == 0){                
                for (int i = k; i < k + (tam_Y/2); i++){
                    A += y[i];
                    sub--;
                    aux++;
                }
                for (int i = k + tam_Y/2 + aux - sub; i < tam_real; i++){
                    B += y[i];
                    sub--;
                }
            }
            if (sub > 0) cout << "Impossible" << "\n";
            else cout << A << "|" << B << "\n";
        }
        else cout << "Impossible" << "\n";
    }
    else {
        if (tam_B - tam_A <= tam_Y){
            int k = 0;
            while (tam_A != tam_B){
                A += y[k];
                k++;
                tam_A++;
                tam_Y--;
            }
            int aux = 0;
            int sub = tam_Y;
            if (tam_Y > 0 && tam_Y % 2 == 0){                
                for (int i = k; i < k + tam_Y/2; i++){
                    A += y[i];
                    sub--;
                    aux++;
                }
                for (int i = k + tam_Y/2 + aux - sub; i < tam_real; i++, k++){
                    B += y[i];
                    sub--;
                } 
            }
            if (sub > 0) cout << "Impossible" << "\n";
            else cout << A << "|" << B << "\n";
        }
        else cout << "Impossible" << "\n";
    }
}
