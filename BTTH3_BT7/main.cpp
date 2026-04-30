#include <iostream>
#include "cNhanVienVP.h"
using namespace std;

int main()
{
    cListNhanVienVP L;
    L.Nhap();

    cout << "Danh sach tat ca nhan vien van phong: \n";
    L.Xuat();

    cout << "Danh sach nhan vien van phong co luong cao nhat: \n";
    L.TimLuongCaoNhat();

    cout << "Danh sach nhan vien van phong co tuoi cao nhat: \n";
    L.TimTuoiCaoNhat();

    cout << "Danh sach nhan vien van phong sap xep tang dan theo luong: \n";
    L.SapXepTangDanTheoLuong();

    cout << "Tong luong: " <<  L.TinhTongLuong();
}
