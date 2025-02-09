#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int lista[n], count = 0;
    for (int i = 0; i < n; i++){
        cin >> lista[i];
        if (lista[i-2] == 1 && lista[i-1] == 0 && lista[i] == 0){
            count++;
        }
    }
    cout << count << "\n";
}
