class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> project(n);

        for(int i = 0; i<n; i++){
            project[i] = {capital[i], profits[i]};
        }

        sort(project.begin(), project.end());

        priority_queue<int> que; //max heap

        int idx = 0;

        for(int i = 0; i<k; i++){
            while(idx < n && project[idx].first <= w){
                 que.push(project[idx].second);
                 idx++;
            }

            if(que.empty()){
                break;
            }

            w+= que.top();
            que.pop();
        }

        return w;
    }
};