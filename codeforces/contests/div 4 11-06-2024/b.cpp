#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;

    int aux = 2, ans;
    int sum = 0;
    int i;
    
    int count = 2;

    while (t--){
        int x;
        cin >> x;

        int div = x/2;

        for (i = 0; i < div; i++){
            for (int j = 0; j < div; j++){
                if (aux <= x){
                    sum += aux;
                }
                aux += count*i;
            }
                
        }

        if (sum >= x){
            ans = count;
        } else {
            ans = x;
        }

        cout << ans << "\n";

        aux = 2;
        sum = 0;
        ans = 0;
    }
}
