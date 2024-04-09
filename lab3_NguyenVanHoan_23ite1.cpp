#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    float math_mark;
    float physics_mark;
    float language_mark;
};

void Input(Student A[], int n)
{
    cout << "Enter students' information:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> A[i].name;
        cout << "Math mark: ";
        cin >> A[i].math_mark;
        cout << "Physics mark: ";
        cin >> A[i].physics_mark;
        cout << "Language mark: ";
        cin >> A[i].language_mark;
    }
}

void Output(Student A[], int n)
{
    cout << "Student list:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Name: " << A[i].name << ", Math: " << A[i].math_mark
             << ", Physics: " << A[i].physics_mark << ", Language: " << A[i].language_mark << endl;
    }
}

void Insert(Student X, int p, Student A[], int *n)
{
    if (p < 0 || p > *n)
    {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = *n; i > p; --i)
    {
        A[i] = A[i - 1];
    }
    A[p] = X;
    (*n)++;
    cout << "Student inserted at position " << p << ".\n";
}

void Search(string x, Student A[], int n)
{
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (A[i].name == x)
        {
            found = true;
            cout << "Student found at position " << i << ".\n";
            cout << "Name: " << A[i].name << ", Math: " << A[i].math_mark
                 << ", Physics: " << A[i].physics_mark << ", Language: " << A[i].language_mark << endl;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
}

int main()
{
    const int maxSize = 100; // Số lượng tối đa sinh viên
    Student students[maxSize];
    int numStudents = 0;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    if (numStudents <= 0 || numStudents > maxSize)
    {
        cout << "Invalid number of students.\n";
        return 1;
    }

    Input(students, numStudents);

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insert a student\n";
        cout << "2. Search for a student\n";
        cout << "3. Display student list\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter information for the new student:\n";
            Student newStudent;
            cout << "Name: ";
            cin >> newStudent.name;
            cout << "Math mark: ";
            cin >> newStudent.math_mark;
            cout << "Physics mark: ";
            cin >> newStudent.physics_mark;
            cout << "Language mark: ";
            cin >> newStudent.language_mark;
            int positionToInsert;
            cout << "Enter position to insert: ";
            cin >> positionToInsert;
            Insert(newStudent, positionToInsert, students, &numStudents);
            break;
        }
        case 2:
        {
            string searchName;
            cout << "Enter the name of the student to search for: ";
            cin >> searchName;
            Search(searchName, students, numStudents);
            break;
        }
        case 3:
            Output(students, numStudents);
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
