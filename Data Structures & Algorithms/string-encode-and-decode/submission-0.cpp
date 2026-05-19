class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(const string &str: strs){
            s+= to_string(str.length())+"#"+str;

        }
        
        return s;
    }

    vector<string> decode(string s) {
        vector<string> strings;
        int size ; 
        int i = 0;
        while(i < s.length()){
            int delim = s.find("#",i);
            int len = stoi(s.substr(i, delim - i));
            i = delim + 1;
            strings.push_back(s.substr(i,len));
            i += len;

        }
        return strings;
    }
};
