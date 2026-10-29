class Solution {
public:
    bool isValid(string s) {
        // check the input for valid characters
        bool valid = isValidInput(s);
        // the first character has to be an opening brace
        if (!valid || !isOpening(s.at(0)))
            return false;

        std:vector<char> braceStack = {};
        braceStack.reserve(s.size() / 2 + 1);

        for(size_t i = 0; i < s.size(); i++)
        {
            char currentBrace = s.at(i);
            if(isOpening(currentBrace))
            {
                braceStack.push_back(currentBrace);
            }
            else if(braceStack.size() <= 0)
            {
                // closing braces received but no opening brace left to check
                valid = false;
                break;
            }
            else
            {
                // closing braces have to match the last one on the stack
                char lastOpeningBrace = braceStack.back();
                braceStack.pop_back();
                if (currentBrace != getMatchingClosingBrace(lastOpeningBrace))
                {
                    valid = false;
                    break;
                }
            }
        }
        
        // at the end, the stack should be empty, otherwise we would have remaining unclosed braces
        return valid && braceStack.size() == 0;
    }

    char getMatchingClosingBrace(char c)
    {
        switch(c)
        {
            case '(': return ')';
            case '[': return ']';
            case '{': return '}';
            default:  return ' '; 
        }
    }

    bool isOpening(char c)
    {
        return c == '(' ||  c == '[' || c == '{';
    }

    bool isValidInput(string s)
    {
        bool valid = true;
        for(const auto c: s)
        {
            if(c != '(' &&  c != '[' && c != '{'
            && c != ')' &&  c != ']' && c != '}')
            {
                valid = false;
                break;
            }
        }
        return valid;
    }
};
