#include<iostream>
#include<cstring>
#include<queue>
const int N = 310010;
typedef std::pair<int,int> PII;
int e[N],ne[N],h[N],idx;
int st[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int bfs(){
    std::queue<PII> q;
    q.push({1,0});
    if(n==1){
                return 0;
            }
    while(!q.empty()){
        PII p = q.front();
        q.pop();
        int t = p.first;
        int step = p.second;
        if(st[t]){
            continue;
        }
        st[t] = 1;
        step++;
        for(int i = h[t];i != -1;i = ne[i]){
            int j = e[i];
            if(j==n){
                return step;
            }
            if(!st[j]){
                //std::cout << j << " "<<step<<std::endl;
                q.push({j,step});
            }
        }
    }
    return -1;
}
int main(){
    memset(h,-1,sizeof(h));
    std::cin >> n >> m;
    int a,b;
    for(int i = 0;i < m;i++){
        std::cin >> a >> b;
        add(a,b);
    }
    int ans = bfs();
    std::cout << ans;
    return 0;
}