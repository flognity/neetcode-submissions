class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int failedAttempts = 0;
        while ( sandwiches.size() > 0 
        &&      students.size() > 0 
        // exit condition when no sandwitch matches any student anymore
        &&      failedAttempts < students.size() ) {
            int currentSandwich = sandwiches.at(0);
            int currentStudent  = students.at(0);

            // dequeue the student
            for(int i = 0; i < students.size() - 1; ++i) {
                students.at(i) = students.at(i + 1);
            }

            if(currentSandwich == currentStudent)
            {
                // remove the student and sandwich from the queue
                students.pop_back();

                for(int i = 0; i < sandwiches.size() - 1; ++i) {
                    sandwiches.at(i) = sandwiches.at(i + 1);
                }
                sandwiches.pop_back();

                // reset the attempts
                failedAttempts = 0;
            }
            else
            {
                // sandwiches remain the same
                // student queues at the back
                students.at(students.size() - 1) = currentStudent;
                ++failedAttempts;
            }
        }

        return students.size();
    }
};