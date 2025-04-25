#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool verif(string bin, int b){
    // b is the number that we want to check
    string aux;
    while (b > 1){
        int r = b % 2;
        aux += r+'0';
        b /= 2;
    }
    aux += '1';
    return (aux.size() == bin.size());
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    //freopen("test_cases.txt", "r", stdin);
    //freopen("saida.txt", "w", stdout);

    int t; cin >> t;

    while(t--){
        int n, x; cin >> n >> x;

        if (n == 1) cout << x << "\n";
        else {
            int temp = x;
            string num;
            while (temp > 1){
                int r = temp % 2;
                num += r+'0';
                temp /= 2;
            }
            if (x != 0) num += '1';
            reverse(num.begin(), num.end());
            
            int cont = 0;
            for (int i = (int)num.size()-1; i >= 0; i--){
                // check how many 1s
                if (num[i] == '1') cont++;
                else break;
            }

            // transforming 1111 to decimal
            int dec = 0;
            int i = 0;
            while (cont > 0){
                dec += pow(2, i);
                i++;
                cont--;
            }

            for (int i = 0; i < n; i++){
                if (i == n-1){
                    if (verif(num, i) && i < dec) cout << i << "\n";
                    else cout << x << "\n";
                }
                else if (i > dec) cout << x << " ";
                else cout << i << " ";
            }
        }
    }
}
