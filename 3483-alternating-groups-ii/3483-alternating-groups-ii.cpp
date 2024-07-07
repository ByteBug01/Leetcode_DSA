class Solution {
public:

// 0 1 0 1 0 + 0 1 0 1 0 
// if k = 3 , we can add upto k-1 chars from intially at the back i.e
// 0 1 0 1 0 + 0 1
// therefore loop is iterated upto (n-1)+(k-1)

// if the condition is satisfied then we increase the window 
// and if the window >= k, then window of size k inside wnd will also be alternating therefore increase ans

//colors[(i-1+n) % n], this has been done for cyclic one

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int wnd = 1;

        int ans = 0;

        for(int i = 1; i<=n-1+k-1; i++){
            if(colors[i%n] != colors[(i-1+n) % n]){
                wnd++;
            }else{
                wnd = 1;
            }

            if(wnd >= k) ans++;
        }

        return ans;
    }
};