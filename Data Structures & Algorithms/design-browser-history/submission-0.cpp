class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        m_history.push_back(homepage);
        m_idx = 0;
    }
    
    void visit(string url) {
        // this will become the new tail
        m_history.resize(m_idx + 1);
        m_history.push_back(url);
        m_idx = (int)m_history.size() - 1;
    }
    
    string back(int steps) {
        if(steps > m_idx)
            m_idx = 0;
        else
            m_idx -= steps;

        return m_history.at(m_idx);
    }
    
    string forward(int steps) {
        if(steps > (int)m_history.size() - 1 - m_idx)
            m_idx = (int)m_history.size() - 1;
        else
            m_idx += steps;
        return m_history.at(m_idx);
    }
private:
    std::vector<string> m_history;
    int m_idx;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */