#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string a; cin >> a;
    sort(a.begin(), a.end());

    vector<string> arr;

    do{
        arr.push_back(a);
    } while(next_permutation(a.begin(), a.end()));
    
    cout << arr.size() << "\n";

    for (int i = 0; i < (int)arr.size(); i++){
        cout << arr[i] << "\n";
    }
}
