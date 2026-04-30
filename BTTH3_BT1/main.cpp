#include <iostream>
#include "cTamGiac.h"
using namespace std;

int main() {
    cTamGiac t; double dx, dy; double k; double goc;
    cout << "Nhap toa do cua 3 diem trong tam giac: ";
    t.Nhap();
    cout << "\nToa do cua 3 diem: \n";
    t.Xuat();
    cout << '\n';

    int type = t.KiemTraLoaiTamGiac();
    if (type == 0) cout << "Tam giac thuong";
    else if (type == 1) cout << "Tam giac vuong";
    else if (type == 2) cout << "Tam giac can";
    else if (type == 3) cout << "Tam giac deu";
    else cout << "Khong phai tam giac";

    //Neu la tam giac thi thuc hien tiep nhung buoc tiep theo
    if (type != -1) {
    double cv = t.TinhChuVi();
    double dt = t.TinhDienTich();
    cout << "\nChu vi: " << cv;
    cout << "\nDien Tich: " << dt;

    cout << "\nNhap toa do tinh tien: "
    << "\nToa do dx: "; cin >> dx;
    cout << "Toa do dy: "; cin >> dy;
    t.TinhTien(dx, dy);
    cout << "Toa do cua 3 diem sau khi tinh tien: \n";
    t.Xuat();

    cout << "\nNhap ti le phong to/ thu nho: ";
    cin >> k;
    t.PhongToThuNho(k);
    cout << "Toa do cua 3 diem sau khi phong to/ thu nho: \n";
    t.Xuat();

    cout << "\nNhap goc do quay: ";
    cin >> goc;
    t.Quay(goc);
    cout << "Toa do cua 3 diem sau khi quay: \n";
    t.Xuat();
    }
}
