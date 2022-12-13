#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll,ll>;

void bfs(vector<vector<ll>>& grid, ll i, ll j,ll N, ll M){
    queue<pll> q = queue<pll>();
    q.push(pll(i,j));
    auto add = [&](pll p,vector<pll>& ne){
        if((0<=p.first && p.first<N) && (0<=p.second && p.second<M)){
            ne.push_back(p);
        }
    };
    auto get_nes = [&](pll p){
        vector<pll> ne;
        add(pll(p.first+1,p.second),ne);
        add(pll(p.first,p.second+1),ne);
        add(pll(p.first-1,p.second),ne);
        add(pll(p.first,p.second-1),ne);
        return ne;
    };
    while(!q.empty()){
        pll c = q.front();
        auto ne  = get_nes(c);
        for(auto p: ne){
            if(grid[p.first][p.second] ==0){
                q.push(p);
                grid[p.first][p.second] = 2;

            }
        }
        q.pop();


    }
}

void solution(vector<vector<ll>>& grid,ll N,ll M){
    ll count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j] == 0){
                bfs(grid,i,j,N,M);
                count +=1;
            }
        }
    }
    cout << count << endl;
    
}





int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<ll>> grid;
    for(int i=0;i<N;i++){
        vector<ll> r = vector<ll>(M);
        char c;
        for(int j=0;j<M;j++){
            cin >> c;
            r[j] = (c == '#') ? -1:0;
        }
        grid.push_back(r);
    }
    solution(grid,N,M);

    
    return 0;
}