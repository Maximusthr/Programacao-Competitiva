#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool check(vector<int> &arr, int a){

    int i = 0, j = arr.size()-1;    
    while(i < j){
        if (arr[i] == arr[j]){
            i++;
            j--;
        }
        else if (arr[i] == a) {
            i++;
        }
        else if (arr[j] == a){
            j--;
        }
        else return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int i = 0, j = n-1;
    while(i < j && arr[i] == arr[j]){
        i++, j--;
    }

    if (i >= j){
        cout << "YES" << "\n";
        return;
    }

    if (check(arr, arr[i]) || check(arr, arr[j])){
        cout << "YES" << "\n";
        return;
    }
    cout << "NO" << "\n";
    return;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}