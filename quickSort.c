#include <stdio.h>
// Função para particionar o vetor
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o pivô como o último elemento
    int i = (low - 1);  // Índice do menor elemento
    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor que o pivô
        if (arr[j] < pivot) {
            i++;  // Incrementa o índice do menor elemento
            // Troca os elementos
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Troca o pivô com o elemento após o menor elemento
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);  // Retorna o índice da posição do pivô
}
// Função recursiva para ordenar o vetor
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Encontra o índice de particionamento
        int pi = partition(arr, low, high);
        // Ordena recursivamente as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    // Chama a função de ordenação QuickSort
    quickSort(arr, 0, n - 1);
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    return 0;
}
