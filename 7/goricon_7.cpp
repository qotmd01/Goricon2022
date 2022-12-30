#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int cnt; // 중복되는
    int child[2]; // 0과 1의 비트
    int fail;
    Node(){
        cnt = 0;
        fail = -1; // 실패함수의 위치.
        for (int i = 0; i < 2; ++i) {
            child[i] = -1;
        }
    }
};

vector<Node> trieL;
vector<Node> trieH;
int rootL;
int rootH;

// 0 -> Low 트라이, 1 -> High 트라이
int mkNode(int dir){
    Node newNode;
    if(dir == 0){
        trieL.push_back(newNode);
        return trieL.size() - 1;
    }
    else{
        trieH.push_back(newNode);
        return trieH.size() - 1;
    }
}

// dir = 0 -> LOW 트라이, 1 -> High 트라이
void addNode(int curNode, string &temp , int idx, int dir){
    if (idx == temp.size()){
        if(dir == 0){
            trieL[curNode].cnt++;
        }
        else{
            trieH[curNode].cnt++;
        }
        return;
    }

    int curC = temp[idx] - '0';
    if (dir == 0 && trieL[curNode].child[curC] == -1){
        int nxt = mkNode(dir);
        trieL[curNode].child[curC] = nxt;
    }
    else if(dir == 1 && trieH[curNode].child[curC] == -1){
        int nxt = mkNode(dir);
        trieH[curNode].child[curC] = nxt;
    }

    if(dir == 0) addNode(trieL[curNode].child[curC], temp, idx + 1, dir);
    else addNode(trieH[curNode].child[curC], temp, idx + 1, dir);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int B, N;
    cin >> B;
    rootL = mkNode(0);
    rootH = mkNode(1);

    for(int i = 0; i < B; i++){
        string temp;
        cin >> temp;
        addNode(rootL, temp, 0, 0);
    }
    for(int i = 0; i < B; i++){
        string temp;
        cin >> temp;
        addNode(rootH , temp, 0, 1);
    }

    queue<int> q;

    trieL[rootL].fail = rootL;
    q.push(rootL);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < 2; ++i){
            int nxt = trieL[cur].child[i];
            if(nxt == -1) continue;
            if(cur == rootL) trieL[nxt].fail = rootL;
            else{
                int temp = trieL[cur].fail;
                while (temp != rootL && trieL[temp].child[i] == -1){
                    temp = trieL[temp].fail;
                }
                if(trieL[temp].child[i] != -1){
                    temp = trieL[temp].child[i];
                }
                trieL[nxt].fail = temp;
            }
            int fail = trieL[nxt].fail;
            if(trieL[fail].cnt) trieL[nxt].cnt += trieL[fail].cnt;
            q.push(nxt);
        }
    }


    trieH[rootH].fail = rootH;
    q.push(rootL);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < 2; ++i){
            int nxt = trieH[cur].child[i];
            if(nxt == -1) continue;
            if(cur == rootH) trieH[nxt].fail = rootH;
            else{
                int temp = trieH[cur].fail;
                while (temp != rootH && trieH[temp].child[i] == -1){
                    temp = trieH[temp].fail;
                }
                if(trieH[temp].child[i] != -1){
                    temp = trieH[temp].child[i];
                }
                trieH[nxt].fail = temp;
            }
            int fail = trieH[nxt].fail;
            if(trieH[fail].cnt) trieH[nxt].cnt += trieH[fail].cnt;
            q.push(nxt);
        }
    }

    cin >> N;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        int Lcnt = 0, Hcnt = 0;
        int cur = rootL;
        for(int j = 0; j < temp.size(); j++){
            int cur_c = temp[j] - '0';
            while (cur != rootL && trieL[cur].child[cur_c] == -1){
                cur = trieL[cur].fail;
            }
            if(trieL[cur].child[cur_c] != -1){
                cur = trieL[cur].child[cur_c];
            }
            if(trieL[cur].cnt) Lcnt += trieL[cur].cnt;
        }

        cur = rootH;
        for(int j = 0; j < temp.size(); j++){
            int cur_c = temp[j] - '0';
            while (cur != rootH && trieH[cur].child[cur_c] == -1){
                cur = trieH[cur].fail;
            }
            if(trieH[cur].child[cur_c] != -1){
                cur = trieH[cur].child[cur_c];
            }
            if(trieH[cur].cnt) Hcnt += trieH[cur].cnt;
        }
        if (Lcnt == Hcnt) printf("GOOD\n");
        else if(Lcnt > Hcnt) printf("HIGH %d\n", Lcnt - Hcnt);
        else printf("LOW %d\n", Hcnt - Lcnt);

    }

    return 0;

}