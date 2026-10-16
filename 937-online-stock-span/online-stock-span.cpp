class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {
    }

    int next(int price) {
        prices.push_back(price);

        int n = prices.size();
        int span = 1;

        int prev = n - 2;

        while (prev >= 0 && prices[prev] <= price) {
            span++;
            prev--;
        }

        return span;
    }
};