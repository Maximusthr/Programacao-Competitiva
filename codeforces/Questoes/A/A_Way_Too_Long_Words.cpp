#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    for (int i = 0; i < t; i++){
        string x; cin >> x;

        if (x.size() > 10) {
            cout << x[0] << x.size() - 2 << x[x.size()-1] << "\n";
        }
        else cout << x << "\n";
    }
}
