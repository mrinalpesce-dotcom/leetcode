class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        // Remove previous prices that are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Store current price and its span
        st.push({price, span});

        return span;
    }
};