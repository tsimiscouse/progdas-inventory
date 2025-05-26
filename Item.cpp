#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Item::Item() : kode(""), nama(""), jumlah(0) {}

Item::Item(const string& kode, const string& nama, int jumlah)
    : kode(kode), nama(nama), jumlah(jumlah) {}

void Item::setKode(const string& kode) { this->kode = kode; }
void Item::setNama(const string& nama) { this->nama = nama; }
void Item::setJumlah(int jumlah) { this->jumlah = jumlah; }

string Item::getKode() const { return kode; }
string Item::getNama() const { return nama; }
int Item::getJumlah() const { return jumlah; }

void Item::display() const {
    cout << "Kode: " << kode << ", Nama: " << nama << ", Jumlah: " << jumlah << endl;
}
