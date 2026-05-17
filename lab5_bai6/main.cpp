#include "KhachHang.h"

// Giới hạn tĩnh 3000 vì đề bài cho 0 < x, y, z < 1000
const int MAX = 3000;

int main() {
    ifstream inFile("XYZ.INP");
    ofstream outFile("XYZ.OUT");

    if (!inFile.is_open()) {
        cout << "Khong the mo file XYZ.INP" << endl;
        return 1;
    }

    int x, y, z;
    inFile >> x >> y >> z;

    KhachHang* danhSach[MAX];
    int soLuongKH = 0;

    // Đọc danh sách Loại A
    for (int i = 0; i < x; i++) {
        danhSach[soLuongKH] = new KhachHangThuong();
        danhSach[soLuongKH]->DocFile(inFile);
        soLuongKH++;
    }

    // Đọc danh sách Loại B
    for (int i = 0; i < y; i++) {
        danhSach[soLuongKH] = new KhachHangThanThiet();
        danhSach[soLuongKH]->DocFile(inFile);
        soLuongKH++;
    }

    // Đọc danh sách Loại C
    for (int i = 0; i < z; i++) {
        danhSach[soLuongKH] = new KhachHangDacBiet();
        danhSach[soLuongKH]->DocFile(inFile);
        soLuongKH++;
    }

    inFile.close();

    // Ghi dữ liệu ra file XYZ.OUT
    outFile << x << " " << y << " " << z << "\n";
    double tongTienCongTy = 0;

    for (int i = 0; i < soLuongKH; i++) {
        danhSach[i]->GhiFile(outFile);
        tongTienCongTy += danhSach[i]->TinhTien();
    }

    outFile << tongTienCongTy << "\n";
    outFile.close();

    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuongKH; i++) {
        delete danhSach[i];
    }

    cout << "Da xu ly xong! Kiem tra file XYZ.OUT." << endl;
    return 0;
}