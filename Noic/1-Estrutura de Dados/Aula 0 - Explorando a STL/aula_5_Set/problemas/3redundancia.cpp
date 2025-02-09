#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    vector<int> sequence;
    set<int> nums;

    int x;
    while(cin >> x && x){
        sequence.push_back(x);
    }

    for (int i = 0; i < (int)sequence.size(); i++){
        nums.insert(sequence[i]);
    }

    for (int i = 0; i < (int)sequence.size(); i++){
        int soma = 0;
        if (nums.find(sequence[i]) != nums.end()){
            for (int j = 0; j < (int)sequence.size(); j++){
                if (sequence[i] == sequence[j]) soma++;
            }
            cout << sequence[i] << " " << soma << "\n";
            nums.erase(sequence[i]);
        } else continue;
    }   
}
