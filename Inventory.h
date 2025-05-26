/**
 * Project Class-Diagram-Progdas
 */


#ifndef _INVENTORY_H
#define _INVENTORY_H

class Inventory {
public: 
    
/**
 * @param username
 */
void Inventory(string username);
    
void loadData();
    
void saveData();
    
void addItem();
    
void getAllInventory();
    
void editItem();
    
void deteleItem();
private: 
    vector<Item> items;
    string username;
};

#endif //_INVENTORY_H