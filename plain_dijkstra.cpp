#include<iostream>
#include<cstring>
const int N = 600;
const int M = 100010;
int g[N][N];
int dist[M];
int n,m;
bool st[N];
int dijkstra(){
    dist[1] = 0;
    for(int i = 0;i < n;i++){
        int t = -1;
        for(int j = 1;j <= n;j++){
            if(!st[j] && (t == -1||dist[t] > dist[j])){
                t = j;
            }
        }
        st[t] = true;
        for(int x = 1;x <= n;x++){
            dist[x] = std::min(dist[x],dist[t] + g[t][x]);
        }
    }

    if(dist[n]==0x7f7f7f7f){
        return -1;
    }
    return dist[n];
}
int main(){
    std::cin >> n >> m;
    memset(g,0x7f,sizeof(g));
    memset(dist,0x7f,sizeof(dist));
    for(int i = 0;i < m;i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        g[a][b] = std::min(g[a][b],c);
    }
    int ans = dijkstra();
    std::cout << ans;
    return 0;
}