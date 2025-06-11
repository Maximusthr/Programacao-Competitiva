#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        string x; cin >> x;
        int ans = 1, aux = 1;

        for (int i = 1; i < n; i++){
            if (x[i] != x[i-1]) aux = 1;
            else aux++;

            ans = max(ans, aux);
        }

        cout << ++ans << "\n";
    }
}
