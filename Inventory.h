#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Inventory {
private:
    vector<Item> items;
    string username;  // Untuk file data per user

public:
    Inventory(const string& username);
    const vector<Item>& getItems() const;
    void loadData();
    void saveData();

    void addItem(const Item& item);
    void editItem(const string& kode);
    void deleteItem(const string& kode);
    void getAllInventory() const;
};

#endif
