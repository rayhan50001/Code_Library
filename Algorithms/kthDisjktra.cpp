typedef long long ll;
typedef pair<int, int> pii;


vector<int>G[MAX], W[MAX], dist[MAX];

int KthDikjstra(int Start, int End, int Kth) {      // Kth Shortest Path (Visits Same Edge More Than Once if required)
    for(int i = 0; i < MAX; ++i)
        dist[i].clear();
    priority_queue<pii>pq;                  // Weight, Node
    pq.push(make_pair(0, Start));

    while(!pq.empty()) {
        int u = pq.top().second;
        int w = -pq.top().first;
        pq.pop();

        if(dist[u].empty())
            dist[u].push_back(w);
        else if(dist[u].back() != w) {          // if the weight is not same
            if((int)dist[u].size() < Kth)       // if we have to take more costs, take it
                dist[u].push_back(w);
            else if(dist[u].back() <= w)        // if the cost is greater than previous, then, don't go further
                continue;
            else {                              // we have to take this cost, and remove the greater one
                dist[u].push_back(w);
                sort(dist[u].begin(), dist[u].end());
                dist[u].pop_back();
        }}
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int v = G[u][i];
            int _w = w + W[u][i];
            pq.push(make_pair(-_w, v));
    }}
    if((int)dist[End].size() < Kth) return -1;
    return dist[End].back();
}
