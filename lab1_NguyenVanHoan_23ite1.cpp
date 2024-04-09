#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define MAX 10000
// nhap mang
void Nhap(int A[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 10;
    }
}
// in mang
void In(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
// tinh tong gia tri cac phan tu trong mang
int Tong(int A[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += A[i];
    }

    return result;
}

// tinh trung binh cong so chan trong mang
float TBCChan(int A[], int n)
{
    int dem = 0;
    float result = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            result += A[i];
            dem += 1;
        }
    }
    float ketQua = static_cast<float>(result / dem);

    return ketQua;
}

// dem so luong so le trong mang
int DemLe(int A[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if ((A[i] % 2) != 0)
        {
            dem += 1;
        }
    }
    return dem;
}
// in phan tu nam trong index tu x den y
void inPhanTuNamTrongXY(int A[], int n, int x, int y)
{
    cout << "Gia tri tu x den y la: ";
    for (int i = x; i <= y; i++)
    {
        cout << A[i] << " ";
    }
}

// tin kiem gia tri x
int TimKiem(int A[], int n, int userNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (userNumber == A[i])
        {
            return i;
        }
    }
}
// chen x vao vi tri p
void Chen(int x, int p, int A[], int *n)
{
    for (int i = *n; i > p; i--)
    {
        A[i] = A[i - 1];
    }
    A[p] = x;

    cout << "Mang moi hien tai: ";
    for (int j = 0; j <= *n; j++)
    {
        cout << A[j];
    }
}
// xoa phan tu o vi tri p
void Xoa(int p, int A[], int *n)
{
    // kiem tra xem vi tri p co hop le voi mang hay khong
    if (p >= *n)
    {
        cout << "Vi tri khong hop le";
        return;
    }
    for (int i = p; i < *n; i++)
    {
        A[i] = A[i + 1];
    }

    cout << "Mang moi hien tai: ";
    for (int i = 0; i < *n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    int n = 5;
    int A[MAX];

    //	cout <<"Nhap mang gom 5 phan tu:  ";
    Nhap(A, n);

    cout << endl
         << "Mang hien tai la: ";
    In(A, n);

    cout << endl
         << "So luong so le la: " << DemLe(A, n) << endl;

    cout << "Trung binh cong chan: " << TBCChan(A, n) << endl;

    inPhanTuNamTrongXY(A, n, 2, 4);
    cout << endl;

    cout << "Gia tri 5 o vi tri:  " << TimKiem(A, n, 5) << endl;

    cout << "Chen 8 vao index 3----------------";
    Chen(8, 3, A, &n);
    cout << endl;

    cout << "Xoa gia tri o index 2:--------------- ";
    Xoa(2, A, &n);
}
