#include <iostream>
#include "cDaGiac.h"
using namespace std;

int main()
{
    cDaGiac dg; double dx, dy; double k; double goc;

    dg.Nhap();

    cout << "Toa do cac dinh cua da giac: \n";
    dg.Xuat();

    cout << "\nChu vi cua da giac: \n";
    cout << dg.TinhChuVi();

    cout <<"\nDien tich cua da giac: \n";
    cout << dg.TinhDienTich();

    cout << "\nNhap toa do tinh tien: \n";
    cout << "Nhap toa do dx: "; cin >> dx;
    cout << "Nhap toa do dy: "; cin >> dy;
    cout << "Toa do cac dinh cua da giac sau khi tinh tien: \n";
    dg.TinhTien(dx, dy);
    dg.Xuat();

    cout << "\nNhap ti le phong to/ thu nho: ";
    cin >> k;
    cout << "Toa do cac dinh cua da giac sau khi phong to/ thu nho: \n";
    dg.PhongToThuNho(k);
    dg.Xuat();

    cout << "\nNhap goc do quay: ";
    cin >> goc;
    cout << "Toa do cac dinh cua da giac sau khi quay: \n";
    dg.Quay(goc);
    dg.Xuat();

    return 0;
}
