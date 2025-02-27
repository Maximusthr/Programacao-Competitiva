#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x, y;

    while(cin >> x >> y){
        int vetor_p[510] = { 0 };

        int vetor_x[x.size()];
        int vetor_y[y.size()];

        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        for (int i = 0; i < (int)x.size(); i++){
            vetor_x[i] = x[i]-'0';
        }
        for (int i = 0; i < (int)y.size(); i++){
            vetor_y[i] = y[i]-'0';
        }

        int carry = 0;

        for (int i = 0, k = 0; i < (int)x.size(); i++){
            k = i;
            for (int j = 0; j < (int)y.size(); j++){
                int aux = vetor_x[i] * vetor_y[j];
                if (aux > 9){
                    int temp = aux;
                    carry = temp/10;
                    aux %= 10;
                }
                vetor_p[k++] += aux;
                int another_carry = 0;
                if (vetor_p[k-1] > 9){
                    int temp = vetor_p[k-1];
                    another_carry = temp/10;
                    vetor_p[k-1] %= 10;
                }
                vetor_p[k] += carry + another_carry;
                carry = 0;
            }
        }
       
        bool ok = false;
        for (int i = 509; i >= 0; i--){
            if (vetor_p[i] == 0 && !ok) continue;
            else {
                ok = true;
                cout << vetor_p[i];
            }
        }
        if (!ok) cout << 0;

        cout << "\n";
    }
}
