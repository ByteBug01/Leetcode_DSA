// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int n = asteroids.size();
//         stack<int> st;
      
//       for(auto& a: asteroids){
//            while(!st.empty() && (a < 0 && st.top() > 0)){
//                int sum  = a+st.top();
//                if(sum<0){ //a > st.top() & oppo direction
//                      st.pop();
//                }else if(sum > 0){
//                 a = 0;
//                }else{
//                 //equal strength
//                  st.pop();
//                  a=0;
//                }
//            }

//            if(a != 0){
//             st.push(a);
//            }
//       }

// int i = st.size();
// vector<int> ans(i);

// while(!st.empty()){
//      ans[i-1] = st.top();
//      st.pop();
//      i--;
// }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     int n = asteroids.size();
     stack<int> st;

     for(auto & ast: asteroids){
        bool explode = false;
        while(!st.empty() && st.top() >0 && ast < 0){
            if(abs(st.top()) < abs(ast)){
                st.pop();
            }else if(abs(st.top()) == abs(ast)){
                st.pop();
                explode = true;
                break;
            }else{
                explode = true;
                break;
            }

        }
        if(!explode) st.push(ast);
     }


     vector<int> ans(st.size());

     for(int i = st.size()-1; i>=0; i--){
        ans[i] = st.top();
        st.pop();
     }

     return ans;
    }
};