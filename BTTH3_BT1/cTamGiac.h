#ifndef CTAMGIAC_H_INCLUDED
#define CTAMGIAC_H_INCLUDED
class Diem {
private:
    double x, y;
public:
    void NhapDiem();
    void XuatDiem();
    double KhoangCach(Diem khac);
    void TinhTienDiem(double dx, double dy);
    void QuayDiem(double goc);
    void PhongToThuNhoDiem(double k);
};
class cTamGiac {
private:
    Diem A, B, C;
public:
    void Nhap();
    void Xuat();
    int KiemTraLoaiTamGiac();
    double TinhDienTich();
    double TinhChuVi();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
};


#endif // CTAMGIAC_H_INCLUDED
