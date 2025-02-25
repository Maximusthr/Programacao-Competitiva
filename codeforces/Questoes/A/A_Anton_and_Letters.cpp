#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x;
    getline(cin, x);

    set<char> aux;

    for (int i = 0; i < (int)x.size(); i++)
        if (x[i] >= 'a' && x[i] <= 'z') aux.insert(x[i]);
    

    cout << aux.size() << "\n";
}
