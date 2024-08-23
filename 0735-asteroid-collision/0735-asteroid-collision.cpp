class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
      
      for(auto& a: asteroids){
           while(!st.empty() && (a < 0 && st.top() > 0)){
               int sum  = a+st.top();
               if(sum<0){ //a > st.top()
                     st.pop();
               }else if(sum > 0){
                a = 0;
               }else{
                //equal strength
                 st.pop();
                 a=0;
               }
           }

           if(a != 0){
            st.push(a);
           }
      }

int i = st.size();
vector<int> ans(i);

while(!st.empty()){
     ans[i-1] = st.top();
     st.pop();
     i--;
}

        return ans;
    }
};