#include "inventory.h"

void inventory::AddWeapon(Weapon* weapon) {
    auto* node = new LinkedListNode<Weapon>(weapon);

    if (!current) {
        // Primer arma: la lista apunta a sí misma (circular)
        current = node;
        node->next = node;

    }
    else {
        // Insertar después del nodo actual y mantener circularidad
        node->next = current->next;
        current->next = node;
        current = node; // el arma recién agregada es la actual
    }
}

void inventory::NextWeapon() {
    if (current && current->next) {
        current = current->next;
    }
}

Weapon* inventory::GetCurrentWeapon() {
    return current ? current->data : nullptr;
}