#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    string s;

    int l = 0, r = n-1, ant = 0;
    while(l <= r){
        if (arr[l] < arr[r]){
            if (arr[l] > ant){
                ant = arr[l];
                s += 'L';
                l++;
            }
            else if (ant < arr[r]){
                ant = arr[r];
                s += 'R';
                r--;
            }
            else break;
        }
        else {
            if (arr[r] > ant){
                ant = arr[r];
                s += 'R';
                r--;
            }
            else if (arr[l] > ant){
                ant = arr[l];
                s += 'L';
                l++;
            }
            else break;
        }
    }

    cout << s.size() << "\n" << s << "\n";
}