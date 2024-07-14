class Solution {
public:
    string countOfAtoms(string formula) {
         int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                string mul;
                while (i < n && isdigit(formula[i])) {
                    mul += formula[i];
                    i++;
                }

                int mulInt = mul.empty() ? 1 : stoi(mul);

                for (auto& it : curr) {
                    st.top()[it.first] += it.second * mulInt;
                }
            } else {
                string currEle;
                currEle.push_back(formula[i]); // e.g., Mg
                i++;
                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currEle.push_back(formula[i]);
                    i++;
                }

                string currCnt;
                while (i < n && isdigit(formula[i])) {
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currCntInt = currCnt.empty() ? 1 : stoi(currCnt);
                st.top()[currEle] += currCntInt;
            }
        }

        map<string, int> sortedMp(begin(st.top()), end(st.top()));
        string result;

        for (auto& it : sortedMp) {
            result += it.first;
            if (it.second > 1) {
                result += to_string(it.second);
            }
        }

        return result;
    }
};

//Using stack
//T.C : O(n^2)
//S.C : O(n)