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
