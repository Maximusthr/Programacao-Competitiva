#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int step, mod;
    while (cin >> step >> mod){
        vector<int> arr;
    
        arr.push_back(0);
    
        int aux = 0, i = 0;
        while(1){
            int oper = (aux + step) % mod;
            if (oper == 0) break;
            arr.push_back(oper);
            aux = oper;
        }
        sort(arr.begin(), arr.end());
    
        bool ok = true;
        if (arr.size() < mod) ok = false;
        else {
            for (int i = 0; i < mod; i++){
                if (arr[i] != i) {
                    ok = false;
                    break;
                }
            }
        }

        printf("%10d%10d    %s\n\n", step, mod, ok ? "Good Choice" : "Bad Choice");
    }
}
