/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
// //dfs //not working--------------------------------------------
//       map<int,map<int,set<int>>> mymap;
//     void solve(TreeNode *curr,int col,int row)
//     {
//         if(!curr)
//             return;
        
//         mymap[col][row].insert(curr->val);
//         solve(curr->left,col-1,row+1);
//         solve(curr->right,col+1,row+1);
//     }

//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         solve(root,0,0);
        
//         vector<vector<int>> ans;
//         for(auto m1: mymap)
//         {    
//             ans.push_back(vector<int>());
//             for(auto m2: m1.second)
//             {
//                 for(auto m3: m2.second)
//                     ans.back().push_back(m3);
//             }
//         }
//         return ans;
//     }
// };

//bfs-------------------------this is also not working
// class Solution {
//     public:

//  vector<vector<int>> verticalTraversal(TreeNode* root){
  
//   TreeNode * curr;

//   queue<pair<TreeNode*, int>> q;
//   q.push({root, 0});

//   vector<vector<int>> ans; //final ans

//   map<int, vector<int>> mymp;

//   while(!q.empty()){
//     int size = q.size();
//     map<int, set<int>> mpset;

//     while(size--){
//        curr = q.front().first;
//        int col = q.front().second;
//        q.pop();

//        mpset[col].insert(curr->val);

//        if(curr->left)
//         q.push({curr->left, col-1});
       
//        if(curr->right)
//         q.push({curr->right, col+1});

//     }
     
//      for(auto it: mpset){
//         for(auto it2: it.second){
//             mymp[it.first].push_back(it2);
//         }
//      }

//   }

// for(auto it: mymp){
//     ans.push_back(it.second);
// }

// return ans;

// }
// };

//------------------------------------------

class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){ //for multiples nodes in same row or column sort these by their values
        if(a.first==b.first)
            return a.second<=b.second;
        else
            return a.first<b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<pair<int,int>>> m;
        int j=1;
        while(!q.empty()){//BFS
            int n=q.size();
            for(int i=0 ; i<n ; i++){
            auto p=q.front();
            q.pop();
            TreeNode* top=p.first;
            int lev=p.second;
            if(top->left){
                q.push({top->left,lev-1});
            }
            if(top->right){
                q.push({top->right,lev+1});
            }
            m[lev].push_back({j,top->val});   
            }
            j++;
        }
        for(auto a:m){
            sort(a.second.begin(),a.second.end(),comp);
            vector<int> temp;
            for(auto l:a.second){
                temp.push_back(l.second);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};