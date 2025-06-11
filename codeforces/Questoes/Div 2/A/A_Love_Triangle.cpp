#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int c = 0;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    bool ok = false;
    int i = 1;
    while(i <= n && !ok){
        int temp = 0;
        vector<int> num(3);
        for (int j = 0; j < 3; j++){
            if (j == 0) {
                temp = arr[i];
                num[0] = temp;
            }
            if (j == 1) {
                temp = arr[temp];
                num[1] = temp;
            }
            if (j == 2){
                temp = arr[temp];
                num[2] = temp;
                if (arr[temp] == num[0]) {
                    if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2]) continue;
                    ok = true;
                }
            }
        }
        i++;
    }

    cout << (ok ? "YES" : "NO") << "\n";
}
