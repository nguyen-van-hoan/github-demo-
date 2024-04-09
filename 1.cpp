#include <iostream>
using namespace std;

const int MAX = 100;

void Nhap(int A[], int &n)
{
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> A[i];
    }
}

void Xuat(int A[], int n)
{
    cout << "Mang vua nhap la: ";
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int Tong(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += A[i];
    }
    return sum;
}

float TBCChan(int A[], int n)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] % 2 == 0)
        {
            sum += A[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return (float)sum / count;
}

int DemLe(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

void inXY(int A[], int n, int x, int y)
{
    cout << "Cac phan tu trong khoang " << x << " va " << y << " la: ";
    for (int i = 0; i < n; ++i)
    {
        if (A[i] >= x && A[i] <= y)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

int TimKiem(int x, int A[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (A[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Chen(int x, int p, int A[], int &n)
{
    if (p < 0 || p > n)
    {
        cout << "Vi tri chen khong hop le." << endl;
        return;
    }
    for (int i = n; i > p; --i)
    {
        A[i] = A[i - 1];
    }
    A[p] = x;
    ++n;
}

void Xoa(int p, int A[], int &n)
{
    if (p < 0 || p >= n)
    {
        cout << "Vi tri xoa khong hop le." << endl;
        return;
    }
    for (int i = p; i < n - 1; ++i)
    {
        A[i] = A[i + 1];
    }
    --n;
}

int main()
{
    int A[MAX], n;
    Nhap(A, n);
    Xuat(A, n);

    cout << "Tong cac phan tu trong mang: " << Tong(A, n) << endl;
    cout << "Trung binh cong cac phan tu chan trong mang: " << TBCChan(A, n) << endl;
    cout << "So luong phan tu le trong mang: " << DemLe(A, n) << endl;

    int x, y;
    cout << "Nhap x va y: ";
    cin >> x >> y;
    inXY(A, n, x, y);

    int val;
    cout << "Nhap gia tri can tim kiem: ";
    cin >> val;
    int pos = TimKiem(val, A, n);
    if (pos != -1)
    {
        cout << "Gia tri " << val << " duoc tim thay tai vi tri " << pos << endl;
    }
    else
    {
        cout << "Gia tri " << val << " khong duoc tim thay trong mang." << endl;
    }

    int p;
    cout << "Nhap gia tri can chen: ";
    cin >> val;
    cout << "Nhap vi tri can chen: ";
    cin >> p;
    Chen(val, p, A, n);
    Xuat(A, n);

    cout << "Nhap vi tri can xoa: ";
    cin >> p;
    Xoa(p, A, n);
    Xuat(A, n);

    return 0;
}
