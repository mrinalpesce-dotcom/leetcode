class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        // lambda function for custom sorting
        auto lamda = [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        };

        // sort tasks based on (minimum - actual)
        sort(tasks.begin(), tasks.end(), lamda);

        long long ans = 0;
        long long energy = 0;

        for (int i = 0; i < tasks.size(); i++) {

            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            // increase energy if current energy is less
            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            // perform current task
            energy -= actual;
        }

        return (int)ans;
    }
};