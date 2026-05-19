class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        unordered_map<int,vector<int>> prereqMap;
        for(int i = 0; i < numCourses; i++){
            prereqMap[i] = {};
        }
        for(const auto& prereq: prerequisites){
           prereqMap[prereq[0]].push_back(prereq[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i,visited,prereqMap)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int c, unordered_set<int>& visited, unordered_map<int,vector<int>>& prereqMap){
        if(visited.find(c)!=visited.end()){
            return false;
        }
        if(prereqMap[c].empty()){
            return true;
        }
        
        visited.insert(c);
        for(const auto& pre: prereqMap[c]){
            if(!dfs(pre,visited,prereqMap)){
                return false;
            };
        }
        
        visited.erase(c);
        prereqMap[c].clear();
        return true;
    }

};
