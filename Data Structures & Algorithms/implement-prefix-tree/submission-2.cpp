class PrefixTree {
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
    PrefixTree() {
        root=getnode();
    }
    
    void insert(string word) {
        trienode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL) {
                crawler->children[idx]=getnode();
            }
            crawler=crawler->children[idx];
        }
        crawler->endofword=true;
    }
    
    bool search(string word) {
        trienode* crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL) {
                return false;
            }
            crawler=crawler->children[idx];
        }
        return (crawler != NULL && crawler->endofword);
    }
    
    bool startsWith(string prefix) {
        trienode* crawler=root;
        int i=0;
        for(;i<prefix.size();i++){
            char ch=prefix[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL) {
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(i==prefix.length()) return true;
        return false;
    }
};
