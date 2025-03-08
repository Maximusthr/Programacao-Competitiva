#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x, y; cin >> x >> y;

    vector<int> arr;
    vector<int> odd;

    for (int i = 0; i < 2*x+1; i++){
        int aux; cin >> aux;
        arr.push_back(aux);
        if (i % 2 == 1) odd.push_back(aux);
    }

    for (int i = 1; i < (int)arr.size(); i += 2){
        if (y > 0 && (arr[i] - 1 > arr[i+1]) && (arr[i] - 1 > arr[i-1])) {
            arr[i] -= 1;
            y--;
        }
    }

    for (int i = 0; i < (int)arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
