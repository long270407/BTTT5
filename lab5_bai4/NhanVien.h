#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;
    double luong;

public:
    NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0;
    virtual int LoaiNV() = 0; // 1: Lap trinh vien, 2: Kiem chung vien
    double GetLuong();
};

class LapTrinhVien : public NhanVien {
private:
    double soGioOvertime;

public:
    LapTrinhVien();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNV() override;
};

class KiemChungVien : public NhanVien {
private:
    int soLoi;

public:
    KiemChungVien();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNV() override;
};

#endif