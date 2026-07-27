class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    // {cost, {node, stops}}

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int w = f[2];

            adj[u].push_back({v, w});
        }

        // dist[node][stops] = minimum cost to reach node using 'stops' flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({0, {src, 0}});
        dist[src][0] = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int node = curr.second.first;
            int stops = curr.second.second;

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (auto &[next, price] : adj[node]) {

                int newCost = cost + price;

                if (newCost < dist[next][stops + 1]) {

                    dist[next][stops + 1] = newCost;

                    pq.push({newCost, {next, stops + 1}});
                }
            }
        }

        return -1;
    }
};