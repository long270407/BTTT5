#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>

using namespace std;

class SinhVien {
protected:
    string mssv;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    SinhVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual bool KiemTraTotNghiep() = 0;
    virtual int LoaiSV() = 0; // 1: Cao Dang, 2: Dai Hoc
    double GetDiemTB();
};

class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;

public:
    SinhVienCaoDang();
    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
    int LoaiSV() override;
};

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    SinhVienDaiHoc();
    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
    int LoaiSV() override;
};

#endif