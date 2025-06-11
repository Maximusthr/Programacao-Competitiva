#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    char a = 'a';
    char A = 'A';

    if (x[0] >= 97){
        x[0] -= 32;
    }

    cout << x << "\n";
}
