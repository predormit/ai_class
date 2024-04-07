#include<iostream>
#include<cstring>
#include<queue>
const int N = 510100;
int e[N],w[N],ne[N],h[N],idx;
int n,m;
int dist[N];
bool st[N];
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dijkstra(){
    dist[1] = 0;
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
    q.push({0,1});
    while(!q.empty()){
        std::pair<int,int> t = q.top();
        q.pop();
        int distance = t.first,v = t.second;
        if(st[v]){
            continue;
        }
        st[v] = true;
        for(int i = h[v];i != -1;i = ne[i]){
            int j = e[i];
            dist[j] = std::min(dist[j],distance + w[i]);
            q.push({dist[j],j});
        }
    }
    if(dist[n]==0x7f7f7f7f){
        return -1;
    }
    return dist[n];
}
int main(){
    std::cin >> n >> m;
    memset(h,-1,sizeof(h));
    memset(dist,0x7f,sizeof(dist));
    for(int i = 0;i < m;i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        add(a,b,c);
    }
    int ans = dijkstra();
    std::cout << ans;
    return 0;
}