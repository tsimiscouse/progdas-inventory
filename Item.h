#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

class Item {
private:
    string kode;
    string nama;
    int jumlah;

public:
    Item();
    Item(const string& kode, const string& nama, int jumlah);

    void setKode(const string& kode);
    void setNama(const string& nama);
    void setJumlah(int jumlah);

    string getKode() const;
    string getNama() const;
    int getJumlah() const;

    void display() const;
};

#endif
