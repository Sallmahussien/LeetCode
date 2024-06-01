class Solution {
private:
    bool isPos(int num) {
        return num > 0;
    }

    bool haveSameSigns (int num1, int num2) {
        return (num1 > 0 && num2 > 0) || (num1 < 0 && num2 < 0);
    } 

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int asteroid: asteroids) {
            if (res.empty() || isPos(asteroid) || haveSameSigns(asteroid, res.back())) {
                res.push_back(asteroid);
            } else {
                // collision occurred
                if (abs(asteroid) == abs(res.back())) res.pop_back();
                else if (abs(asteroid) < abs(res.back())) continue;
                else {
                    int top;
                    while (!res.empty() && !haveSameSigns(asteroid, res.back()) && abs(asteroid) >= abs(res.back())) {
                        top = res.back();
                        res.pop_back();
                        if (abs(top) == abs(asteroid)) break;
                    }

                    if (!haveSameSigns(top, asteroid) && abs(top) == abs(asteroid)) continue;

                    if (res.empty() || (!res.empty() && haveSameSigns(asteroid, res.back()))) {
                        res.push_back(asteroid);
                    }
                }
                
            }
        }

        return res; 
    }
};