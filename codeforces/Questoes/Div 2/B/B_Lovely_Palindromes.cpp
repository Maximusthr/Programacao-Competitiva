#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string x;
    cin >> x;

    string new_x = x;

    for (int i = (int)x.size()-1; i >= 0; i--){
        new_x += x[i];
    }

    cout << new_x << "\n";
}
