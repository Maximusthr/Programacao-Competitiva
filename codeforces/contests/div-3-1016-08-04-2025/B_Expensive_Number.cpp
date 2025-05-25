#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        string x; cin >> x;

        int soma = 0;
        int pos = 0;
        for (int i = (int)x.size()-1; i >= 0; i--){
            if (x[i] == '0') soma++;
            else if (x[i] != '0') {
                pos = i;
                break;
            }
        }

        for (int i = pos-1; i >= 0; i--){
            if (x[i] != '0') soma++;
        }


        cout << soma << "\n";
    }
}
