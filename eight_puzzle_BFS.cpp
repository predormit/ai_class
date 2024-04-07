#include<iostream>
#include<queue>
#include<cstring>
#include<set>
typedef struct{
    std::string state;
    int dis;
}node;
std::string start = "";
std::string goal = "123456780";
std::set<std::string> s;
int dir[4][2] = {
    {-1,0},{1,0},{0,1},{0,-1}
};
int bfs(){
    node st;
    st.state = start;
    st.dis = 0;
    if(goal==st.state){
        return st.dis;
    }
    s.insert(st.state);
    std::queue<node> q;
    q.push(st);
    while(!q.empty()){
        node now=q.front();
        q.pop();
        int z;
        for(int i = 0;i < 9;i++){
            if(now.state[i]=='0'){
                z = i;
                break;
            }
        }
        int x = z/3;
        int y = z%3;
        for(int i = 0;i < 4;i++){
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int nz = newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){
                node newnode;
                newnode.state = now.state;
                newnode.dis = now.dis+1;
                std::swap(newnode.state[z],newnode.state[nz]);
                if(newnode.state==goal){
                    return newnode.dis;
                }

                if(!(s.count(newnode.state))){
                    q.push(newnode);
                    s.insert(newnode.state);
                }
            }
        }
    }
    
    return -1;
}
int main(){
    char x;
    for(int i = 0;i < 9;i++){
        std::cin >> x;
        if(x=='x'){
            start += "0";
        }
        else{
            start += std::to_string(x-'0');
        }
    }
    //std::cout << start;
    int ans = bfs();
    std::cout << ans;
    return 0;
}