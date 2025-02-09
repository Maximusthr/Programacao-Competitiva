#include <iostream>

using namespace std;

int main(){
    int n, i;
    cin >> n;

    int lista[n], soma = 0;

    for (int i = 0; i < n; i++){
        cin >> lista[i];
        soma += lista[i];
    }

    cout << soma - n << "\n";
    
}   

// int main(){
//     int n;
//     cin >> n;
//     int ans = 0;

//     while(n--){
//         int x;
//         cin >> x;
//         ans += x-1;
//     }
//     cout << ans << "\n";
// }