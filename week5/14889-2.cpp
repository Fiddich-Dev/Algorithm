#include <bits/stdc++.h>
using namespace std;

int n;
int a[24][24];
int visited[24];

int m = 987654321;

int solve(vector<int> v) {

    int sum = 0;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            sum += a[v[i]][v[j]];
        }
    }
    return sum;
}


void combi(int start, vector<int> b) {
    if(b.size() == n/2) {
        vector<int> start;
        vector<int> link;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 1) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        m = min(m, abs(solve(start) - solve(link)));

        return;
    } 
    for(int i = start+1; i < n; i++) {
        b.push_back(i);
        visited[i] = 1;
        combi(i, b);
        b.pop_back();
        visited[i] = 0;
    }
}


int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> v0;
    combi(-1, v0);

    cout << m << "\n";

}