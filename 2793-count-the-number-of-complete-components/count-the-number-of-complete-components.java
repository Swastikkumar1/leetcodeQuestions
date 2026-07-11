class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] degree = new int[n];
        
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
            degree[u]++;
            degree[v]++;
        }
        
        boolean[] visited = new boolean[n];
        int completeComponents = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                List<Integer> componentNodes = new ArrayList<>();
                Queue<Integer> queue = new LinkedList<>();
                
                queue.offer(i);
                visited[i] = true;
                
                while (!queue.isEmpty()) {
                    int curr = queue.poll();
                    componentNodes.add(curr);
                    
                    for (int neighbor : adj.get(curr)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            queue.offer(neighbor);
                        }
                    }
                }
                int vCount = componentNodes.size();
                long totalDegreeSum = 0; 
                for (int node : componentNodes) {
                    totalDegreeSum += degree[node];
                }
                
                if (totalDegreeSum == (long) vCount * (vCount - 1)) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
}