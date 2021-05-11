import java.util.*;
public class graph {
    static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    static int[] visited;
    public static void dfs(int v){
        visited[v] = 1;
        System.out.println(v);
        for(int child : arr.get(v)){
            if(visited[child] == 0){
                dfs(child);
            }
        }
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        // Adjacency list implementation of graph
        
        visited = new int[n];

        while(m > 0){
            int a = s.nextInt();
            int b = s.nextInt();
            if(arr.get(a) != null)
            arr.get(a).add(b);
            m--;
        }
    }
}
