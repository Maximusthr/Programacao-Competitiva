#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string a; cin >> a;
    vector<int> arr((int)a.size());
    for (int i = 0; i < a.size(); i++){
        arr[i] = a[i] - '0';
    }

    string b; cin >> b;
    vector<int> arr2((int)b.size());
    for (int i = 0; i < (int)b.size(); i++){
        arr2[i] = b[i] - '0';
    }   

    vector<int> arr3((int)a.size());
    for (int i = 0; i < (int)a.size(); i++){
        arr3[i] = (arr[i] ^ arr2[i]);
        cout << arr3[i];
    }

    cout << "\n";
}
