#include <bits/stdc++.h>
using namespace std;

struct A {
    int q;
    int w;
    int e;
};

int n;
int a[3];
A atk[6] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1}
};
int visited[64][64][64];



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<A> q;
    q.push({a[0], a[1], a[2]});
    visited[a[0]][a[1]][a[2]] = 1;

    while(q.size()) {
        A temp = q.front();
        q.pop();

        for(A next : atk) {
            int temp1 = max(0, temp.q - next.q);
            int temp2 = max(0, temp.w - next.w);
            int temp3 = max(0, temp.e - next.e);

            if(visited[temp1][temp2][temp3] == 0) {
                q.push({temp1, temp2, temp3});
                visited[temp1][temp2][temp3] = visited[temp.q][temp.w][temp.e] + 1;
            }
        }
    }
    cout << visited[0][0][0] - 1 << "\n";
}