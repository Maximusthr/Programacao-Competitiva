#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        for (int i = 1, k = 1; k <= x; i += 2, k++) {
            cout << i << " ";
        }

        cout << "\n";
    }
}
