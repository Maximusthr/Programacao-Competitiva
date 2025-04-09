#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    int soma = 0;
    while(n--){
        string x; cin >> x;
        if (x[0] == '-' || x[1] == '-' || x[2] == '-') soma--;
        else if (x[0] == '+' || x[1] == '+' || x[2] == '+') soma++;
    }

    cout << soma << "\n";
}