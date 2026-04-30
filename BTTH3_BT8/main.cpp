#include <iostream>
#include "cNhanVienSX.h"

using namespace std;

int main()
{
    cListNhanVienSX L;
    L.Nhap();

    cout << "Danh sach tat ca nhan vien san xuat: \n";
    L.Xuat();

    cout << "Danh sach nhan vien san xuat co luong thap nhat: \n";
    L.TimLuongThapNhat();

    cout << "Danh sach nhan vien san xuat co tuoi cao nhat: \n";
    L.TimTuoiCaoNhat();

    cout << "Danh sach nhan vien san xuat sap xep tang dan theo luong: \n";
    L.SapXepTangDanTheoLuong();

    cout << "Tong luong: " <<  L.TinhTongLuong();
}
