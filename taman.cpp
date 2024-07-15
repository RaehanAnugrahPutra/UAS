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
