//1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int , list<int>> adj_front;
        unordered_map<int , list<int>> adj_rev;
        for(int i=0;i<connections.size();i++){
            int v=connections[i][0];
            int u=connections[i][1];
            adj_front[v].push_back(u);
            adj_rev[u].push_back(v);
                        
        }
        vector<bool> visited(n,false);
        queue<int> q;
        visited[0]=true;
        int cnt=0;
        q.push(0);
        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto neighbour:adj_front[front]){
                if(!visited[neighbour]){
                    cnt++;
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
            for(auto neighbour:adj_rev[front]){
                if(!visited[neighbour]){
                   
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        return cnt;
    }
};
