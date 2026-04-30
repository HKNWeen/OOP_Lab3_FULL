#include <iostream>
#include "cDaThuc.h"
using namespace std;

int main()
{
    cDaThuc A, B, Tong, Hieu;
    double x;

    A.Nhap();
    B.Nhap();

    cout << "Da thuc A: \n";
    A.Xuat();
    cout << "Da thuc B: \n";
    B.Xuat();

    Tong = A + B;
    cout << "Tong (A + B): \n";
    Tong.Xuat();

    Hieu = A - B;
    cout << "Hieu (A - B): \n";
    Hieu.Xuat();

    cout << "Nhap x: ";
    cin >> x;
    cout << "Gia tri cua A(x): " << A.TinhGiaTri(x);
    cout << "\nGia tri cua B(x): " << B.TinhGiaTri(x);
}
