class MyCalendar {
public:

//fir se krooo-------------
set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end});

        if( it !=st.end() && it->first < end){
            return false;
        }

if(it != st.begin()){
auto previt = prev(it);

if(previt->second > start){
    return false;
}
}
st.insert({start, end});
return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */