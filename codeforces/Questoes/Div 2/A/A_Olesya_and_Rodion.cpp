#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, t; cin >> n >> t;

    bool um = (n == 1 ? true : false);

    if (um && t == 10) cout << -1 << "\n";
    else {
        // 10 é diferente
        if (t == 10){
            int count = 1;
            cout << 1;
            for (int i = 0; count < n; i++){
                cout << 0;
                count++;
            }    
        }
        else {
            for (int i = 0; i < n; i++){
                cout << t;
            }
        }
    }

    cout << "\n";
}
