class Solution {
public:
    
    //detect cycles in a graph 

    unordered_map<int,vector<int>> prereqMap;
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i < numCourses; i++){
            prereqMap[i] = {};
        }
        for(const auto& prereq: prerequisites){
            prereqMap[prereq[0]].push_back(prereq[1]);

        }
        for(int c = 0; c< numCourses; c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int c){
        if(visiting.count(c)){
            return false;
        }
        if(prereqMap[c].empty())
        {
            return true;
        }
        visiting.insert(c);
        for(int pre: prereqMap[c]){
            if(!dfs(pre)){
                return false;
            }
        }
        visiting.erase(c);
        prereqMap[c].clear();
        return true;
    }
};
