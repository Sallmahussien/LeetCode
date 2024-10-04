class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        sort(skill.begin(), skill.end());

        int l = 0, r = skill.size()-1;
        int team_sum = skill[l] + skill[r];
        while (l < r) {
            if (skill[l] + skill[r] != team_sum) return -1;
            res += skill[l++] * skill[r--];    
        }

        return res;
        
    }
};