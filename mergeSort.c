#include <stdio.h>

// Função para mesclar duas metades de um vetor
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // Tamanho da primeira metade
    int n2 = r - m;      // Tamanho da segunda metade
    // Vetores temporários
    int L[n1], R[n2];
    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    // Mescla os vetores L[] e R[] de volta em arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Função recursiva para ordenar o vetor
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Encontra o ponto médio
        mergeSort(arr, l, m);       // Ordena a primeira metade
        mergeSort(arr, m + 1, r);   // Ordena a segunda metade
        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
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
    // Chama a função de ordenação MergeSort
    mergeSort(arr, 0, n - 1);
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    return 0;
}
