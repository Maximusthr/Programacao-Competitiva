#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    vector<int> arr(t);

    for (int &i : arr) cin >> i;

    queue<int> team1, team2, team3;

    for (int i = 0; i < t; i++){
        if (arr[i] == 1) team1.push(i+1);
        else if (arr[i] == 2) team2.push(i+1);
        else team3.push(i+1);
    }

    int min1 = min(team1.size(), team2.size());
    int min2 = min(team2.size(), team3.size());
    int min_real = min(min1, min2);
    
    cout << min_real << "\n";
    for (int i = 0; i < min_real; i++){
        cout << team1.front() << " " << team2.front() << " " << team3.front() << "\n";
        team1.pop();
        team2.pop();
        team3.pop();
    }
}
