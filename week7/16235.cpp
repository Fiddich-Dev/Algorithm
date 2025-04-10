#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[14][14];
int energy[14][14];
int death[14][14];
int x, y, z;
vector<int> tree[14][14];

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};


// 봄
// 여름
void spring() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(tree[i][j].size() == 0) {
                continue;
            }

            int die_tree = 0;
            vector<int> temp;

            // 어린 나무부터
            sort(tree[i][j].begin(), tree[i][j].end());
            // 양분 흡수
            for(int k = 0; k < tree[i][j].size(); k++) {
                // 양분 흡수 가능
                if(energy[i][j] >= tree[i][j][k]) {
                    energy[i][j] -= tree[i][j][k];
                    temp.push_back(tree[i][j][k]+1);
                }
                // 양분 흡수 불가능
                else {
                    die_tree += tree[i][j][k] / 2;
                }
            }
            tree[i][j] = temp;
            energy[i][j] += die_tree;
        }
    }
}

void fall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < tree[i][j].size(); k++) {
                // 번식
                if(tree[i][j][k] % 5 == 0) {
                    for(int l = 0; l < 8; l++) {
                        int ny = i + dy[l];
                        int nx = j + dx[l];

                        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
                            continue;
                        }

                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            energy[i][j] += a[i][j];
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--;
        y--;
        tree[x][y].push_back(z);
    }

    fill(&energy[0][0], &energy[0][0] + 14*14, 5);

    

    while(t--) {
        spring();
        fall();
        winter();
    }

    int ret = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret += tree[i][j].size();
            // cout << tree[i][j].size() << " ";
        }
        // cout << '\n';
    }

    cout << ret << "\n";
}

// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.

// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.

// 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.

