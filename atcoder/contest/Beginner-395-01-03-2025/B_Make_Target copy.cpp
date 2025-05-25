#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    string matriz[n][n];

    for (int i = 0; i < n; i++){
        int a = n - i - 1;
        if (i > a) continue;

        char c = '#';
        if (i % 2) c = '.';
        for (int j = i; j <= a; j++){
            for (int k = i; k <= a; k++){
                matriz[j][k] = c;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matriz[i][j];
        }
        cout << "\n";
    }

}
