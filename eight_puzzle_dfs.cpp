#include<iostream>
#include<set>
const int MAX_SUM = 10000;
std::string start = "";
std::string goal = "12345678x";
std::set<std::string> reached;
int times = 0;
int dir[4][2]={
    {-1,0},{1,0},{0,1},{0,-1}
};
int dfs(int depth,int max_depth,std::string now){
    if(depth>max_depth) return 0;
    if(reached.count(now)) return 0;
    reached.insert(now);
    if(now==goal){
        return 1;
    }
    times++;
    int z;
    for(int i = 0;i < 9;i++){
        if(now[i]=='x'){
            z = i;
            break;
        }
    }
    int x = z/3;
    int y = z%3;
    for(int i = 0;i < 4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        int nz = nx*3+ny;
        if(nx>=0&&nx<3&&ny>=0&&ny<3){
                std::string newnode = now;
                std::swap(newnode[z],newnode[nz]);
                if(dfs(depth+1,max_depth,newnode)){
                    return 1;
                }
        }
    }
    return 0;
}
int main(){
    char x;
    for(int i = 0;i < 9;i++){
        std::cin >> x;
        start += x;
    }
    //std::cout << start;
    int ans = dfs(0,10000,start);
    std::cout << ans;
    return 0;
}