#include "KhachHang.h"

// --- KhachHang (Base) ---
KhachHang::KhachHang() : soLuong(0), donGia(0) {}

void KhachHang::DocFile(ifstream& in) {
    getline(in >> ws, hoTen); // Đọc chuỗi bỏ qua khoảng trắng thừa/newline
    in >> soLuong;
    in >> donGia;
}

void KhachHang::GhiFile(ofstream& out) {
    out << hoTen << "\n" << TinhTien() << "\n";
}

// --- KhachHangThuong (Loại A) ---
double KhachHangThuong::TinhTien() {
    double tien = soLuong * donGia;
    return tien + tien * 0.1; // + VAT 10%
}

// --- KhachHangThanThiet (Loại B) ---
KhachHangThanThiet::KhachHangThanThiet() : soNam(0) {}

void KhachHangThanThiet::DocFile(ifstream& in) {
    KhachHang::DocFile(in);
    in >> soNam;
}

double KhachHangThanThiet::TinhTien() {
    double khuyenMai = max(soNam * 0.05, 0.5); // Max của Số năm * 5% và 50%
    double tien = (soLuong * donGia) * (1.0 - khuyenMai);
    return tien + tien * 0.1; // + VAT 10%
}

// --- KhachHangDacBiet (Loại C) ---
double KhachHangDacBiet::TinhTien() {
    double tien = (soLuong * donGia) * 0.5;
    return tien + tien * 0.1; // + VAT 10%
}