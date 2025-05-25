#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        string x; cin >> x;
        string new_x = x;
        reverse(new_x.begin(), new_x.end());
        if (k == 0){
            cout << (new_x > x ? "YES" : "NO") << "\n";
        }
        else {
            string aux; 
            string inv;
            for (int i = 0; i < n; i++){
                if (x[i] > new_x[0]) aux += x[i];
                else if (x[i] < new_x[0]) inv += x[i];
            }   

            if (aux.size() >= 1 || inv.size() >= 1) cout << "YES" << "\n";
            else cout << "NO" << "\n";   
        }
    }
}
