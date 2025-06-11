#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        map<int, int> arr;

        for (int i = 0; i < n; i++){
            int x; cin >> x;
            arr[x]++;
        }   
        
        int total = n;
       
        int par = 0, qtd_par = 0;
        int impar = 0, qtd_impar = 0;


        for (auto [x, y] : arr){
            if (y >= 2) {
                if (y % 2 == 0) {
                    par++;
                    qtd_par += y;
                }
                else {
                    impar++;
                    qtd_impar += y;
                }
            }
        }

        if (par == 1) total -= qtd_par;
        else if (par % 2 == 0) total = total - qtd_par + par;
        else if (par % 2 == 1) total = total - qtd_par + par-1;
        if (impar == 1) total = total - qtd_impar + 1;
        else total = total - qtd_impar + impar;

        cout << total << "\n";
    }
}
