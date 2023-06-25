#include <stdio.h>
#include <stdlib.h>

// İkili arama ağacı düğüm yapısı
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Yeni bir düğüm oluşturma işlevi
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// İkili arama ağacına eleman ekleme işlevi
struct node* insert(struct node* node, int data) {
    // Ağaç boşsa, yeni bir düğüm oluşturarak başlat
    if (node == NULL) return newNode(data);

    // Aksi takdirde, ağaçta yer alacak yeni düğümün yerini belirleyin
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Değiştirilmeyen ağaç kökünü döndür
    return node;
}

// İkili arama ağacını sıralayarak yazdırma işlevi
void inorderTraversal(struct node* node) {
    if (node == NULL) return;  // verilen düğüm NULL ise işlem sonlandırılır.
    inorderTraversal(node->left);  // sol alt ağaca in.
    printf("%d ", node->data); // düğüm verisini yazdırır.
    inorderTraversal(node->right); // sağ alt ağaca in.
}

// Ana fonksiyon
int main() {
    int arr[] = { 6, 2, 8, 4, 7, 1, 3, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    // İlk düğümü oluştur ve diğer düğümleri ekleyin
    struct node* root = NULL;
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        insert(root, arr[i]);

    // İkili arama ağacını sıralayarak yazdır
    inorderTraversal(root);

    return 0;
}
