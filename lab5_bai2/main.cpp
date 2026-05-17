#include "GiaoDich.h"

const int MAX = 100;

int main() {
    GiaoDich* danhSach[MAX];
    int soLuong = 0;
    int slDat, slNhaPho, slChungCu;

    // 1. Nhập danh sách
    cout << "--- NHAP GIAO DICH DAT ---" << endl;
    cout << "So luong: "; cin >> slDat;
    for (int i = 0; i < slDat; i++) {
        if (soLuong >= MAX) break;
        cout << "\nGiao dich Dat thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new GiaoDichDat();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    cout << "\n--- NHAP GIAO DICH NHA PHO ---" << endl;
    cout << "So luong: "; cin >> slNhaPho;
    for (int i = 0; i < slNhaPho; i++) {
        if (soLuong >= MAX) break;
        cout << "\nGiao dich Nha Pho thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new GiaoDichNhaPho();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    cout << "\n--- NHAP GIAO DICH CHUNG CU ---" << endl;
    cout << "So luong: "; cin >> slChungCu;
    for (int i = 0; i < slChungCu; i++) {
        if (soLuong >= MAX) break;
        cout << "\nGiao dich Chung Cu thu " << i + 1 << ":" << endl;
        danhSach[soLuong] = new GiaoDichChungCu();
        danhSach[soLuong]->Nhap();
        soLuong++;
    }

    // Xuất danh sách để kiểm tra
    cout << "\n================ DANH SACH GIAO DICH ================" << endl;
    for (int i = 0; i < soLuong; i++) {
        danhSach[i]->Xuat();
    }

    // 2. Tính tổng số lượng cho từng loại
    cout << "\n================ THONG KE ================" << endl;
    cout << "Tong so GD Dat: " << slDat << endl;
    cout << "Tong so GD Nha Pho: " << slNhaPho << endl;
    cout << "Tong so GD Chung Cu: " << slChungCu << endl;

    // 3. Tính trung bình thành tiền của GD Căn hộ chung cư
    double tongTienChungCu = 0;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->LoaiGD() == 3) {
            tongTienChungCu += danhSach[i]->TinhTien();
        }
    }
    if (slChungCu > 0) {
        cout << "Trung binh thanh tien GD Chung cu: " << (tongTienChungCu / slChungCu) << endl;
    }
    else {
        cout << "Khong co giao dich Chung cu de tinh trung binh." << endl;
    }

    // 4. Tìm Giao dịch Nhà phố có trị giá cao nhất
    double maxTienNhaPho = -1;
    GiaoDich* gdNhaPhoMax = nullptr;
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i]->LoaiGD() == 2) {
            if (maxTienNhaPho == -1 || danhSach[i]->TinhTien() > maxTienNhaPho) {
                maxTienNhaPho = danhSach[i]->TinhTien();
                gdNhaPhoMax = danhSach[i];
            }
        }
    }

    if (gdNhaPhoMax != nullptr) {
        cout << "\nGiao dich Nha Pho co tri gia cao nhat:" << endl;
        gdNhaPhoMax->Xuat();
    }
    else {
        cout << "\nKhong co giao dich Nha pho." << endl;
    }

    // 5. Xuất danh sách giao dịch tháng 12/2024
    cout << "\n===== DANH SACH GIAO DICH THANG 12 NAM 2024 =====" << endl;
    bool coGDThang12 = false;
    for (int i = 0; i < soLuong; i++) {
        Ngay d = danhSach[i]->GetNgayGD();
        if (d.thang == 12 && d.nam == 2024) {
            danhSach[i]->Xuat();
            coGDThang12 = true;
        }
    }
    if (!coGDThang12) {
        cout << "Khong co giao dich nao trong thang 12/2024." << endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < soLuong; i++) {
        delete danhSach[i];
    }

    return 0;
}