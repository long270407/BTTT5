#include "SinhVien.h"

const int MAX = 100;

int main() {
    SinhVien* danhSach[MAX];
    int soLuong = 0;
    int slCaoDang, slDaiHoc;

    // a. Nhập danh sách sinh viên
    cout << "--- NHAP DANH SACH SINH VIEN CAO DANG ---" << endl;
    cout << "So luong SV Cao Dang: "; cin >> slCaoDang;
    for (int i = 0; i < slCaoDang; i++) {
        if (soLuong >= MAX) break;
        cout << "\nSinh vien Cao dang thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new SinhVienCaoDang();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    cout << "\n--- NHAP DANH SACH SINH VIEN DAI HOC ---" << endl;
    cout << "So luong SV Dai Hoc: "; cin >> slDaiHoc;
    for (int i = 0; i < slDaiHoc; i++) {
        if (soLuong >= MAX) break;
        cout << "\nSinh vien Dai hoc thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new SinhVienDaiHoc();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    // b. Xuất danh sách sinh viên
    cout << "\n================ DANH SACH SINH VIEN ================" << endl;
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->Xuat();
    }

    // c. Xuất danh sách sinh viên đủ điều kiện tốt nghiệp
    cout << "\n================ SV DU DIEU KIEN TOT NGHIEP ================" << endl;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->KiemTraTotNghiep()) {
            danhSach[i]->Xuat();
        }
    }

    // d. Xuất danh sách sinh viên không đủ điều kiện tốt nghiệp
    cout << "\n================ SV KHONG DU DIEU KIEN TOT NGHIEP ================" << endl;
    for (int i = 0; i < soLuong; i++) {
        if (!danhSach[i]->KiemTraTotNghiep()) {
            danhSach[i]->Xuat();
        }
    }

    // e & f. Tìm sinh viên có điểm trung bình cao nhất mỗi hệ
    double maxDTBCaoDang = -1, maxDTBDaiHoc = -1;
    SinhVien* svCaoDangMax = nullptr;
    SinhVien* svDaiHocMax = nullptr;

    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->LoaiSV() == 1) { // Cao Dang
            if (danhSach[i]->GetDiemTB() > maxDTBCaoDang) {
                maxDTBCaoDang = danhSach[i]->GetDiemTB();
                svCaoDangMax = danhSach[i];
            }
        }
        else if (danhSach[i]->LoaiSV() == 2) { // Dai Hoc
            if (danhSach[i]->GetDiemTB() > maxDTBDaiHoc) {
                maxDTBDaiHoc = danhSach[i]->GetDiemTB();
                svDaiHocMax = danhSach[i];
            }
        }
    }

    cout << "\n================ SINH VIEN CO DIEM TB CAO NHAT ================" << endl;
    if (svCaoDangMax != nullptr) {
        cout << "He Cao dang:" << endl;
        svCaoDangMax->Xuat();
    }
    else {
        cout << "Khong co sinh vien he Cao dang." << endl;
    }

    if (svDaiHocMax != nullptr) {
        cout << "He Dai hoc:" << endl;
        svDaiHocMax->Xuat();
    }
    else {
        cout << "Khong co sinh vien he Dai hoc." << endl;
    }

    // g. Thống kê số lượng sinh viên không đủ điều kiện tốt nghiệp
    int rotCaoDang = 0, rotDaiHoc = 0;
    for (int i = 0; i < soLuong; i++) {
        if (!danhSach[i]->KiemTraTotNghiep()) {
            if (danhSach[i]->LoaiSV() == 1) rotCaoDang++;
            else if (danhSach[i]->LoaiSV() == 2) rotDaiHoc++;
        }
    }

    cout << "\n================ THONG KE KHONG DU DK TOT NGHIEP ================" << endl;
    cout << "So luong SV he Cao dang khong du dieu kien: " << rotCaoDang << endl;
    cout << "So luong SV he Dai hoc khong du dieu kien: " << rotDaiHoc << endl;

    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuong; i++) {
        delete danhSach[i];
    }

    return 0;
}