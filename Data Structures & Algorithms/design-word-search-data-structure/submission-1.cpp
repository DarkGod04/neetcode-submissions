class WordDictionary {
public:
    struct trienode{
        bool endofword;
        trienode* children[26];
    };
    trienode* getnode(){
        trienode* newnode=new trienode();
        newnode->endofword=false;
        for(int i=0;i<26;i++){
            newnode->children[i]=NULL;
        }
        return newnode;
    }
    trienode* root;
    WordDictionary() {
        root=getnode();
    }
    
    void addWord(string word) {
        trienode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getnode();
            }
            crawler=crawler->children[idx];
        }
        crawler->endofword=true;
    }
    bool searchuntil(trienode* root,string word) {
        trienode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(crawler->children[j]!=NULL){
                        if(searchuntil(crawler->children[j],word.substr(i+1))==true) return true;
                    }
                }
                return false;
            }
            int idx=ch-'a';
            if(crawler->children[idx]==NULL) return false;
            crawler=crawler->children[idx];
        }
        return (crawler!=NULL && crawler->endofword);
    }

    bool search(string word) {
        return searchuntil(root,word);
    }
};
