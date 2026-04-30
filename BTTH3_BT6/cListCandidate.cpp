#include <string>
#include "cListCandidate.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//constructor khoi tao gia tri ban dau cua thi sinh;
cCandidate::cCandidate() {
    ma = "";
    ten = "";
    ngaysinh = "";
    diemtoan = 0;
    diemvan = 0;
    diemanh = 0;
}
//Ham nhap lan luot ma, ten, ngay sinh, diem toan, van, anh cua thi sinh;
void cCandidate::Nhap() {
    cout << "Nhap ma: "; cin >> ma; cin.ignore();
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap ngay sinh (dd/mm/yyyy): "; cin >> ngaysinh;
    cout << "Nhap diem toan: "; cin >> diemtoan;
    cout << "Nhap diem van: "; cin >> diemvan;
    cout << "Nhap diem anh: "; cin >> diemanh;

}
//Ham xuat, su dung setw de tao khoang cach giua cac gia tri,
//left de canh le trai (mac dinh la le phai);
void cCandidate::Xuat() const {
    cout << left << setw(10) << ma
                << setw(25) << ten
                << setw(15) << ngaysinh
                << setw(8) << diemtoan
                << setw(8) << diemvan
                << setw(8) << diemanh;
    cout << '\n';

}
//Constructor khoi tao gia tri ban dau cua danh sach thi sinh;
cListCandidate::cListCandidate() {
    n = 0;
    ds = nullptr;
}
//Destructor giai phong bo nho;
cListCandidate::~cListCandidate() {
    delete []ds;
}
//Ham nhap cua danh sach thi sinh;
void cListCandidate::Nhap() {
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    ds = new cCandidate[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thi sinh thu " << i + 1 << ": \n";
        ds[i].Nhap();
    }
}
//Ham in tieu de cho bang;
void cListCandidate::intieude() const{
    cout << left << setw(10) << "Ma"
                << setw(25) << "Ten"
                << setw(15) << "Ngay sinh"
                << setw(8) << "Toan"
                << setw(8) << "Van"
                << setw(8) << "Anh";
    cout << '\n';
}
//Ham xuat cua danh sach thi xem theo dang bang co tieu de;
void cListCandidate::Xuat() const {
    if (n == 0) { cout << "Danh sach trong! \n"; return; }
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}
//Ham tinh tong diem 3 mon toan, van, anh cua thi sinh;
double cCandidate::TinhTongDiem() const {
    return (diemtoan + diemvan + diemanh);
}
//Ham xuat tat ca thi sinh co tong diem 3 mon toan, van, anh tren 15 theo dang bang;
void cListCandidate::XuatThiSinhCoTongHon15() const {
    if (n == 0) { cout << "Danh sach trong! \n"; return; }
    intieude();
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTongDiem() > 15) {
            ds[i].Xuat();
        }
    }
}
//Ham xuat tat ca thi sinh co tong diem 3 mon toan, van, anh cao nhat theo dang bang;
void cListCandidate::XuatThiSinhCoTongCaoNhat() const {
    if (n == 0) { cout << "Danh sach trong! \n"; return; }
    double best = ds[0].TinhTongDiem();
    for (int i = 1; i < n; i++) {
        if (ds[i].TinhTongDiem() > best) {
            best = ds[i].TinhTongDiem();
        }
    }
    intieude();
    //In ra tat ca thi sinh co trung tong diem voi tong diem cao nhat;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTongDiem() == best) {
            ds[i].Xuat();
        }
    }
}
//Ham merge cua thuat toan merge sort (Sap xep giam dan);
void cListCandidate::merge (int l, int m, int r) {
    vector <cCandidate> left (ds + l, ds + m + 1);
    vector <cCandidate> right (ds + m + 1, ds + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i].TinhTongDiem() > right[j].TinhTongDiem()) ds[k++] = left[i++];
        else ds[k++] = right[j++];
    }
    while (i < left.size()) ds[k++] = left[i++];
    while (j < right.size()) ds[k++] = right[j++];
}
//Ham mergesort giup sap xep danh sach thi sinh co tong diem giam dan;
void cListCandidate::mergesort (int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}
//Ham sap xep giam dan danh sach thi sinh theo tong diem su dung mergesort va xuat ra theo dang bang;
void cListCandidate::SapXepGiamDanTheoTongDiem() {
    if (n == 0) { cout << "Danh sach trong! \n"; return; }
    mergesort(0, n - 1);
    intieude();
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

