#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct Pengunjung {
    string nama;
    int usia;
    string jenisKelamin;
    string nomorTelepon;
    string tanggalKunjungan;
    string jenisTiket;
    string kodeBooking;
};

vector<Pengunjung> pengunjungList;
string generateKodeBooking() {
    string kode = "TW";
    for (int i = 0; i < 5; ++i) {
        kode += '0' + rand() % 10;
    }
    return kode;
}
bool validasiUmur(int usia) {
    return usia > 5;
}
void tambahPengunjung() {
    Pengunjung p;

    cout << "Masukkan nama pengunjung: ";
    getline(cin, p.nama);

    cout << "Masukkan usia pengunjung: ";
    cin >> p.usia;
    cin.ignore();

    if (!validasiUmur(p.usia)) {
        cout << "Error: Usia pengunjung harus lebih dari 5 tahun!" << endl;
        return;
    }

    cout << "Masukkan jenis kelamin pengunjung: ";
    getline(cin, p.jenisKelamin);

    cout << "Masukkan nomor telepon pengunjung: ";
    getline(cin, p.nomorTelepon);

    cout << "Masukkan tanggal kunjungan (DD/MM/YYYY): ";
    getline(cin, p.tanggalKunjungan);

    cout << "Masukkan jenis tiket (reguler/VIP): ";
    getline(cin, p.jenisTiket);

    p.kodeBooking = generateKodeBooking();

    pengunjungList.push_back(p);

    cout << "Pendaftaran berhasil! Kode booking: " << p.kodeBooking << endl;
}
void cariPengunjung() {
    string keyword;
    cout << "Masukkan nama atau kode booking pengunjung: ";
    getline(cin, keyword);

    for (const auto &p : pengunjungList) {
        if (p.nama == keyword || p.kodeBooking == keyword) {
            cout << "Nama: " << p.nama << endl;
            cout << "Usia: " << p.usia << endl;
            cout << "Jenis Kelamin: " << p.jenisKelamin << endl;
            cout << "Nomor Telepon: " << p.nomorTelepon << endl;
            cout << "Tanggal Kunjungan: " << p.tanggalKunjungan << endl;
            cout << "Jenis Tiket: " << p.jenisTiket << endl;
            cout << "Kode Booking: " << p.kodeBooking << endl;
            return;
        }
    }

    cout << "Pengunjung tidak ditemukan!" << endl;
}
void batalkanKunjungan() {
    string kodeBooking;
    cout << "Masukkan kode booking pengunjung yang akan dibatalkan: ";
    getline(cin, kodeBooking);

    for (auto it = pengunjungList.begin(); it != pengunjungList.end(); ++it) {
        if (it->kodeBooking == kodeBooking) {
            pengunjungList.erase(it);
            cout << "Kunjungan berhasil dibatalkan!" << endl;
            return;
        }
    }

    cout << "Kode booking tidak ditemukan!" << endl;
}
void daftarPengunjung() {
    string tanggalKunjungan, jenisTiket;
    cout << "Masukkan tanggal kunjungan (DD/MM/YYYY): ";
    getline(cin, tanggalKunjungan);
    cout << "Masukkan jenis tiket (reguler/VIP): ";
    getline(cin, jenisTiket);

    for (const auto &p : pengunjungList) {
        if (p.tanggalKunjungan == tanggalKunjungan && p.jenisTiket == jenisTiket) {
            cout << "Nama: " << p.nama << endl;
            cout << "Usia: " << p.usia << endl;
            cout << "Jenis Kelamin: " << p.jenisKelamin << endl;
            cout << "Nomor Telepon: " << p.nomorTelepon << endl;
            cout << "Kode Booking: " << p.kodeBooking << endl;
            cout << "--------------------------" << endl;
        }
    }
}

int main() {
    srand(time(0));
    int pilihan;

    do {
        cout << "Sistem Manajemen Pengelolaan Taman Wisata" << endl;
        cout << "1. Tambah Pengunjung" << endl;
        cout << "2. Cari Pengunjung" << endl;
        cout << "3. Batalkan Kunjungan" << endl;
        cout << "4. Daftar Pengunjung" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahPengunjung();
                break;
            case 2:
                cariPengunjung();
                break;
            case 3:
                batalkanKunjungan();
                break;
            case 4:
                daftarPengunjung();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
