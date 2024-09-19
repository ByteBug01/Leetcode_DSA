class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         vector<int> ans;
         int n = expression.length();

         for(int i = 0; i<n; i++){
              if(expression[i] == '*' || expression[i] == '+' || expression[i] == '-'){
                 vector<int> left_res = diffWaysToCompute(expression.substr(0, i));
                 vector<int> right_res = diffWaysToCompute(expression.substr(i+1));

                 for(int x: left_res){
                    for(int y : right_res){
                        if(expression[i] == '*'){
                            ans.push_back(x * y);
                        }else if(expression[i] == '+'){
                            ans.push_back(x + y);
                        }else{
                            ans.push_back(x - y);
                        }
                    }
                 }
              }
         }

         if(ans.empty()) {
            ans.push_back(stoi(expression));
         }

         return ans;
    }
};