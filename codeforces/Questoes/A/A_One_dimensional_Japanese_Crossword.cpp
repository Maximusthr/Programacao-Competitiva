#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    string x; cin >> x;

    vector<int> B;

    int sum = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == 'B') {
            sum++;
            if (i == n-1) B.push_back(sum);
        }
        else if (x[i] == 'W'){
            if (sum > 0) B.push_back(sum);
            sum = 0;
        }
    }

    cout << (int)B.size() << "\n";
    for (int i = 0; i < (int)B.size(); i++){
        cout << B[i] << " ";
    }
    cout << "\n";
}
