#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int temp;
int sum;

int main() {

    for(int i = 0; i < 9; i++) {
        cin >> temp;
        v.push_back(temp);
        sum += temp;
    }

    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 9; j++) {
            if(sum - v[i]- v[j] == 100) {
                v.erase(v.begin() + j);
                v.erase(v.begin() + i);

                sort(v.begin(), v.end());
                for(int k : v) {
                    cout << k << "\n";
                }
                return 0;
            }
        }
    }

}