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
            if (S.isEmpty())
            {
                valid = false;
                break;
            }
            else
            {
                S.pop();
            }
        }
    }
    if (!S.isEmpty())
    {
        valid = false;
    }

    return valid;
}

int main()
{
    char choice;
    do
    {
        cout << "\nChọn chức năng:\n";
        cout << "1. Thử nghiệm stack\n";
        cout << "2. Kiểm tra biểu thức\n";
        cout << "3. Out\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        if (choice == '1')
        {
            string input;
            cout << "Nhập giá trị để đưa vào Stack: ";
            cin >> input;

            CharStack S;
            for (char c : input)
            {
                S.push(c);
            }

            cout << "Kết quả sau khi pop từ Stack: ";
            while (!S.isEmpty())
            {
                cout << S.pop();
            }
            cout << endl;
        }
        else if (choice == '2')
        {
            string input;
            cout << "Nhập biểu thức: ";
            cin.ignore();
            getline(cin, input);

            cout << "Biểu thức là: " << (Check(input) ? "hợp lệ" : "không hợp lệ") << endl;
        }
        else if (choice == '3')
        {
            break;
        }
        else
        {
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (true);

    cout << "Kết thúc chương trình.\n";
    return 0;
}
