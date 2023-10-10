#include <bits/stdc++.h>
using namespace std;

struct Nhanvien
{
    char manv[10];
    char hodem[15];
    char ten[10];
    char gioitinh[10];
    double hesoluong;
};

struct Node
{
    Nhanvien infor;
    Node *next;
};

typedef Node *Tro;

void makeEmpty(Tro &L)
{
    L = NULL;
}

int Empty(Tro L)
{
    return L == NULL;
}

void nhap1NV(Nhanvien &nv)
{
    cout << "Nhap ma NV: ";
    fflush(stdin);
    gets(nv.manv);
    cout << "Ho dem: ";
    fflush(stdin);
    gets(nv.hodem);
    cout << "Ten: ";
    fflush(stdin);
    gets(nv.ten);
    cout << "Gioi tinh: ";
    fflush(stdin);
    gets(nv.gioitinh);
    cout << "He so luong: ";
    cin >> nv.hesoluong;
}

void nhapDSNV(Tro &L, int n)
{
    makeEmpty(L);
    Nhanvien x;
    int i = 0;
    Tro P, Q;
    while (i < n)
    {
        cout << "Nhan vien thu " << i + 1 << endl;
        nhap1NV(x);
        P = new Node;
        P->infor = x;
        P->next = NULL;
        if (L == NULL)
        {
            L = P;
        }
        else
        {
            Q->next = P;
        }
        Q = P;
        i++;
    }
}

void hienthiDS(Tro L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong\n";
    }
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma CB";
    cout << setw(25) << "Ho va ten";
    cout << setw(12) << "Gioi tinh";
    cout << setw(15) << "He so luong" << endl;
    Tro Q = L;
    int i = 0;
    while (Q != NULL)
    {
        Nhanvien x = Q->infor;
        cout << setw(5) << (1 + i);
        cout << setw(10) << x.manv;
        cout << setw(17) << x.hodem;
        cout << setw(8) << x.ten;
        cout << setw(12) << x.gioitinh;
        cout << setw(10) << x.hesoluong << endl;
        Q = Q->next;
        i++;
    }
}

// Tim kiem nhan vien co ma mhap vao tu ban phim
Tro search(Tro L, char Ma[10])
{
    Tro Q = L;
    while (Q != NULL && strcmp(Q->infor.manv, Ma) != 0)
    {
        Q = Q->next;
    }
    return Q;
}
// Hien thi thong tin nhan vien co ma nhap vao vua tim duoc
void TimMaNV(Tro &L, char ma[])
{
    int i = 0;
    Tro T = search(L, ma);
    if (T == NULL)
    {
        cout << "Khong ton tai nhan vien co ma nhap trong danh sach\n";
        return;
    }
    else
    {
        cout << "Thong tin nhan vien co ma vua nhap\n";
        cout << setw(10) << "Ma NV";
        cout << setw(25) << "Ho va ten";
        cout << setw(12) << "Gioi tinh";
        cout << setw(15) << "He so luong" << endl;
        Nhanvien x = T->infor;
        if (strcmp(x.manv, ma) == 0)
        {
            cout << setw(10) << x.manv;
            cout << setw(17) << x.hodem;
            cout << setw(8) << x.ten;
            cout << setw(12) << x.gioitinh;
            cout << setw(10) << x.hesoluong << endl;
        }
    }
}

// Xoa nhan vien dung truoc nhan vien vua tim duoc
void xoaTruoc(Tro &L, char ma[])
{
    Tro T = search(L, ma);
    if (T == NULL)
    {
        cout << "Khong tim thay nhan vien co ma da nhap\n";
        return;
    }
    else
    {
        Tro Q = L;
        while (Q != NULL && Q->next != T)
        {
            Q = Q->next;
            Tro M = L;
            while (M != NULL && M->next != Q)
            {
                M = M->next;
            }
            M->next = T;
        }
        delete Q;
    }
}

// Chen nhan vien moi sau nhan vien vua tim duoc
void chenSau(Tro &L, char ma[])
{
    Tro T = search(L, ma);
    if (T == NULL)
    {
        cout << "Khong tim thay nhan vien co ma da nhap\n";
        return;
    }

    Tro P = new Node;
    Nhanvien x;
    cout << "Nhap thong tin nhan vien bo sung\n";
    nhap1NV(x);
    P->infor = x;
    P->next = T->next;
    T->next = P;

    cout << "Danh sach da bo sung\n";
    hienthiDS(L);
}

int main()
{
    Tro L;
    int n;
    do
    {
        cout << "Nhap tu 3 can bo tro len: ";
        cin >> n;
    } while (n < 3);
    nhapDSNV(L, n);
    cout << "============================== DANH SACH NHAN VIEN DA NHAP =================================\n";
    hienthiDS(L);
    cout << "============================================================================================\n";
    char ma[10];
    cout << "\nNhap ma nhan vien can tim: ";
    fflush(stdin);
    gets(ma);
    cout << "============================ TIM KIEM NHAN VIEN CO MA VUA NHAP =============================\n";
    TimMaNV(L, ma);
    cout << "============================================================================================\n";
    cout << "======================= XOA NHAN VIEN TRUOC NHAN VIEN CO MA VUA NHAP =======================\n";
    xoaTruoc(L, ma);
    hienthiDS(L);
    cout << "============================================================================================\n";
    cout << "===================== CHEN THEM NHAN VIEN SAU NHAN VIEN CO MA VUA NHAP =====================\n";
    chenSau(L, ma);
    cout << "============================================================================================\n";
}