class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        return freq1==freq2;
    }
};
