//https://leetcode-cn.com/problems/course-schedule/
//topologicSort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> adj(numCourses);
        //维护入度数组和邻接表
        for(vector<int> prerequisite : prerequisites){
            inDegree[prerequisite[1]]++;
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        queue<int> q;
        int cnt = 0;
        //获取入度为0的点
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int val = q.front(); q.pop();
            ++cnt;
            for(int next : adj[val]){
                inDegree[next]--;
                if(inDegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return cnt == numCourses;
    }
};
