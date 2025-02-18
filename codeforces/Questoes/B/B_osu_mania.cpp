#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        int num; cin >> num;
        vector<int> arr;
        for (int i = 0; i < num; i++){
            string aux; cin >> aux;
            for (int j = 0; j < 4; j++){
                if (aux[j] == '#') {
                    arr.push_back(j+1);
                    break;
                }
            }
        }

        for (int i = (int)arr.size()-1; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
