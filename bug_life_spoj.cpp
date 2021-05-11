#include<bits/stdc++.h>
using namespace std;
vector<int> arr[2001];
int visited[2001];
int color[2001];

bool dfs(int v, int c){
    visited[v] = 1;
    color[v] = c;

    for(int child : arr[v]){
        if(visited[child] == 0){
            if(dfs(child, c ^ 1) == false){  
                return false;
            }
        }
        else{
            if(color[v] == color[child]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    int count = 1;
    while(count <= t){
        int n, e;
        cin >> n >> e;

        // clear the adjacency list for new test case
        for(int  i = 1 ;i <= n; i++){
            arr[i].clear();
            visited[i] = 0;
            // color[i] = 0;
        }
        while(e--){
            int a,b;
            cin >> a >> b;

            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        bool flag = true;
        // for all connected components
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                bool ans = dfs(i,0);
                if(ans == false){
                    flag = false;
                } 
            }
            
        }
        cout <<"Scenario #" << count << ":" << endl;
        if(flag == false){
            cout << "Suspicious bugs found!" << endl;
        }
        else{
            cout << "No suspicious bugs found!";
        }
        count++;
    }
}