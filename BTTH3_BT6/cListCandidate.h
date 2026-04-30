#ifndef CLISTCANDIDATE_H_INCLUDED
#define CLISTCANDIDATE_H_INCLUDED
#include <string>

class cCandidate {
private:
    std::string ma;
    std::string ten;
    std::string ngaysinh;
    double diemtoan;
    double diemvan;
    double diemanh;
public:
    cCandidate();
    void Nhap();
    void Xuat() const;
    double TinhTongDiem() const;
};

class cListCandidate {
private:
    int n;
    cCandidate* ds;
    void intieude() const;
    void merge(int l, int m, int r);
    void mergesort(int l, int r);
public:
    cListCandidate();
    ~cListCandidate();
    void Nhap();
    void Xuat() const;
    void XuatThiSinhCoTongHon15() const;
    void XuatThiSinhCoTongCaoNhat() const;
    void SapXepGiamDanTheoTongDiem();
};

#endif // CLISTCANDIDATE_H_INCLUDED
