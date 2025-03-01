#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x = min(i, n-i-1);
            int y = min(j, n-j-1);
            int z = min(x, y);

            if (z % 2 == 1) cout << ".";
            else cout << "#";
        }
        cout << "\n";
    }
    
}
