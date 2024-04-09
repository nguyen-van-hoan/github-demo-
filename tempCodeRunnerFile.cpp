public:
    void push(char x)
    {
        s.push(x);
    }

    char pop()
    {
        char c = s.top();
        s.pop();
        return c;
    }

    bool isEmpty()
    {
        return s.empty();
    }
};