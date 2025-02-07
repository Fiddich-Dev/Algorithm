#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int m;
int temp;


int binarySearch(vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            return 1;
        }
        else if(arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t; 
    for(int i = 0; i < t; i++) {
        vector<int> v1;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            v1.push_back(temp);
        }
        sort(v1.begin(), v1.end());

        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> temp;
            cout << binarySearch(v1, temp) << "\n";
        }
    }
}