class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1;
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        vector<int> od, ev;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2)
                od.push_back(nums1[i]);
            else
                ev.push_back(nums1[i]);
        }
        bool cev = true, cod = true;
        for (auto x : nums1) {
            if (x % 2) {
                if (od.empty() || od[0] >= x) {
                    cev = false;
                    break;
                }
            }
        }
        if (od.empty())
            cod = false;
        else {
            int mn = od[0];
            for (auto x : nums1) {
                if (x % 2 == 0) {
                    if (mn >= x) {
                        cod = false;
                        break;
                    }
                }
            }
        }
        return cev || cod;
    }
};