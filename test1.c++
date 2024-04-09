#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CharStack
{
private:
    stack<char> s;

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

bool Check(string s)
{
    CharStack S;
    bool valid = true;
    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (c == '(')
        {
            S.push(c);
        }
        else if (c == ')')
        {
            if (S.isEmpty)
            {
                valid = false;
                break;
            }
            else
                S.pop();
        }
    }
    if (!S.isEmpty)
    {
        valid = false
    }
    return valid;
}

int main()
{
    char choice;
    do
    {
        cout << "Choice Option: \n";
        cout << "1. Check Stack:\n";
        cout << "2. Check Expresion \n";
        cout << "3. Out\n";
        cout << "Your choice:";
        cin >> choice;
        if (choice == "1")
        {
            string input;
            cout << "Enter Stack: ";
            cin >> input;

            CharStack S;
            for (char c : input)
            {
                S.push(c);
            }

            cout << "Stack: " while (!S.isEmpty())
            {
            }
        }

    } while (true);
}