#include<iostream>
#include<cstring>
#include<queue>
#include<map>
typedef std::pair<int,std::string> PIS;
std::string start = "";
std::string goal = "12345678x";
std::priority_queue<PIS,std::vector<PIS>,std::greater<PIS>> p;
std::map<std::string,std::string> m;
std::map<std::string, int> dis;
int dir[4][2] = {
    {-1,0},{0,1},{1,0},{0,-1}
};
std::string op = "urdl";
int g(std::string s){
    int ans = 0;
    for(int i =0;i < 9;i++){
        if(s[i]!='x'){
            int y = s[i] - '1';
            ans += abs(y/3-i/3) + abs(y%3-i%3);
        }
    }
    return ans;
}
std::string astar(){
    PIS st;
    if(start==goal){
        return "";
    }
    st.second = start;
    st.first = g(st.second);
    p.push(st);
    m[start] = "";
    dis[start] = 0;
    while(!p.empty()){
        PIS now = p.top();
        p.pop();
        int z;
        std::string state = now.second;
        for(int i = 0;i < 9;i++){
            if(state[i]=='x'){
                z = i;
                break;
            }
        }

        int x = z/3;
        int y = z%3;
        int distance = dis[state];
        for(int i = 0;i < 4;i++){
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int nz = newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){
                PIS newnode;
                newnode.second = state;
                std::swap(newnode.second[z],newnode.second[nz]);
                newnode.first = distance + g(newnode.second) + 1;
                if(dis.count(newnode.second)==0||dis[newnode.second] > dis[state] + 1){
                    m[newnode.second] = m[state] + op[i];
                    dis[newnode.second] = distance + 1;
                    p.push(newnode);
                }
                //std::cout << newnode.second <<std::endl;
                //std::cout << m[newnode.second] <<std::endl;
                if(newnode.second==goal){
                    return m[newnode.second];
                }

            }
        }
    }
    return "unsolvable";
}
int main(){
    char x;
    std::string seq;
    for(int i = 0;i < 9;i++){
        std::cin >> x;
        start += x;
        if(x!='x'){
            seq += x;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 8; j++){
            if(seq[i] > seq[j]) cnt ++;
        }
    }
    if(cnt & 1){
        std::cout << "unsolvable";
    } 
    else{
        std::string ans = astar();
        std::cout << ans;
    }
    return 0;
}