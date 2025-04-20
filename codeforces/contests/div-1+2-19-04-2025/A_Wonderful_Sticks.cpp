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
        string x; cin >> x;

        deque<int> arr(n);
        iota(arr.begin(), arr.end(), 1);

        deque<int> real;

        for (int i = x.size()-1; i >= 0; i--){
            if (x[i] == '>') {
                real.push_front(arr[arr.size()-1]);
                arr.pop_back();
            }
            else {
                real.push_front(arr[0]);
                arr.pop_front();
            }
        }

        real.push_front(arr[0]);

        for (int i = 0; i < n; i++){
            cout << real[i] << " ";
        }
        cout << "\n";
    }
}
