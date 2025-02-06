#include <bits/stdc++.h>
using namespace std;

int ret;

int binarySearch(vector<int> arr, int target) {
    int left = 0;
    int right = arr.size();

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] > target) {
            right = mid - 1;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
    }
    return -1;
}


int main() {
    vector<int> arr = {1, 3, 6, 9, 10, 21, 22, 30};
    sort(arr.begin(), arr.end());
    int target = 6;

    ret = binarySearch(arr, target);

    cout << ret << "\n";
}