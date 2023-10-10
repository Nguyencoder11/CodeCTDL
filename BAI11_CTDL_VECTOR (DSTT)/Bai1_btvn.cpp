#include <bits/stdc++.h>
using namespace std;
#define max 100
struct Hang
{
    char mahang[10], tenhang[15], donvitinh[10];
    int dongia;
    int soluong;
};

struct List
{
    int count;
    Hang e[max];
};

// Khoi tao danh sach rong
void taorong(List &L)
{
    L.count = -1;
}

// Kiem tra danh sach day
int full(List L)
{
    return L.count == max - 1;
}

// Kiem tra danh sach rong
int empty(List L)
{
    return L.count == -1;
}

// Them hang vao cuoi danh sach
int Add(List &L, Hang x)
{
    if (full(L))
        return 0;
    else
    {
        L.count++;
        L.e[L.count] = x;
        return 1;
    }
}

// Nhap thong tin cua mot hang
void nhaphang(Hang &h)
{
    cout << "Nhap ma hang: ";
    fflush(stdin);
    gets(h.mahang);
    if (strcmp(h.mahang, "***") == 0)
        return;
    cout << "Ten hang: ";
    fflush(stdin);
    gets(h.tenhang);
    cout << "Don vi tinh: ";
    fflush(stdin);
    gets(h.donvitinh);
    cout << "Don gia: ";
    cin >> h.dongia;
    cout << "So luong: ";
    cin >> h.soluong;
}

// Nhap danh sach cac hang
void nhapDSSV(List &L)
{
    taorong(L);
    Hang x;
    int i = 1;
    do
    {
        cout << "Nhap hang thu " << i << endl;
        nhaphang(x);
        if (strcmp(x.mahang, "***") == 0)
            return;
        if (!Add(L, x))
            return;
        i++;
    } while (1);
}

// hien thi danh sach
void hienthiDS(List L)
{
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma hang";
    cout << setw(15) << "Ten hang";
    cout << setw(15) << "Don vi tinh";
    cout << setw(10) << "Don gia";
    cout << setw(10) << "So luong";
    cout << setw(12) << "Thanh tien" << endl;
    for (int i = 0; i <= L.count; i++)
    {
        cout << setw(5) << (1 + i);
        cout << setw(10) << L.e[i].mahang;
        cout << setw(15) << L.e[i].tenhang;
        cout << setw(15) << L.e[i].donvitinh;
        cout << setw(10) << L.e[i].dongia;
        cout << setw(10) << L.e[i].soluong;
        cout << setw(12) << (L.e[i].dongia * L.e[i].soluong) << endl;
    }
}

/* Xoa phan tu thu 3 trong danh sach */
int xoaE3(List &L)
{
    if (L.count < 2)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i <= L.count; i++)
        {
            L.e[i] = L.e[i + 1];
        }
        L.count--;
        return 1;
    }
}

/* Chen hang hoa(2007, Phan, Hop, 3000, 15, 45000) vao dau danh sach */
void chanDauTien(List &L)
{
    if (full(L))
    {
        cout << "Khong the chen vao danh sach\n";
    }
    else
    {
        L.count++;
        for (int i = L.count; i >= 0; i--)
        {
            L.e[i] = L.e[i - 1];
        }
        strcpy(L.e[0].mahang, "2007");
        strcpy(L.e[0].tenhang, "Phan");
        strcpy(L.e[0].donvitinh, "Hop");
        L.e[0].dongia = 3000;
        L.e[0].soluong = 15;
        L.e[0].dongia *L.e[0].soluong;
        hienthiDS(L);
        cout << "Chen thanh cong\n";
    }
}

/* Sap xep theo chieu giam dan cua thanh tien bang bubble sort */
void sort_Money(List &L)
{
    for (int i = 0; i <= L.count; i++)
    {
        for (int j = L.count; j > i; j--)
        {
            if ((L.e[j].dongia * L.e[j].soluong) > (L.e[j - 1].dongia * L.e[j - 1].soluong))
            {
                Hang tg = L.e[j];
                L.e[j] = L.e[j - 1];
                L.e[j - 1] = tg;
            }
        }
    }
}

int main()
{
    List L;
    nhapDSSV(L);
    cout << "\n========================== DANH SACH HANG VUA NHAP ==========================\n";
    hienthiDS(L);
    cout << "=============================================================================\n";

    cout << "\n========================== XOA PHAN TU THU 3 ================================\n";
    if (xoaE3(L) == 1)
    {
        cout << "----->Xoa thanh cong\n";
        hienthiDS(L);
    }
    else
    {
        cout << "----->Khong co phan tu thu 3 trong danh sach.\n----->Xoa khong thanh cong\n";
    }
    cout << "=============================================================================\n";

    cout << "\n========================== CHEN HANG VAO DAU TIEN ===========================\n";
    chanDauTien(L);
    cout << "=============================================================================\n";

    sort_Money(L);
    cout << "\n========================== DANH SACH DUOC SAP XEP ===========================\n";
    hienthiDS(L);
    cout << "=============================================================================\n";
}