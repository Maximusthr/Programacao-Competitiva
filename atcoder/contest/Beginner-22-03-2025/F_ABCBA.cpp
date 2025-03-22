// WA E TLE

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string x; cin >> x;
    
    string new_x = x;
    string aux = x; 
    reverse(aux.begin(), aux.end());   

    if (aux == x) {
        cout << x << "\n";
        return 0;
    }

    bool ok = false;


    for (int i = (int)x.size()-2; i >= 0; i--){
        if (x[i] != x[i+1]) new_x += x[i];
        aux = new_x;
        reverse(aux.begin(), aux.end()); // O(n)
        if (new_x == aux) {
            break;
        }
    }

    cout << new_x << "\n";

}
