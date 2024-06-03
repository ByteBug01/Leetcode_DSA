class Solution {
public:

typedef pair<char, int> P;

struct comp{
 bool operator()(P & p1, P & p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
        return p1.first > p2.first;
 }
};
    string clearStars(string s) {
int n = s.length();

priority_queue<P, vector<P>, comp> pq; // heap according to comparator

for(int i = 0; i<n; i++){
    if(s[i] != '*'){
        pq.push({s[i], i});
    }else{
        // if it is '*' then pop the most recent or top char from heap and record the index
        int idx = pq.top().second;
        pq.pop();
        s[idx] = '*';
    }
}
string ans = "";
for(int i = 0; i<n; i++){
    if(s[i] != '*'){
       ans += s[i];
    }
}
return ans;
    }

};


