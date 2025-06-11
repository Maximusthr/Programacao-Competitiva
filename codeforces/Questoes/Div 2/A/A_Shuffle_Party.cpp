#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;
        
        string binario;
        while(x > 0){
            binario += ((x % 2) + '0');
            x /= 2;
        }
        reverse(binario.begin(), binario.end());

        cout << (int)(pow(2, (int)binario.size()-1)) << "\n";
    }
}
