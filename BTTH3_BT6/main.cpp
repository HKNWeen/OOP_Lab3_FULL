#include <iostream>
#include "cListCandidate.h"

using namespace std;

int main()
{
    cListCandidate L;

    L.Nhap();

    cout << "Danh sach tat ca thi sinh: \n";
    L.Xuat();

    cout << "Danh sach tat ca thi sinh co tong diem lon hon 15: \n";
    L.XuatThiSinhCoTongHon15();

    cout << "Danh sach thi sinh co tong diem cao nhat: \n";
    L.XuatThiSinhCoTongCaoNhat();

    cout << "Danh sach thi sinh duoc xep theo tong diem giam dan: \n";
    L.SapXepGiamDanTheoTongDiem();
}
