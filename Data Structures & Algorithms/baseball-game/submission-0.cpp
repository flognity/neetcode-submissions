class Solution {
public:
    int calPoints(vector<string>& operations) {
        // loop through the entries and parse each operation
        for (size_t i = 0; i < operations.size(); i++)
        {
            string current = operations.at(i);
            // parse the operation
            if (current == "+")
            {
                int size = m_scores.size();
                if(size > 1)
                    m_scores.push_back(m_scores.back() + m_scores.at(size - 2));
            }
            else if (current == "D")
            {
                if(m_scores.size() > 0)
                    m_scores.push_back(m_scores.back() * 2);
            }
            else if (current == "C")
            {
                m_scores.pop_back();
            }
            else
            {
                try
                {
                    int score = std::stoi(current);
                    m_scores.push_back(score);
                }
                catch(...)
                {
                    std::cerr << "Can't parse string to integer: " << current << "\n";
                }
            }
        }

        // sum up all scores
        int sum = 0;
        for (size_t i = 0; i < m_scores.size(); i++)
            sum += m_scores.at(i);

        return sum;
    }

private:
    std::vector<int> m_scores;
};