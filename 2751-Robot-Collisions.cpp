class Solution {
private:
    struct Robot {
        int idx;
        int pos;
        int health;
        char dir;
    };

    static bool compare_postions (Robot& a, Robot& b) {
        return a.pos < b.pos;
    }

    static bool compare_idx(Robot& a, Robot& b) {
        return a.idx < b.idx;
    }

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        for (int i = 0; i < n; i++) {
            robots[i] = {i, positions[i], healths[i], directions[i]};
        }

        sort(robots.begin(), robots.end(), compare_postions);



        stack<Robot> stk;

        for (auto robot : robots) {
            cout << robot.pos << endl;
            if (robot.dir == 'R') stk.push(robot);
            else {
                if (stk.empty() || stk.top().dir == 'L') stk.push(robot);
                else if (robot.health < stk.top().health) stk.top().health--;
                else if (robot.health == stk.top().health) stk.pop();
                else {
                    bool isCollide = false;
                    while (!stk.empty() && robot.dir != stk.top().dir) {
                        if (robot.health < stk.top().health) {
                            isCollide = true;
                            stk.top().health--;
                            break;
                        }

                        if (robot.health == stk.top().health) {
                            stk.pop();
                            isCollide = true;
                            break;
                        }

                        robot.health--;
                        stk.pop();  
                    }

                    if (!isCollide) stk.push(robot);
                }
            }
        }

        vector<int> res;
        vector<Robot> robot_vec;

        while (!stk.empty()) {
            Robot top_robot = stk.top();
            stk.pop();
            robot_vec.push_back(top_robot);
        }

        sort(robot_vec.begin(), robot_vec.end(), compare_idx);

        for (auto robot : robot_vec) {
            res.push_back(robot.health);
        }

        return res;

    }
};