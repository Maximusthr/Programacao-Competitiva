#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    
    while(t--){
        string x;
        getline(cin >> ws, x);

        string new_string;
        for (int i = 0; i < (int)x.size(); i++){
            if (i == 0) new_string += x[0];
            else if (x[i] == ' ' && i+1 < (int)x.size()) new_string += x[i+1];
        }

        cout << new_string << "\n";
    }
}
