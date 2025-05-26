#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;

Inventory::Inventory(const string& username) : username(username) {
    loadData();
}

const vector<Item>& Inventory::getItems() const {
    return items;
}

void Inventory::loadData() {
    items.clear();
    ifstream file("inventory_" + username + ".txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string kode, nama;
        int jumlah;
        getline(ss, kode, ',');
        getline(ss, nama, ',');
        ss >> jumlah;
        items.emplace_back(kode, nama, jumlah);
    }
    file.close();
}

void Inventory::saveData() {
    ofstream file("inventory_" + username + ".txt");
    for (const auto& item : items) {
        file << item.getKode() << "," << item.getNama() << "," << item.getJumlah() << endl;
    }
    file.close();
}

void Inventory::addItem(const Item& item) {
    items.push_back(item);
    saveData();
    cout << "Item berhasil ditambahkan.\n";
}

void Inventory::editItem(const string& kode) {
    for (auto& item : items) {
        if (item.getKode() == kode) {
            int pilihanEdit;
            do {
                cout << "\nEdit item " << kode << ":\n";
                cout << "1. Edit Nama\n";
                cout << "2. Edit Jumlah\n";
                cout << "3. Edit Keduanya\n";
                cout << "4. Batal\n";
                cout << "Pilih opsi edit: ";
                cin >> pilihanEdit;

                if (pilihanEdit == 1) {
                    string newNama;
                    cout << "Nama baru: ";
                    cin.ignore();
                    getline(cin, newNama);
                    cout << "Apakah Anda yakin ingin mengubah nama item? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        item.setNama(newNama);
                        saveData();
                        cout << "Nama item berhasil diubah.\n";
                    } else {
                        cout << "Perubahan dibatalkan.\n";
                    }
                } else if (pilihanEdit == 2) {
                    int newJumlah;
                    cout << "Jumlah baru: ";
                    cin >> newJumlah;
                    cout << "Apakah Anda yakin ingin mengubah jumlah item? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        item.setJumlah(newJumlah);
                        saveData();
                        cout << "Jumlah item berhasil diubah.\n";
                    } else {
                        cout << "Perubahan dibatalkan.\n";
                    }
                } else if (pilihanEdit == 3) {
                    string newNama;
                    int newJumlah;
                    cout << "Nama baru: ";
                    cin.ignore();
                    getline(cin, newNama);
                    cout << "Jumlah baru: ";
                    cin >> newJumlah;
                    cout << "Apakah Anda yakin ingin mengubah item? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        item.setNama(newNama);
                        item.setJumlah(newJumlah);
                        saveData();
                        cout << "Item berhasil diubah.\n";
                    } else {
                        cout << "Perubahan dibatalkan.\n";
                    }
                } else if (pilihanEdit == 4) {
                    cout << "Edit dibatalkan.\n";
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
            } while (pilihanEdit < 1 || pilihanEdit > 4);
            return;
        }
    }
    cout << "Item dengan kode " << kode << " tidak ditemukan.\n";
}

void Inventory::deleteItem(const string& kode) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getKode() == kode) {
            cout << "Apakah Anda yakin ingin menghapus item ini? (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                items.erase(it);
                saveData();
                cout << "Item berhasil dihapus.\n";
            } else {
                cout << "Penghapusan item dibatalkan.\n";
            }
            return;
        }
    }
    cout << "Item dengan kode " << kode << " tidak ditemukan.\n";
}

void Inventory::getAllInventory() const {
    if (items.empty()) {
        cout << "Inventori kosong.\n";
        return;
    }
    cout << "Daftar Inventori:\n";
    for (const auto& item : items) {
        item.display();
    }
}
