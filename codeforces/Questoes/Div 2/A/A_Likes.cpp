#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);

    int posi = 0;
    int sub = 0;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > 0) posi++;
        else sub++;
    }

    for (int i = 0; i < posi; i++){
        cout << i+1 << " ";
    }
    for (int i = 0; i < sub; i++){
        cout << posi - i - 1 << " ";
    }
    cout << "\n";

    int temp_neg = 0;
    int sum = 1;
    bool alter = false;
    for (int i = 0; i < n; i++){
        cout << sum << " \n"[i == n-1];
        if (!alter && temp_neg < sub){
            sum--;
            temp_neg++;
        }
        else sum++;
        
        alter ^= 1;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}