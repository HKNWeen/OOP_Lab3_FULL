#ifndef CDATHUC_H_INCLUDED
#define CDATHUC_H_INCLUDED
class cDaThuc {
private:
    int bac;
    double* heso;
public:
    cDaThuc();
    cDaThuc(int n);
    cDaThuc(const cDaThuc& other);
    ~cDaThuc();
    cDaThuc& operator=(const cDaThuc& other);
    void Nhap();
    void Xuat() const;
    double TinhGiaTri(double x) const;
    cDaThuc Cong(const cDaThuc& other) const;
    cDaThuc operator+(const cDaThuc& other) const;
    cDaThuc Tru(const cDaThuc& other) const;
    cDaThuc operator-(const cDaThuc& other) const;
};
#endif // CDATHUC_H_INCLUDED
