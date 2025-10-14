#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    auto calc = [&](int num) -> int {
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        
        return sum;
    };
    
    vector<int> arr(2e5 + 1);
    iota(arr.begin(), arr.end(), 0);

    for (int i = 1; i <= 2e5; i++){
        arr[i] = calc(i) + arr[i-1];
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << arr[n] << "\n";
    }
}