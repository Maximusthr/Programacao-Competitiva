#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    if (n == 1 && k == 0){
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    // maior num
    string num;
    int aux = k;
    while (num.size() < n){
        if (aux > 9){
            num += '9';
            aux -= 9;
        }
        else {
            if (aux > 0){
                num += (aux) + '0';
                aux = 0;
            }
            else {
                while (num.size() != n){
                    num += '0';
                }
            }
        }
    }

    // menor num
    string menor;
    aux = k;
    while (aux > 0 && menor.size() <= n){
        if (aux > 9){
            menor += '9';
            aux -= 9;
        }
        else {
            if (aux == 1){
                while (menor.size() < n && menor.size() != n-1){
                    menor += '0';
                }
                menor += '1';
                aux--;
            }
            else {
                // corner case
                if (menor.size() == n-1){
                    menor += ((aux) + '0');
                    aux = 0;
                    break;
                }
 
                menor += ((aux-1) + '0');
                aux = 1;
            }
        }
    }

    reverse(menor.begin(), menor.end());

    if (menor.size() != n || num.size() != n){
        cout << -1 << " " << -1 << "\n";
        return 0;
    }
    cout << menor << " " << num << "\n";
}