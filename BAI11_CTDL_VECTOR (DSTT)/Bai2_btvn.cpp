#include <bits/stdc++.h>
using namespace std;

#define max 100

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

struct List
{
    int count;
    Canbo cb[max];
};

// Tao danh sach rong
void tao_rong(List &L)
{
    L.count = -1;
}

// Kiem tra danh sach rong
int kt_rong(List L)
{
    return L.count == -1;
}

// Kiem tra danh sach day
int kt_day(List L)
{
    return L.count == max - 1;
}

// Nhap thong tin cho 1 can bo
void nhapCB(Canbo &cb)
{
    cin.ignore();
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

// Them can bo vao cuoi danh sach 
int Add(List &L, Canbo x)
{
    if (kt_day(L))
        return 0;
    else
    {
        L.count++;
        L.cb[L.count] = x;
        return 1;
    }
}

// Nhap danh sach gom n can bo
void nhapDSCB(List &L, int &n)
{
    tao_rong(L);
    Canbo x;
    for (int i = 0; i < n; i++)
    {
        cout << "Can bo " << i + 1 << endl;
        nhapCB(x);
        int result = Add(L, x);
        if (result == 0)
        {
            cout << "Danh sach da day, khong the them can bo moi.\n";
            break;
        }
    }
}

// Hien thi danh sach can bo
void hienthiDSCB(List L)
{
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma CB";
    cout << setw(25) << "Ho va ten";
    cout << setw(12) << "Gioi tinh";
    cout << setw(10) << "Tuoi";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Luong co ban" << endl;
    for (int i = 0; i <= L.count; i++)
    {
        cout << setw(5) << (1 + i);
        cout << setw(10) << L.cb[i].macb;
        cout << setw(17) << L.cb[i].hodem;
        cout << setw(8) << L.cb[i].ten;
        cout << setw(12) << L.cb[i].gioitinh;
        cout << setw(10) << L.cb[i].tuoi;
        cout << setw(10) << L.cb[i].hsLuong;
        cout << setw(15) << L.cb[i].luongCoBan << endl;
    }
}

// Danh sach nu can bo co tuoi <= 50
void CanBo50(List L)
{
    int d = 0;
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma CB";
    cout << setw(25) << "Ho va ten";
    cout << setw(12) << "Gioi tinh";
    cout << setw(10) << "Tuoi";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Luong co ban" << endl;
    for (int i = 0; i <= L.count; i++)
    {
        if (L.cb[i].tuoi <= 50 && ((strcmp(L.cb[i].gioitinh, "Nu") == 0) || (strcmp(L.cb[i].gioitinh, "nu") == 0)))
        {
            cout << setw(5) << (1 + i);
            cout << setw(10) << L.cb[i].macb;
            cout << setw(17) << L.cb[i].hodem;
            cout << setw(8) << L.cb[i].ten;
            cout << setw(12) << L.cb[i].gioitinh;
            cout << setw(10) << L.cb[i].tuoi;
            cout << setw(10) << L.cb[i].hsLuong;
            cout << setw(15) << L.cb[i].luongCoBan << endl;
            d++;
        }
    }
    if (d == 0)
    {
        cout << "Khong tim thay du lieu thoa man dieu kien\n";
    }
}

// Thong tin can bo ten "Tung"
void CanboTung(List L)
{
    int dem = 0;
    bool first = false;
    cout << setw(5) << "STT";
    cout << setw(10) << "Ma CB";
    cout << setw(25) << "Ho va ten";
    cout << setw(12) << "Gioi tinh";
    cout << setw(10) << "Tuoi";
    cout << setw(15) << "He so luong";
    cout << setw(15) << "Luong co ban" << endl;
    for (int i = 0; i <= L.count; i++)
    {
        if (strcmp(L.cb[i].ten, "Tung") == 0)
        {
            dem++;
            if (!first)
            {
                cout << setw(5) << (1 + i);
                cout << setw(10) << L.cb[i].macb;
                cout << setw(17) << L.cb[i].hodem;
                cout << setw(8) << L.cb[i].ten;
                cout << setw(12) << L.cb[i].gioitinh;
                cout << setw(10) << L.cb[i].tuoi;
                cout << setw(10) << L.cb[i].hsLuong;
                cout << setw(15) << L.cb[i].luongCoBan << endl;
                first = true;
            }
        }
    }
    if (dem == 0)
    {
        cout << "Khong ton tai can bo ten Tung trong danh sach\n";
    }
}

// Chen vao sau phan tu thu 3
int insert(List &L, int k)
{
    Canbo x;
    if (k <= L.count + 1 && k > 0 && !kt_day(L))
    {
        cout << "Nhap thong tin can bo can bo sung\n";
        nhapCB(x);
        for (int i = L.count; i >= k - 1; i--)
        {
            L.cb[i + 1] = L.cb[i];
        }
        L.count++;
        L.cb[k - 1] = x;
        return 1;
    }
    else
        return 0;
}

int main()
{
    List L;
    int n;
    cout << "So can bo: ";
    cin >> n;
    nhapDSCB(L, n);
    cout << "\n================================= DANH SACH HANG VUA NHAP ===================================\n";
    hienthiDSCB(L);
    cout << "=============================================================================================\n";

    cout << "\n================================= CAN BO NU TUOI DUOI 50 ====================================\n";
    CanBo50(L);
    cout << "=============================================================================================\n";

    cout << "\n================================= CAN BO TEN TUNG DAU TIEN ==================================\n";
    CanboTung(L);
    cout << "=============================================================================================\n";

    int k;
    cout << "Nhap vi tri can chen: ";
    cin >> k;

    if (insert(L, k) == 1)
    {
        cout << "\n================================= DANH SACH DA CHEN THEM ====================================\n";
        cout << "Danh sach vua bo sung\n";
        hienthiDSCB(L);
    }
    else
        cout << "Khong the chen vao danh sach\n";
    cout << "=============================================================================================\n";
}