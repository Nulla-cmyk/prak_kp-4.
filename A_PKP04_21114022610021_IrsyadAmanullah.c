#include <stdio.h>
#include <string.h>

#define MAKS_MAHASISWA 5
#define JUMLAH_MK 3


void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah);
float hitungRataRata(int nilai[][JUMLAH_MK], int index);
char tentukanGrade(float rata);

void tampilkanRapor(
    char nama[][30],
    int nilai[][JUMLAH_MK],
    float rataRata[],
    int jumlah
);

int nilaiTertinggi(int nilai[][JUMLAH_MK], int jumlah);
int nilaiTerendah(int nilai[][JUMLAH_MK], int jumlah);
int mahasiswaTerbaik(float rataRata[], int jumlah);
int cariMahasiswa(char nama[][30], int jumlah, char target[]);


// masukkan data mahasiswa
void inputData(char nama[][30], int nilai[][JUMLAH_MK], int jumlah) {
    int i, j;

    for (i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);

        printf("Nama : ");
        scanf("%29s", nama[i]);

        for (j = 0; j < JUMLAH_MK; j++) {
            if (j == 0) {
                printf("Nilai Algoritma : ");
            } else if (j == 1) {
                printf("Nilai Pemrograman : ");
            } else {
                printf("Nilai Basis Data : ");
            }

            scanf("%d", &nilai[i][j]);
        }
    }
}


// hitung rata2
float hitungRataRata(int nilai[][JUMLAH_MK], int index) {
    int j;
    int total = 0;

    for (j = 0; j < JUMLAH_MK; j++) {
        total += nilai[index][j];
    }

    return (float) total / JUMLAH_MK;
}


// menentukan grade
char tentukanGrade(float rata) {
    if (rata >= 90) {
        return 'A';
    } else if (rata >= 80) {
        return 'B';
    } else if (rata >= 70) {
        return 'C';
    } else if (rata >= 60) {
        return 'D';
    } else {
        return 'E';
    }
}


// menampilkan rapor
void tampilkanRapor(
    char nama[][30],
    int nilai[][JUMLAH_MK],
    float rataRata[],
    int jumlah
) {
    int i, j;

    printf("\n============================================================\n");
    printf("                     RAPOR DIGITAL\n");
    printf("============================================================\n");

    printf("%-15s%-8s%-8s%-8s%-10s%-7s%-12s\n",
           "Nama", "Alg", "Prog", "BD",
           "Rata-rata", "Grade", "Status");

    printf("------------------------------------------------------------\n");

    for (i = 0; i < jumlah; i++) {
        printf("%-15s", nama[i]);

        for (j = 0; j < JUMLAH_MK; j++) {
            printf("%-8d", nilai[i][j]);
        }

        printf("%-10.2f%-7c",
               rataRata[i],
               tentukanGrade(rataRata[i]));

        if (rataRata[i] >= 70) {
            printf("%-12s", "LULUS");
        } else {
            printf("%-12s", "TIDAK LULUS");
        }

        printf("\n");
    }

    printf("============================================================\n");
}


// mencari nilai tertinggi
int nilaiTertinggi(int nilai[][JUMLAH_MK], int jumlah) {
    int i, j;
    int tertinggi = nilai[0][0];

    for (i = 0; i < jumlah; i++) {
        for (j = 0; j < JUMLAH_MK; j++) {
            if (nilai[i][j] > tertinggi) {
                tertinggi = nilai[i][j];
            }
        }
    }

    return tertinggi;
}


// mencari nilai terendah
int nilaiTerendah(int nilai[][JUMLAH_MK], int jumlah) {
    int i, j;
    int terendah = nilai[0][0];

    for (i = 0; i < jumlah; i++) {
        for (j = 0; j < JUMLAH_MK; j++) {
            if (nilai[i][j] < terendah) {
                terendah = nilai[i][j];
            }
        }
    }

    return terendah;
}


// mecari mahasiswa dengan rata2 tertinggi
int mahasiswaTerbaik(float rataRata[], int jumlah) {
    int i;
    int indexTerbaik = 0;

    for (i = 1; i < jumlah; i++) {
        if (rataRata[i] > rataRata[indexTerbaik]) {
            indexTerbaik = i;
        }
    }

    return indexTerbaik;
}


// mencari mahasiswa berdasarkan nama
int cariMahasiswa(char nama[][30], int jumlah, char target[]) {
    int i;

    for (i = 0; i < jumlah; i++) {
        if (strcmp(nama[i], target) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    char nama[MAKS_MAHASISWA][30];
    int nilai[MAKS_MAHASISWA][JUMLAH_MK];
    float rataRata[MAKS_MAHASISWA];

    int jumlah, i;
    int indexTerbaik;
    int indexCari;
    char target[30];

    printf("=============================================\n");
    printf("             SISTEM RAPOR DIGITAL\n");
    printf("=============================================\n");

    // Memasukkan jumlah mahasiswa
    printf("Jumlah mahasiswa (1-%d): ", MAKS_MAHASISWA);
    scanf("%d", &jumlah);

    // Validasi jumlah mahasiswa
    if (jumlah < 1 || jumlah > MAKS_MAHASISWA) {
        printf("Jumlah mahasiswa tidak valid!\n");
        return 0;
    }

    // Memasukkan data mahasiswa
    inputData(nama, nilai, jumlah);

    // Menghitung rata2 setiap mahasiswa
    for (i = 0; i < jumlah; i++) {
        rataRata[i] = hitungRataRata(nilai, i);
    }

    // Menampilkan rapor
    tampilkanRapor(nama, nilai, rataRata, jumlah);

    // Menampilkan statistik
    printf("\nSTATISTIK NILAI\n");
    printf("------------------------------------------------------------\n");

    printf("Nilai tertinggi : %d\n",
           nilaiTertinggi(nilai, jumlah));

    printf("Nilai terendah  : %d\n",
           nilaiTerendah(nilai, jumlah));

    // Mencari mahasiswa terbaik
    indexTerbaik = mahasiswaTerbaik(rataRata, jumlah);

    printf("Mahasiswa terbaik : %s\n",
           nama[indexTerbaik]);

    printf("Rata-rata terbaik  : %.2f\n",
           rataRata[indexTerbaik]);

    // Pencarian mahasiswa
    printf("\nPENCARIAN MAHASISWA\n");
    printf("Masukkan nama yang dicari: ");
    scanf("%29s", target);

    indexCari = cariMahasiswa(nama, jumlah, target);

    if (indexCari != -1) {
        printf("\nData Mahasiswa\n");
        printf("------------------------------------------------------------\n");
        printf("Nama      : %s\n", nama[indexCari]);
        printf("Rata-rata : %.2f\n", rataRata[indexCari]);
        printf("Grade     : %c\n", tentukanGrade(rataRata[indexCari]));

        if (rataRata[indexCari] >= 70) {
            printf("Status    : LULUS\n");
        } else {
            printf("Status    : TIDAK LULUS\n");
        }
    } else {
        printf("Mahasiswa tidak ditemukan.\n");
    }

    return 0;
}