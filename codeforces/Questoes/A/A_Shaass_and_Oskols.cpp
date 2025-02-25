#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    int arr[qtd+1];
    for (int i = 1; i <= qtd; i++){
        cin >> arr[i];
    }

    int call; cin >> call;

    while(call--){
        int x, y; cin >> x >> y;

        if (x == 1){
            int left = arr[x] - y;
            arr[x] = 0;
            arr[x+1] += left;
            
        }
        else if (x == qtd){
            int right = y - 1;
            arr[x] = 0;
            arr[x-1] += right;
        }
        else {
            int left = arr[x] - y;
            arr[x+1] += left;
            int right = y - 1;
            arr[x-1] += right;

            arr[x] = 0;
        }
    }

    for (int i = 1; i <= qtd; i++){
        cout << arr[i] << "\n";
    }
}
