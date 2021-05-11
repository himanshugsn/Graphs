#include<bits/stdc++.h>
using namespace std;

vector<int> arr[1001];
int visited[1001];
int dist[1001];


void dfs(int v, int d){
    visited[v] = 1;
    dist[v] = d;
    for(int child : arr[v]){
        if(visited[child] == 0){
            dfs(child,dist[child]+1);
        }
    }
}

int main(){
    int n,q,a,b;
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    dfs(1,0);
    
    // number of girls
    cin >> q;
    int ans = -1, minDist = INT_MAX;
    while(q--){
        int girlCity;
        cin >> girlCity;
        if(dist[girlCity] < minDist){
            ans = girlCity;
            minDist = dist[girlCity];
        }
        else if(dist[girlCity] == minDist && girlCity < ans){
            ans = girlCity;
        }
        
    }
    cout << ans;
    return 0;
}