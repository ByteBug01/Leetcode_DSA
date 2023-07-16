class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        const int n = (int)req_skills.size();
        
        // Map skills to their corresponding bitmask values
        map<string, int> skill_to_bitmask;
        for (int i = 0; i < n; i++) {
            skill_to_bitmask[req_skills[i]] = (1 << i);
        }
        
        vector<int> people_bitmasks;
        
        // Convert each person's skills to a bitmask
        for (auto& person_skills : people) {
            int bitmask = 0;
            for (auto& skill : person_skills) {
                if (skill_to_bitmask.find(skill) != skill_to_bitmask.end()) {
                    bitmask |= skill_to_bitmask[skill];
                }
            }
            people_bitmasks.push_back(bitmask);
        }
        
        vector<int> distance(1 << n, -1);  // Store the shortest distance for each bitmask
        vector<pair<int, int>> parent(1 << n, {-1, -1});  // Store the parent information for backtracking
        queue<int> q;
        
        // Perform BFS to find the shortest path
        q.emplace(0);
        distance[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < (int)people_bitmasks.size(); i++) {
                int v = u | people_bitmasks[i];
                if (distance[v] == -1) {
                    parent[v] = {u, i};
                    distance[v] = distance[u] + 1;
                    q.emplace(v);
                } 
            }
        }
        
        // Backtracking to retrieve the team members
        vector<int> team;
        int x = (1 << n) - 1;
        while (parent[x].first != -1) {
            team.push_back(parent[x].second);
            x = parent[x].first;
        }

        assert(distance[(1 << n) - 1] == (int)team.size());  // Sanity check
        return team;
    }
};
