#include <bits/stdc++.h>

using namespace std;

int main(){
    int x; cin >> x;

    vector<int> num(31);
    for (int i = 2, j = 4; i <= 30; i += 2){
        if (i == 2) num[i] = 2;
        else if (i == 4) num[i] = 6;
        else {
            num[i] = num[i-2] + (2*(j));
            j *= 2;
        }
        
    }
    
    for (int i = 0; i < x; i++){
        int a; cin >> a;
        cout << num[a] << "\n";
    }
}
