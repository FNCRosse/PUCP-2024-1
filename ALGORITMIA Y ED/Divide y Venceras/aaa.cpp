#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Función para insertar el nodo 34 en la posición correcta
Node* insert34(Node* root, int key) {
    if (!root) return new Node(key);
    
    // Recorrer el árbol hasta encontrar el nodo 40
    if (root->data == 40) {
        // Insertar el nodo 34 entre el nodo 40 y 25
        Node* temp = root->left;
        root->left = new Node(key);
        root->left->left = temp;
        return root;
    }
    
    // Continuar la búsqueda en el subárbol correspondiente
    if (key < root->data) {
        root->left = insert34(root->left, key);
    } else {
        root->right = insert34(root->right, key);
    }
    return root;
}

void preOrder(Node* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    // Crear el árbol inicial
    Node* root = new Node(52);
    root->left = new Node(40);
    root->right = new Node(60);
    root->left->left = new Node(25);
    root->left->right = new Node(42);

    std::cout << "Preorder before insertion: ";
    preOrder(root);
    std::cout << std::endl;

    // Insertar 34 en la posición correcta
    root = insert34(root, 34);

    std::cout << "Preorder after insertion: ";
    preOrder(root);
    std::cout << std::endl;

    return 0;
}

