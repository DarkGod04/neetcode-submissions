class Twitter {
    unordered_map<int,set<int>>friends;
    int curr=0;
    priority_queue<vector<int>>timeline;
public:
    Twitter() {
        curr=0;
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({curr++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>>pq=timeline;
        while(!pq.empty() && ans.size()<10){
            vector<int>tweet=pq.top();
            pq.pop();
            int tweetId=tweet[2];
            int tweetUser=tweet[1];
            if(tweetUser==userId || friends[userId].count(tweetUser)){
                ans.push_back(tweetId);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
