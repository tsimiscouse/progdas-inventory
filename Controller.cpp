#include "Controller.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Controller::Controller() : inventory(nullptr) {}

Controller::~Controller() {
    if (inventory != nullptr) {
        delete inventory;
    }
}

void Controller::mainMenu() {
    int choice;
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Pilih: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n=== Register User ===\n";
                authManager.registerUser();
                break;
            case 2:
                cout << "\n=== Login User ===\n";
                if (authManager.login(currentUser)) {
                    if (inventory != nullptr) delete inventory;
                    inventory = new Inventory(currentUser);
                    userMenu();
                }
                break;
            case 3:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while(choice != 3);
}

void Controller::userMenu() {
    int choice;
    do {
        cout << "\n=== Menu User (" << currentUser << ") ===\n";
        cout << "1. Tambah Item\n";
        cout << "2. Edit Item\n";
        cout << "3. Hapus Item\n";
        cout << "4. Tampilkan Semua Item\n";
        cout << "5. Logout\n";
        cout << "Pilih: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n=== Tambah Item ===\n";
            string kode, nama;
            int jumlah;
            cout << "Kode item: ";
            cin >> kode;

            // Cek apakah kode item sudah ada
            bool kodeSudahAda = false;
            for (const auto& item : inventory->getItems()) {
                if (item.getKode() == kode) {
                    kodeSudahAda = true;
                    break;
                }
            }

            if (kodeSudahAda) {
                cout << "Kode item sudah digunakan. Silakan gunakan kode lain.\n";
            } else {
                cout << "Nama item: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Jumlah item: ";
                cin >> jumlah;

                cout << "Apakah Anda yakin ingin menambahkan item ini? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    Item newItem(kode, nama, jumlah);
                    inventory->addItem(newItem);
                } else {
                    cout << "Penambahan item dibatalkan.\n";
                }
            }

        } else if (choice == 2) {
            string kode;
            cout << "\n=== Edit Item ===\n";
            inventory->getAllInventory();
            if(inventory->getItems().empty()) {
                cout << "Tidak ada item untuk diedit.\n";
                continue;
            }
            cout << "\nMasukkan kode item yang ingin diedit: ";
            cin >> kode;
            inventory->editItem(kode);

        } else if (choice == 3) {
            string kode;
            cout << "\n=== Hapus Item ===\n";
            inventory->getAllInventory();
            if(inventory->getItems().empty()) {
                cout << "Tidak ada item untuk dihapus.\n";
                continue;
            }
            cout << "\nMasukkan kode item yang ingin dihapus: ";
            cin >> kode;
            inventory->deleteItem(kode);

        } else if (choice == 4) {
            cout << "\n=== Tampilkan Semua Item ===\n";
            inventory->getAllInventory();

        } else if (choice == 5) {
            cout << "Logout berhasil.\n";
            currentUser = "";
            if (inventory != nullptr) {
                delete inventory;
                inventory = nullptr;
            }
            break;

        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (true);
}

void Controller::run() {
    mainMenu();
}
