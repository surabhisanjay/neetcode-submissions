class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //while adding edges do a dfs and see if you end back where you came so for every node 
        // do a dfs 
        if(edges.size()> n-1){
            return false;
        }
        unordered_set<int> visited;
        unordered_map<int,vector<int>> tree;
        for(const auto& edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        
        if(!dfs(0,-1,visited,tree)){
            return false;
        }
        return visited.size() == n;
    }
    bool dfs(int e, int u,unordered_set<int> &visited,unordered_map<int,vector<int>>& tree){
        if(visited.find(e)!=visited.end()){
            return false;
        }
        visited.insert(e);
        for(int edge: tree[e]){
            if(edge == u){
                continue;
            }
            if(!dfs(edge,e,visited,tree)){
                return false;
            }
        }
        
        return true;
    }

};
