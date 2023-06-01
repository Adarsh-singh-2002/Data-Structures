class Solution 
{

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        vis[0] = 1;

        queue<int> q;
        q.push_back(0);

        vector<int> ans;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i : adj[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        } 
        return bfs;
    }

};