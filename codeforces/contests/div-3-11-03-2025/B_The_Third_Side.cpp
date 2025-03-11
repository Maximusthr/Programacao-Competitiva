#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);    
    int t; cin >> t;

    while(t--){
        int qtd; cin >> qtd;

        vector<int> arr(qtd);

        for (auto &i : arr) cin >> i;

        int aux = 0;
        if ((int)arr.size() == 1) cout << arr[0] << "\n";
        else if ((int)arr.size() == 2){
            aux = arr[0] + arr[1] - 1;
            cout << aux << "\n";
        }
        else{
            while((int)arr.size() != 2){
                aux = arr[(int)arr.size()-1] + arr[(int)arr.size()-2] - 1;

                arr.erase(arr.begin() + arr.size()-2, arr.end());
                arr.push_back(aux);
            }

            aux = arr[0] + arr[1] - 1;
            cout << aux << "\n";
        }

    }
}