#ifndef GIAODICH_H
#define GIAODICH_H
#include <iostream>
#include <string>

using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

class GiaoDich {
protected:
    string maGD;
    Ngay ngayGD;
    double donGia;
    double dienTich;

public:
    GiaoDich();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhTien() = 0;
    virtual int LoaiGD() = 0; // 1: Dat, 2: Nha pho, 3: Chung cu
    Ngay GetNgayGD();
};

class GiaoDichDat : public GiaoDich {
private:
    string loaiDat; // A, B, C
public:
    GiaoDichDat();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int LoaiGD() override;
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha; // "cao cap" hoac "thuong"
    string diaChi;
public:
    GiaoDichNhaPho();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int LoaiGD() override;
};

class GiaoDichChungCu : public GiaoDich {
private:
    string maCan;
    int viTriTang;
public:
    GiaoDichChungCu();
    void Nhap() override;
    void Xuat() override;
    double TinhTien() override;
    int LoaiGD() override;
};

#endif