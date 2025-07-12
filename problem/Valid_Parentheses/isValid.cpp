class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s)
        {
            if (mapping.find(c) != mapping.end())
            {
                if (st.empty() || st.top() != mapping[c])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }

    bool isValid_optimized(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
