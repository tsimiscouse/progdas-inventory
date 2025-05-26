#include "AuthManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::stringstream;

AuthManager::AuthManager() {
    loadUsers();
}

void AuthManager::loadUsers() {
    users.clear();
    ifstream file("users.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.emplace_back(username, password);
    }
    file.close();
}

void AuthManager::saveUser(const User& user) {
    ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << user.getUsername() << "," << user.getPassword() << endl;
        file.close();
    }
}

bool AuthManager::registerUser() {
    string username, password;
    cout << "Masukkan username baru: ";
    cin >> username;

    // Cek username sudah ada
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            cout << "Username sudah digunakan.\n";
            return false;
        }
    }

    cout << "Masukkan password: ";
    cin >> password;

    User newUser(username, password);
    users.push_back(newUser);
    saveUser(newUser);

    cout << "Registrasi berhasil!\n";
    return true;
}

bool AuthManager::login(string& currentUser) {
    string username, password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            currentUser = username;
            cout << "Login berhasil!\n";
            return true;
        }
    }

    cout << "Login gagal! Username atau password salah.\n";
    return false;
}
