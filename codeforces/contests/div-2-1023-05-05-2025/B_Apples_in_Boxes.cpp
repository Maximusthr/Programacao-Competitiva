#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        ll sum = 0;
        map<int ,int> biggest;
        ll maior = 0;
        ll menor = INF;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            menor = min(arr[i], menor);
            maior = max(arr[i], maior);
            biggest[arr[i]]++;
        }

        // caso k = 0 (NÂO EXISTE CASO K =( )
        // if (k == 0 && maior == menor){
        //     if (maior - menor + 1 > k) cout << "Jerry" << "\n";
        //     else cout << "Tom" << "\n";
        // }
        if (biggest[maior] > 1){
            if (maior - menor > k || sum % 2 == 0) cout << "Jerry" << "\n";
            else cout << "Tom" << "\n";
        }
        else {
            if (maior - menor - 1 > k || sum % 2 == 0) cout << "Jerry" << "\n";
            else cout << "Tom" << "\n";
        }
    }
}
