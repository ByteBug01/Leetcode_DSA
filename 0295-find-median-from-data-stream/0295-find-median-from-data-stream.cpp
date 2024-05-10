class MedianFinder {
public:

//declaretion of priority_queues
 priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) { //compare if num > top of left_max_heap then inserted to min_heap
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        
        
       //max_heap ka size always 1 greater rkho otherwise dono heaps ki size equal
        
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            //even number of elements honge
            
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        
        //else odd number of elemenes honge
        return left_max_heap.top();
    }




};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */