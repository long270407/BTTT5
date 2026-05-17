#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class KhachHang {
protected:
    string hoTen;
    int soLuong;
    double donGia;

public:
    KhachHang();
    virtual void DocFile(ifstream& in);
    virtual void GhiFile(ofstream& out);
    virtual double TinhTien() = 0;
    virtual ~KhachHang() {}
};

class KhachHangThuong : public KhachHang {
public:
    double TinhTien() override;
};

class KhachHangThanThiet : public KhachHang {
private:
    int soNam;
public:
    KhachHangThanThiet();
    void DocFile(ifstream& in) override;
    double TinhTien() override;
};

class KhachHangDacBiet : public KhachHang {
public:
    double TinhTien() override;
};

#endif