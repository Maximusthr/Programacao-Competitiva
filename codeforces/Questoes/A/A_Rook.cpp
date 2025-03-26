#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        char square; cin >> square;
        int num; cin >> num;
    
        // vertically
    
        for (int i = 1; i <= 8; i++){
            if (num == i) continue;
            else cout << square << i << "\n";
        }
    
        char aux = 'a';
        for (int i = 1; i <= 8; i++){
            if (square == aux) {
                aux++;
                continue;
            }
            else cout << aux << num << "\n";
            aux++;
        }
    }
}
