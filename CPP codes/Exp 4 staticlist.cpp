#include <iostream>
const int max_size = 10;

struct staticlist {
    int elements[max_size];
    int count;
};

void initializelist(staticlist& list) {
    list.count = 0;
}

bool isempty(const staticlist& list) {
    return list.count == 0;
}

bool isfull(const staticlist& list) {
    return list.count == max_size;
}

void addelement(staticlist& list, int value) {
    if (isfull(list)) {
        std::cout << "list is full. cannot add element." << std::endl;
        return;
    }
    
    list.elements[list.count] = value;
    list.count++;
}

void displaylist(const staticlist& list) {
    if (isempty(list)) {
        std::cout << "list is empty." << std::endl;
        return;
    }
    
    std::cout << "list elements: ";
    for (int i = 0; i < list.count; i++) {
        std::cout << list.elements[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    staticlist mylist;
    initializelist(mylist);
    
    addelement(mylist, 10);
    addelement(mylist, 20);
    addelement(mylist, 30);
    
    displaylist(mylist);
    
    return 0;
}
