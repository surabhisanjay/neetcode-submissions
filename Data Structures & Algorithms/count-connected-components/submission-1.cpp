class Solution {
public:
    vector<int> all_components;
    unordered_map<int,vector<int>> adj;
    int countComponents(int n, vector<vector<int>>& edges) {
        
        int res_count=0;
        for(int i= 0; i < n; i++){
            adj[i] = {};
        }
        for(const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n,false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(visited,i);
                res_count++;
            }
        }
        return res_count;

    }
    void dfs(vector<bool>& visited,int i){
        
        visited[i] = true;
        for(const auto& edge: adj[i]){
            if(!visited[edge]){
                dfs(visited,edge);
            }
        }
    }

};
