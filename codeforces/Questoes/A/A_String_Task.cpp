#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string x; cin >> x;

    string new_string;

    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] == 'A' || x[i] == 'a' || x[i] == 'E' || x[i] == 'e' || x[i] == 'I' || x[i] == 'i' || x[i] == 'O' || x[i] == 'o' || x[i] == 'U' || x[i] == 'u' || x[i] == 'Y' || x[i] == 'y') continue;

        new_string += ".";
        if (x[i] >= 65 && x[i] <= 90){
            new_string += x[i] + 32;
        }
        else {
            new_string += x[i];
        } 
    }

cout << new_string << "\n";
}
