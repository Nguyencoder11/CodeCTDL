#include <bits/stdc++.h>
using namespace std;

// Khai bao cau truc Hang
struct Hang
{
    char mahang[10];
    char tenhang[20];
    char dvtinh[10];
    long dongia;
    int soluong;
};

// Khai bao kieu du lieu cho 1 Node
struct Node
{
    Hang infor;
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

// Ham nhap thong tin cho mot hang
void nhap_hang(Hang &h)
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
    gets(h.dvtinh);
    cout << "Don gia: ";
    cin >> h.dongia;
    cout << "So luong: ";
    cin >> h.soluong;
}

// Nhap danh sach hang
void nhap_ds(TRO &L)
{
    tao_rong(L);
    Hang h;
    int i = 1;
    TRO Q, P;
    do
    {
        cout << "Nhap hang thu " << i << endl;
        nhap_hang(h);
        // Neu mahang = *** thi ket thuc nhap
        if (strcmp(h.mahang, "***") == 0)
        {
            return;
        }
        P = new Node;
        P->infor = h;
        P->next = NULL;
        if (L == NULL)
            L = P;
        else
            Q->next = P;
        Q = P;
        i++;
    } while (1);
}

// Xac dinh do dai danh sach
int listSize(TRO L)
{
    int n = 0;
    TRO Q = L;
    while (Q != NULL)
    {
        Q = Q->next;
        n++;
    }
    return n;
}

// Hien thi danh sach hang
void hienthi_ds(TRO L)
{
    if (L == NULL)
    {
        cout << "Danh sach rong\n";
        return;
    }
    else
    {
        cout << setw(5) << "STT";
        cout << setw(10) << "Ma hang";
        cout << setw(20) << "Ten hang";
        cout << setw(10) << "DV Tinh";
        cout << setw(10) << "Don gia";
        cout << setw(10) << "So luong";
        cout << setw(15) << "Thanh tien" << endl;
        TRO Q = L;
        int i = 0;
        while (Q != NULL)
        {
            Hang h = Q->infor;
            cout << setw(5) << (1 + i);
            cout << setw(10) << h.mahang;
            cout << setw(20) << h.tenhang;
            cout << setw(10) << h.dvtinh;
            cout << setw(10) << h.dongia;
            cout << setw(10) << h.soluong;
            cout << setw(15) << (h.dongia * h.soluong) << endl;
            Q = Q->next;
            i++;
        }
    }
}

// Xoa phan tu thu 3 trong danh sach
void SearchElem3(TRO &L, int pos)
{
    if (L == NULL)
    {
        cout << "Khong ton tai phan tu thu 3 can xoa\n";
    }
    TRO Q = L;
    int d = 1;
    while (Q != NULL && d < pos - 1)
    {
        Q = Q->next;
        d++;
    }
    if (d)
    {
        TRO T;
        T = Q->next;
        Q->next = T->next;
        delete T;
    }
    cout << "Danh sach da xoa phan tu thu 3\n";
    hienthi_ds(L);
}

// Chen hang hoa (H2007, Phan, Hop, 3000, 15, 45000) vao dau danh sach
void firstAdd(TRO &L)
{
    Hang x;
    strcpy(x.mahang, "H2007");
    strcpy(x.tenhang, "Phan");
    strcpy(x.dvtinh, "Hop");
    x.dongia = 3000;
    x.soluong = 15;
    TRO P = new Node;
    P->infor = x;
    P->next = L;
    L = P;
}

// Sap xep giam theo thanh tien bang bubble sort
void GiamThanhTien(TRO &L)
{
    Hang tg;
    TRO Q, R;
    R = L;
    while (R->next != NULL)
    {
        Q = R->next;
        while (Q != NULL)
        {
            if (Q->infor.soluong * Q->infor.dongia > R->infor.soluong * R->infor.dongia)
            {
                tg = Q->infor;
                Q->infor = R->infor;
                R->infor = tg;
            }
            Q = Q->next;
        }
        R = R->next;
    }
}

int main()
{
    TRO L;
    cout << "Nhap danh sach hang\n";
    nhap_ds(L);
    cout << "=========================== DANH SACH HANG VUA NHAP ============================\n";
    hienthi_ds(L);
    cout << "================================================================================\n";

    cout << "====================== XOA HANG HOA THU 3 TRONG DANH SACH ======================\n";
    SearchElem3(L, 3);
    cout << "================================================================================\n";

    cout << "========================= CHEN HANG HOA VAO DANH SACH ==========================\n";
    firstAdd(L);
    hienthi_ds(L);
    cout << "================================================================================\n";

    cout << "====================== SAP XEP DANH SACH THEO THANH TIEN =======================\n";
    GiamThanhTien(L);
    hienthi_ds(L);
    cout << "================================================================================\n";
}