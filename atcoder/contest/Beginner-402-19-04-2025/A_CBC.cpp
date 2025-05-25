#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string x; cin >> x;


    string new_string;
    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] >= 'A' && x[i] <= 'Z') new_string += x[i];
    }

    cout << new_string << "\n";
}