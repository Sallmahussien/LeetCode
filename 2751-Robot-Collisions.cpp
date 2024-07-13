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
                bool is_collide = false;
                while (!stk.empty() && stk.top().dir == 'R') {
                    Robot& top_robot = stk.top();
                    if (robot.health > top_robot.health) {
                        robot.health--;
                        stk.pop();
                    } else if (robot.health == top_robot.health) {
                        stk.pop();
                        is_collide = true;
                        break;
                    } else {
                        top_robot.health--;
                        is_collide = true;
                        break;
                    }
                }
                if (!is_collide) stk.push(robot);
            }
        }

        vector<Robot> survivors;

        while (!stk.empty()) {
            Robot top_robot = stk.top();
            stk.pop();
            survivors.push_back(top_robot);
        }

        sort(survivors.begin(), survivors.end(), compare_idx);

        vector<int> res;
        for (auto survivor : survivors) {
            res.push_back(survivor.health);
        }

        return res;

    }
};