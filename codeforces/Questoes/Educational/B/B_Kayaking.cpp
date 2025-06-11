#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n*2);

    for(auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int mid = INF;
    // fixo um elemento
    for (int i = 0; i < n * 2; i++){
        // fixo o elemento do meio
        for (int j = 0; j < n * 2; j++){
            if (j == i) continue;
            int temp = 0;
            bool pular = false;
            for (int k = 0; k < n * 2; k += 2){
                if (k == i || k == j || pular){
                    if (pular) pular ^= 1;
                    k--;
                    continue;
                }

                if (k+1 == i || k+1 == j){
                    temp += abs(arr[k] - arr[k+2]);
                    pular = true;
                }
                else temp += abs(arr[k] - arr[k+1]);
            }
            mid = min(mid, temp);
        }
    }

    cout << mid << "\n";
}
