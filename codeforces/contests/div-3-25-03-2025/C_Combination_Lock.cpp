#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        if (x % 2 == 0) cout << -1 << "\n";

        else {
            vector<int> odd;
            vector<int> even;

            for (int i = 1; i <= x; i++){
                if (i % 2 == 1) odd.push_back(i);
                else even.push_back(i);
            }

            for (int i = 0; i < (int)odd.size(); i++){
                cout << odd[i] << " ";
            }

            for (int i = 0; i < (int)even.size(); i++){
                cout << even[i] << " ";
            }
            cout << "\n";
        }

    }   
}