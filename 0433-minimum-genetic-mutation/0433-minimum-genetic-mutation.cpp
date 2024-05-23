class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visited;

        q.push(startGene);
        visited.insert(startGene);

        int cnt = 0; //level

        while(!q.empty()){

            int n = q.size();
            while(n--){
            string node = q.front();
            q.pop();

            if(node == endGene){
                return cnt;
            }

         for(char ch: "ACGT"){
            for(int i = 0; i<node.length(); i++){
                string tmp = node;
                tmp[i] = ch;

//visited me nhi hona chiye && bankset me hona chiye
                if( visited.find(tmp) == visited.end() && bankset.find(tmp) != bankset.end()){ //check if tmp is present in the visited set and bank
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
         }
            }
         cnt++;
        }

return -1;
    }
};