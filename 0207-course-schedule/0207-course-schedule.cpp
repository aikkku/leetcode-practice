class Solution {
public:
    unordered_map<int, vector<int>> courses;
    unordered_map<int, int> studying;
    int total = 0;

    bool study(int course) {
        if(courses.find(course) == courses.end()) {
            courses[course] = {course};
            studying[course] = 2;
            total ++;
            return 1;
        }
        if(studying.find(course) == studying.end()){
            studying[course] = 1;
            for(int pre : courses[course]) {
                if(!study(pre)) {
                    return false;
                }
            }

            studying[course] = 2;
            total ++;
            return 1;
            
        } else {
            if(studying[course] == 2) {
                return 1;
            }
            return 0;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(vector<int> p : prerequisites) {
            courses[p[0]].push_back(p[1]);
        }

        for(vector<int> p : prerequisites) {
            study(p[0]);
            if(total >= numCourses) return true;
        }
        if(courses.size() == total) {
            return true;
        }
        return false;
    }
};
