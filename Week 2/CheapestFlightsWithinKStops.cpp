/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
*/
class Solution {
public:
    typedef tuple<int,int,int> ti;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
      vector<vector<pair<int,int>>> gp(n);
      for(auto &x:flights)
        gp[x[0]].push_back(make_pair(x[1],x[2]));
      priority_queue<ti,vector<ti>,greater<ti>> pq;
      pq.emplace(0,src,K+1);
      while(!pq.empty()){
        auto [cost,u,steps]=pq.top();
        pq.pop();
        if(u==dst) return cost;
        if(!steps) continue;
        for(auto v:gp[u]){
          pq.emplace(cost+v.second,v.first,steps-1);
        }
      }
      return -1;
    }
};
