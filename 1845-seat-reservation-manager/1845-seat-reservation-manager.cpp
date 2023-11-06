class SeatManager {
public:
    
    priority_queue<int, vector<int>,greater<int>> pq;
    int seat_maker;
    SeatManager(int n) {
        seat_maker = 1;
    }
    
    int reserve() {
        if(!pq.empty()){
           int seat = pq.top();
            pq.pop();
            return seat;
        }
        int  seat = seat_maker;
        seat_maker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */