#pragma once
#include "Weapon.h"
using namespace LoW;

template<typename T>
class LinkedListNode {
public:
    T* data;
    LinkedListNode* next;
    LinkedListNode(T* d) : data(d), next(nullptr) {}
};

class inventory {
public:
    LinkedListNode<Weapon>* sword = nullptr;
    LinkedListNode<Weapon>* Axe = nullptr;
    LinkedListNode<Weapon>* current = nullptr;

    void AddWeapon(Weapon* weapon);
    void NextWeapon();
    Weapon* GetCurrentWeapon();
};
