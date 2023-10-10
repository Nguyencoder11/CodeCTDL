#include <bits/stdc++.h>
using namespace std;

// Khai bao cau truc Canbo
struct Canbo
{
    char macb[10];
    char hodem[15];
    char ten[10];
    char gioitinh[12];
    int tuoi;
    float hsLuong;
    long luongCoBan;
};

// Khai bao kieu du lieu cho 1 Node
struct Node
{
    Canbo infor;
    Node *next;
};

// Dinh nghia con tro tro vao Node
typedef Node *TRO;

// Ham tao danh sach rong
void tao_rong(TRO &L)
{
    L = NULL;
}

// Ham kiem tra danh sach rong
int empty(TRO L)
{
    return L == NULL;
}

// Nhap thong tin cho mot can bo
void nhap1CB(Canbo &cb)
{
    cout << "Nhap ma can bo: ";
    fflush(stdin);
    gets(cb.macb);
    cout << "Ho dem: ";
    fflush(stdin);
    gets(cb.hodem);
    cout << "Ten: ";
    fflush(stdin);
    gets(cb.ten);
    cout << "Gioi tinh: ";
    fflush(stdin);
    gets(cb.gioitinh);
    cout << "Tuoi: ";
    cin >> cb.tuoi;
    cout << "He so luong: ";
    cin >> cb.hsLuong;
    cb.luongCoBan = cb.hsLuong * 1490000;
}

// nhap danh sach can bo
void nhapDS(TRO &L, int n)
{
    tao_rong(L);
    Canbo x;
    int i = 0;
    TRO Q, P;
    while (i < n)
    {
        cout << "Nhap can bo thu " << i + 1 << endl;
        nhap1CB(x);
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

// Hien thi danh sach can bo
void hienthiDS(TRO L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong" << endl;
        return;
    }
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma CB";
    cout << setw(25) << "Ho va ten";
    cout << setw(12) << "Gioi tinh";
    cout << setw(10) << "Tuoi";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Luong co ban" << endl;
    TRO Q = L;
    int i = 0;
    while (Q != NULL)
    {
        Canbo x = Q->infor;
        cout << setw(5) << (1 + i);
        cout << setw(10) << x.macb;
        cout << setw(17) << x.hodem;
        cout << setw(8) << x.ten;
        cout << setw(12) << x.gioitinh;
        cout << setw(10) << x.tuoi;
        cout << setw(10) << x.hsLuong;
        cout << setw(15) << x.luongCoBan << endl;
        Q = Q->next;
        i++;
    }
}

// Hien thi nhung can bo nu tuoi tu 50 tro xuong
void NuCB_Tuoi50(TRO L)
{
    int d = 0, i = 0;
    TRO T = L;
    while (T != NULL)
    {
        if (T->infor.tuoi <= 50 && strcmp(T->infor.gioitinh, "Nu") == 0)
        {
            d++;
        }
        T = T->next;
    }
    if (d != 0)
    {
        T = L;
        cout << setw(5) << "STT";
        cout << setw(10) << "Ma CB";
        cout << setw(25) << "Ho va ten";
        cout << setw(12) << "Gioi tinh";
        cout << setw(10) << "Tuoi";
        cout << setw(15) << "He so luong";
        cout << setw(15) << "Luong co ban" << endl;
        while (T != NULL)
        {
            Canbo x = T->infor;
            if (x.tuoi <= 50 && strcmp(x.gioitinh, "Nu") == 0)
            {
                cout << setw(5) << (1 + i);
                cout << setw(10) << x.macb;
                cout << setw(17) << x.hodem;
                cout << setw(8) << x.ten;
                cout << setw(12) << x.gioitinh;
                cout << setw(10) << x.tuoi;
                cout << setw(10) << x.hsLuong;
                cout << setw(15) << x.luongCoBan << endl;
                i++;
            }
            T = T->next;
        }
    }
    else
        cout << "Khong co can bo nu tuoi duoi 50\n";
}

// Hien thi can bo ten Tung trong danh sach
// Tim nhan vien ten Tung trong danh sach
TRO search(TRO L, char *ten)
{
    TRO Q = L;
    while (Q != NULL && strcmp(Q->infor.ten, ten) != 0)
    {
        Q = Q->next;
    }
    return Q;
}

void danhSach_Tung(TRO &L)
{
    TRO T = search(L, "Tung");
    if (T == NULL)
    {
        cout << "Khong co sinh vien ten Tung\n";
        return;
    }
    else
    {
        cout << "Can bo ten Tung dau tien\n";
        cout << setw(10) << "Ma CB";
        cout << setw(25) << "Ho va ten";
        cout << setw(12) << "Gioi tinh";
        cout << setw(10) << "Tuoi";
        cout << setw(15) << "He so luong";
        cout << setw(15) << "Luong co ban" << endl;
        Canbo x = T->infor;
        if (strcmp(x.ten, "Tung") == 0)
        {
            cout << setw(10) << x.macb;
            cout << setw(17) << x.hodem;
            cout << setw(8) << x.ten;
            cout << setw(12) << x.gioitinh;
            cout << setw(10) << x.tuoi;
            cout << setw(10) << x.hsLuong;
            cout << setw(15) << x.luongCoBan << endl;
        }
    }
}

// Them phan tu vao sau phan tu thu 3
TRO TimKiem3(TRO L)
{
    TRO P = L;
    int d = 1;
    while (P != NULL && d < 3)
    {
        P = P->next;
        d++;
    }
    return P;
}

void themSau3(TRO &L)
{
    TRO P = TimKiem3(L);
    if (P == NULL)
    {
        cout << "Danh sach khong du phan tu\n";
        return;
    }
    // Neu khong thi tao mot node moi
    TRO newNode = new Node;
    Canbo x;
    cout << "Nhap thong tin can bo can bo sung\n";
    nhap1CB(x);
    newNode->infor = x;
    newNode->next = P->next;
    P->next = newNode;

    cout << "Danh sach sau khi them\n";
    hienthiDS(L);
}

int main()
{
    TRO L;
    int n;
    do
    {
        cout << "Nhap so luong can bo: ";
        cin >> n;
    } while (n <= 0);
    nhapDS(L, n);
    cout << "=================================== DANH SACH VUA NHAP =====================================\n";
    hienthiDS(L);
    cout << "============================================================================================\n";

    cout << "============================= CAN BO NU TUOI TU 50 TRO XUONG ===============================\n";
    NuCB_Tuoi50(L);
    cout << "============================================================================================\n";

    cout << "============================ CAN BO TEN TUNG TRONG DANH SACH ===============================\n";
    danhSach_Tung(L);
    cout << "============================================================================================\n";

    cout << "============================== THEM VAO SAU PHAN TU THU 3 ==================================\n";
    themSau3(L);
    cout << "============================================================================================\n";
}