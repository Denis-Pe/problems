class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maximum = 0;
        int currAlt = 0;

        for (auto g : gain) {
            currAlt += g;
            if (currAlt > maximum) {
                maximum = currAlt;
            }
        }

        return maximum;
    }
};
