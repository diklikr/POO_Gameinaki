#pragma once
#include <iostream>
#include <string>
#include "Singleton.h"
#pragma once  
#include <iostream>  

class Toolbox {  
private:  
   Toolbox() {} // Constructor privado para el patrón Singleton  

public:  
   static Toolbox& getInstance() {  
       static Toolbox instance;  
       return instance;  
   }  

   void printMessage(const std::string& message) {  
       std::cout << message << std::endl;  
   }  

   // Eliminar constructores de copia y asignación para evitar duplicados  
   Toolbox(const Toolbox&) = delete;  
   Toolbox& operator=(const Toolbox&) = delete;  
}; 

//template <typename T>  
//class LinkedListNode {  
//public:  
//   friend class Singleton<Toolbox>; // Permitir acceso al constructor privado  
//   T data;  
//   LinkedListNode<T>* next;  
//
//   LinkedListNode(T value) : data(value), next(nullptr) {}  
//
//   void print() {  
//       std::cout << data << std::endl;  
//       
//   }  
//};

template <typename T>
class LinkedList
{
public:
	LinkedListNode<T>* head;
	LinkedList() : head(nullptr) {}
	void add(T value) {
		LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
		if (!head) {
			head = newNode;
		}
		else {
			LinkedListNode<T>* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	/*void print() {
		LinkedListNode<T>* current = head;
		while (current) {
			current->print();
			current = current->next;
		}
	}*/
};


