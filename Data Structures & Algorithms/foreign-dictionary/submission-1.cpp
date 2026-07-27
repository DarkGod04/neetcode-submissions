class Solution {
public:
    bool dfs(vector<vector<int>>&adj ,int node,vector<int>&visited, stack<int>& st ){
        visited[node]=1;
        for(auto & it : adj[node]){
            if(visited[it]==1) return false;
            if(visited[it]==0){
                if(!dfs(adj,it,visited,st)) return false;
            }
        }
        visited[node]=2;
        st.push(node);
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        stack<int>st;
        vector<vector<int>>adj(26);
        vector<int>visited(26,0);
        vector<bool>present(26,false);
        for(auto & it : words){
            for ( char & ch : it){
                present[ch-'a']=true;
            }
        }
        for (int i=0;i<n-1;i++){
            string ch1=words[i];
            string ch2=words[i+1];
            int minlen=min(ch1.length(),ch2.length());
            if(ch1.size()>ch2.size() && ch1.substr(0,ch2.size())==ch2) return ""; 
            for(int j=0;j<minlen;j++){
                if(ch1[j]!=ch2[j]){
                    adj[ch1[j]-'a'].push_back(ch2[j]-'a');
                    break;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(present[i] && visited[i]==0 ){
                if(dfs(adj,i,visited,st)==false) return "";
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top()+'a');
            st.pop();
        }
        return ans;
    }
};