#include <stdio.h>

// Função para implementar o algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Percorre o vetor da segunda posição até o final
    for (i = 1; i < n; i++) {
        key = arr[i];  // O elemento a ser inserido na parte ordenada do vetor
        j = i - 1;
        // Move os elementos da parte ordenada do vetor para a direita
        // enquanto eles forem maiores que o valor da chave
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insere o elemento da chave na posição correta
        arr[j + 1] = key;
    }
}
// Função para imprimir um vetor
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    // Solicita ao usuário o número de elementos
    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    int arr[n];  // Cria um vetor de tamanho n
    // Solicita ao usuário os valores do vetor
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Vetor original: \n");
    printArray(arr, n);
    // Chama a função de ordenação Insertion Sort
    insertionSort(arr, n);
    printf("Vetor ordenado: \n");
    printArray(arr, n);

    return 0;
}
