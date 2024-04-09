#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Định nghĩa char stack
class CharStack
{
private:
    stack<char> s;

public:
    // Thêm ký tự vào stack
    void Push(char x)
    {
        s.push(x);
    }

    // Lấy và loại bỏ ký tự khỏi stack
    char Pop()
    {
        char c = s.top();
        s.pop();
        return c;
    }

    // Kiểm tra xem stack có rỗng không
    bool IsEmpty()
    {
        return s.empty();
    }
};

// Hàm kiểm tra biểu thức hợp lệ
bool CheckExpression(string s)
{
    CharStack S;
    bool valid = true;

    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (c == '(')
        {
            S.Push(c);
        }
        else if (c == ')')
        {
            if (S.IsEmpty())
            {
                valid = false;
                break;
            }
            else
            {
                S.Pop();
            }
        }
    }

    if (!S.IsEmpty())
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
        cout << "\nChọn chức năng bạn muốn sử dụng:\n";
        cout << "1. Thử nghiệm stack (Nhập 's')\n";
        cout << "2. Kiểm tra biểu thức (Nhập 'b')\n";
        cout << "3. Thoát (Nhập 'q')\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        if (choice == 's')
        {
            // Test stack
            string input;
            cout << "Nhập giá trị để thêm vào stack: ";
            cin >> input;

            CharStack S;
            for (char c : input)
            {
                S.Push(c);
            }

            cout << "Kết quả sau khi pop từ stack: ";
            while (!S.IsEmpty())
            {
                cout << S.Pop();
            }
            cout << endl;
        }
        else if (choice == 'b')
        {
            // Test biểu thức
            string expression;
            cout << "Nhập biểu thức: ";
            cin.ignore(); // Đọc bỏ dấu newline từ lần nhập trước
            getline(cin, expression);

            cout << "Biểu thức vừa nhập là " << (CheckExpression(expression) ? "hợp lệ." : "không hợp lệ.") << endl;
        }
        else if (choice == 'q')
        {
            // Thoát chương trình
            break;
        }
        else
        {
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (true);

    cout << "Đã thoát chương trình.\n";

    return 0;
}
