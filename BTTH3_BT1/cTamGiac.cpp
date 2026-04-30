#include "cTamGiac.h"
#include <iostream>
#include <cmath>
using namespace std;
//Ham kiem tra bang nhau giua cac so thuc (vi so thuc co the co sai so nho);
bool BangNhau(double a, double b) {
    return (fabs(a - b) < (1e-4));
}
void Diem::NhapDiem() {
    cout << "\nNhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}
void Diem::XuatDiem() {
    cout << "(" << x << ", " << y << ")";
}
void cTamGiac::Nhap() {
    cout << "\nNhap diem A: "; A.NhapDiem();
    cout << "\nNhap diem B: "; B.NhapDiem();
    cout << "\nNhap diem C: "; C.NhapDiem();
}
void cTamGiac::Xuat() {
    cout << "Diem A: "; A.XuatDiem();
    cout << ", Diem B: "; B.XuatDiem();
    cout << ", Diem C: "; C.XuatDiem();
}
//Ham tinh do dai cua cac canh
double Diem::KhoangCach (Diem khac) {
    return sqrt(pow(x - khac.x, 2) + pow(y - khac.y, 2));
}
//Ham tinh chu vi cua tam giac;
//Cong thuc chu vi: AB + BC + AC;
double cTamGiac::TinhChuVi() {
    double AB = A.KhoangCach(B);
    double BC = B.KhoangCach(C);
    double AC = C.KhoangCach(A);
    return AB + BC + AC;
}
//Su dung cong thuc heron de tinh dien tich;
//p = (AB + BC + AC)/2;
//Cong thuc heron: sqrt(p * (p - AB) * (p - BC) * (p - AC));
double cTamGiac::TinhDienTich() {
    double AB = A.KhoangCach(B);
    double BC = B.KhoangCach(C);
    double AC = C.KhoangCach(A);
    double p = (AB + BC + AC)/2;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}
//Ham kiem tra coi day la tam giac deu, can, vuong, thuong hay khong phai tam giac;
int cTamGiac::KiemTraLoaiTamGiac() {
    double AB = A.KhoangCach(B);
    double BC = B.KhoangCach(C);
    double AC = C.KhoangCach(A);
    if (AB + BC <= AC + 1e-4 ||
        AB + AC <= BC + 1e-4 ||
        AC + BC <= AB + 1e-4) {
        return -1;
    }
    if (BangNhau(AB, BC) && BangNhau(BC, AC)) {
        return 3;
    }
    if (BangNhau(AB, BC) || BangNhau(AB, AC) || BangNhau(BC, AC)) {
        return 2;
    }
    if (BangNhau(AB*AB + BC*BC, AC*AC) ||
        BangNhau(AB*AB + AC*AC, BC*BC) ||
        BangNhau(BC*BC + AC*AC, AB*AB)){
        return 1;
    }
    return 0;
}
//Ham tinh tien cua diem
void Diem::TinhTienDiem(double dx, double dy) {
    x += dx;
    y += dy;
}
//Ham tinh tien cua tam giac
void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTienDiem(dx, dy);
    B.TinhTienDiem(dx, dy);
    C.TinhTienDiem(dx, dy);
}
//Ham quay tung diem
void Diem::QuayDiem(double goc) {
    double rad = goc * M_PI / 180;
    double dx = x * cos(rad) - y * sin(rad);
    double dy = x * sin(rad) + y * cos(rad);
    x = dx;
    y = dy;
}
//Ham quay ca tam giac
void cTamGiac::Quay(double goc) {
    A.QuayDiem(goc);
    B.QuayDiem(goc);
    C.QuayDiem(goc);
}
//Ham phong to/ thu nho tung diem
void Diem::PhongToThuNhoDiem(double k) {
    x *= k;
    y *= k;
}
//Ham phong to/ thu nho ca tam giac
void cTamGiac::PhongToThuNho(double k) {
    A.PhongToThuNhoDiem(k);
    B.PhongToThuNhoDiem(k);
    C.PhongToThuNhoDiem(k);
}

