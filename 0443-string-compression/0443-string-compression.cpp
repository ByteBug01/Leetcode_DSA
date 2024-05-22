class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int indx = 0;
        int i = 0;

        while(i<n){
            char currchar = chars[i];
            int cnt = 0;

            while(i<n && chars[i] == currchar){
                cnt++;
                i++;
            }

            chars[indx] = currchar;
            indx++;

            if(cnt > 1){
                string newch = to_string(cnt);

                for(char& ch: newch){
                    chars[indx] = ch;
                    indx++;
                }
            }
        }

        return indx;
    }
};