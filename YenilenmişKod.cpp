#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int A_SIZE = 20;
const int G_SIZE = 10;
const int MAX_W = 10;

//Max deger icin sonsuz sayi
#define INF INT_MAX

void diziuret(int a[], int size);
void fonksiyon1(int a[], int size);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int fonksiyon2(int a[], int size);
void djifonksiyon3(int g[][G_SIZE], int d[][G_SIZE], int size);
void diziyaz(int a[], int size);
void matrisyaz(int g[][G_SIZE], int size);
void enkisa(int g[][G_SIZE], int size, int t);

int main() {
    int a[A_SIZE];
    int g[G_SIZE][G_SIZE] = {
    { 0, 10,  3,  0,  0,  5,  0, 17,  0, 22},
    {10,  0,  5,  0,  2,  0, 13,  0,  0,  0},
    { 3,  5,  0,  2,  0,  4,  0, 21,  0, 11},
    { 0,  0,  2,  0,  7,  0,  6,  0,  0,  0},
    { 0,  2,  0,  7,  0,  6,  0,  0, 19,  0},
    { 5,  0,  4,  0,  6,  0,  9,  3,  0,  0},
    { 0, 13,  0,  6,  0,  9,  0,  4,  0,  0},
    {17,  0, 21,  0,  0,  3,  4,  0,  8,  0},
    { 0,  0,  0,  0, 19,  0,  0,  8,  0,  5},
    {22,  0, 11,  0,  0,  0,  0,  0,  5,  0}
    };
    int d[G_SIZE][G_SIZE];
    int t;

    // Rastgele sayi uretici icin seed
    srand(time(NULL));

    // Calisma suresinin hesaplanmasi
    clock_t start, end;
    double time;

    start = clock();

    diziuret(a, A_SIZE);
    printf("A:\n");
    diziyaz(a, A_SIZE);

    fonksiyon1(a, A_SIZE);
    printf("\nFunction1 Sonuc:\n");
    diziyaz(a, A_SIZE);

    t = fonksiyon2(a, A_SIZE);
    printf("\nFunction2 Sonuc: %d\n", t);

    printf("\nG:\n");
    matrisyaz(g, G_SIZE);

    djifonksiyon3(g, d, G_SIZE);
    printf("\nFunction3 Sonuc:\n");
    matrisyaz(d, G_SIZE);

    printf("\n%d icin sonuc:\n", t);
    enkisa(d, G_SIZE, t);

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nCalisma Suresi: %f sn\n", time);

    return 0;
}

void diziuret(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (2 * MAX_W) - MAX_W;
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
        

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void fonksiyon1(int a[], int size) {
    mergeSort(a, 0, size - 1);
}

int fonksiyon2(int a[], int size) {
    int t = 0, current_sum = 0, count=0;
    for (int i = 0; i < size; i++) {
        if (current_sum + a[i] > 0) {
            current_sum = current_sum + a[i];
        }
        else {
            current_sum = 0;
        }
        if (current_sum > t) {
            t = current_sum;
            count++;
        }
    }
    return t/count;
}

void dijkstra(int g[][G_SIZE], int src, int d[]) {
    bool sptSet[G_SIZE];

    for (int i = 0; i < G_SIZE; i++) {
        d[i] = INF;
        sptSet[i] = false;
    }

    d[src] = 0;

    for (int count = 0; count < G_SIZE - 1; count++) {
        int u = -1;

        for (int v = 0; v < G_SIZE; v++) {
            if (!sptSet[v] && (u == -1 || d[v] < d[u])) {
                u = v;
            }
        }

        sptSet[u] = true;

        for (int v = 0; v < G_SIZE; v++) {
            if (!sptSet[v] && g[u][v] != 0 && d[u] != 
            INF && d[u] + g[u][v] < d[v]) {
                d[v] = d[u] + g[u][v];
            }
        }
    }
}

void djifonksiyon3(int g[][G_SIZE], int d[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        dijkstra(g, i, d[i]);
    }
}

void diziyaz(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

void matrisyaz(int g[][G_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (g[i][j] == INF) {
                printf("INF ");
            }
            else {
                printf("%3d ", g[i][j]);
            }
        }
        printf("\n");
    }
}

void enkisa(int d[][G_SIZE], int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && d[i][j] < t) {
                printf("%c -> %c: %d\n", 'A' + i, 'A' + j, d[i][j]);
            }
        }
    }
}
