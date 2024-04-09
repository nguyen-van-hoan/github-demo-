#include <stdio.h>

#define MAX 100

void Nhap(int A[], int *n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; ++i)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &A[i]);
    }
}

void Xuat(int A[], int n)
{
    printf("Mang vua nhap la: ");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
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
    printf("Cac phan tu trong khoang %d va %d la: ", x, y);
    for (int i = 0; i < n; ++i)
    {
        if (A[i] >= x && A[i] <= y)
        {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
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

void Chen(int x, int p, int A[], int *n)
{
    if (p < 0 || p > *n)
    {
        printf("Vi tri chen khong hop le.\n");
        return;
    }
    for (int i = *n; i > p; --i)
    {
        A[i] = A[i - 1];
    }
    A[p] = x;
    ++*n;
}

void Xoa(int p, int A[], int *n)
{
    if (p < 0 || p >= *n)
    {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }
    for (int i = p; i < *n - 1; ++i)
    {
        A[i] = A[i + 1];
    }
    --*n;
}

int main()
{
    int A[MAX], n;
    Nhap(A, &n);
    Xuat(A, n);

    printf("Tong cac phan tu trong mang: %d\n", Tong(A, n));
    printf("Trung binh cong cac phan tu chan trong mang: %.2f\n", TBCChan(A, n));
    printf("So luong phan tu le trong mang: %d\n", DemLe(A, n));

    int x, y;
    printf("Nhap x va y: ");
    scanf("%d %d", &x, &y);
    inXY(A, n, x, y);

    int val;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &val);
    int pos = TimKiem(val, A, n);
    if (pos != -1)
    {
        printf("Gia tri %d duoc tim thay tai vi tri %d\n", val, pos);
    }
    else
    {
        printf("Gia tri %d khong duoc tim thay trong mang.\n", val);
    }

    int p;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &val);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &p);
    Chen(val, p, A, &n);
    Xuat(A, n);

    printf("Nhap vi tri can xoa: ");
    scanf("%d", &p);
    Xoa(p, A, &n);
    Xuat(A, n);

    return 0;
}
