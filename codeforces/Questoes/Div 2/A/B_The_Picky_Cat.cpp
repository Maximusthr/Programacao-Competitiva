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

        vector<int> arr(n+1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
            arr[i] = abs(arr[i]);
        }

        int alvo = arr[1];        
        sort(arr.begin()+1, arr.end());

        int pos = 0;
        for (int i = 1; i <= n; i++){
            if (arr[i] == alvo) {
                pos = i;
                break;
            }
        }

        if (pos <=  n/2 + 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
