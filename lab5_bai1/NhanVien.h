#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <string>

using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

class NhanVien {
protected:
    string hoTen;
    Ngay ngaySinh;
    double luong;

public:
    NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0; // Phương thức thuần ảo
    double GetLuong();
    int GetTuoi();
    virtual int LoaiNhanVien() = 0; // 1 cho SX, 2 cho VP
};

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    NhanVienSanXuat();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNhanVien() override;
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    NhanVienVanPhong();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNhanVien() override;
};

#endif