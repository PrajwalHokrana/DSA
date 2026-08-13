class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> s;//value,span
    int next(int price) {
        int span=1;
        if(!s.empty())
        {
            while(!s.empty() && s.top().first<=price)
            {
                span+=s.top().second;
                s.pop();
            }
        }
        s.push({price,span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */