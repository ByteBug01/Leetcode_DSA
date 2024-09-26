class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
         set<int> st;

         for(auto & it: candyType){
            st.insert(it);
         }

         int limit = n/2;

         if( st.size() >= limit){
            return limit;
         }
     
     return st.size();
    }
};