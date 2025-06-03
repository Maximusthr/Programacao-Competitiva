#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<ll>arr(n+1);

        bool dif = false;
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            if (i != 1 && arr[i] != arr[i-1]) dif = true;
        }

        if (dif){
            ll ans = LINF;
            for (int i = 1; i <= n; i++){
                ll aux_right = 0;
                ll aux_left = 0;
                aux_left = (i - 1) * arr[i];
                
                if (i != n && arr[i] == arr[i+1]){
                    int fim = 0;
                    int j = i; 
                    while(j < n && arr[j] == arr[j+1]){
                        aux_right = (n-j) * arr[j] - arr[j];
                        fim = j;
                        j++;
                    }

                    ans = min(ans, aux_right + aux_left);

                    i = fim;
                    continue;
                }
                else aux_right = (n-i) * arr[i];
                
                ll temp = aux_right + aux_left;
                ans = min(ans, temp);
            }
            cout << ans << "\n";
        }
        else cout << 0 << "\n";
    }
}