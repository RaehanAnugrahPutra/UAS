#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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
