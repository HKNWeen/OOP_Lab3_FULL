#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cArray.h"
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout << "Nhap kich thuoc cua mang: ";
    cin >> n;
    cArray a(n);

    a.TaoMangNgauNhien();
    cout << "Mang ngau nhien da khoi tao: \n";
    a.XuatMang();

    if (a.KiemTraTangDan()) cout << "Day tang dan!";
    else cout << "Day khong tang dan!";
    cout << '\n';

    int minLe = a.TimPhanLeNhoNhat();
    if (minLe != -1) {
        cout << "Phan le nho nhat: ";
        cout << minLe;
    }
    else cout << "Khong ton tai phan le nho nhat";
    cout << '\n';

    int maxNguyenTo = a.TimSoNguyenToLonNhat();
    if (maxNguyenTo != -1) {
        cout << "So nguyen to lon nhat: ";
        cout << maxNguyenTo;
    }
    else cout << "Khong ton tai so nguyen to lon nhat";
    cout <<'\n';


    a.SapXepTangDan();
    cout << "Mang tang dan: \n";
    a.XuatMang();

    a.SapXepGiamDan();
    cout << "Mang giam dan: \n";
    a.XuatMang();

    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "So lan gia tri x xuat hien trong mang: " << a.DemSoLanXuatHien(x);
}
