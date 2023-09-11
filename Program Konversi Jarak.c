#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char satuanKonversi[15], inputChar[13], option[20], satuanAwal[15],
      satuanAkhir[15], rangeInput[12] = "0123456789.";
  double input, hasilKonversi;
  int menu, valid, validCheck;

  printf("\033[0;32m==========================================================="
         "========\n");
  printf("\t\t\t\t\t  PROGRAM KONVERSI JARAK\n");
  printf(
      "===================================================================\n");
  printf("\t\t\tSelamat datang di Program Konversi Jarak!\033[0m\n\n");

  menu = 1;
  while (menu == 1) {
    printf("1. Mulai Program\n");
    printf("2. Keluar Program\n");
    printf("3. Info\n");
    printf("------------------------------------------------------------\n");
    printf("Pilih menu : ");
    scanf("%s", &option);
    getchar();

    while (strcmp(option, "1") != 0 && strcmp(option, "2") != 0 &&
           strcmp(option, "3") != 0) {
      printf("\033[0;31mInput tidak valid!\033[0m\n");
      break;
      menu = 1;
    }

    while (strcmp(option, "1") == 0) {
      printf("------------------------------------------------------------\n");
      printf("\033[0;32mProgram dimulai...\033[0m\n");
      printf("\n\033[0;36mPilih satuan awal yang ingin dikonversikan\033[0m\n");
      printf("1. Kilometer\n");
      printf("2. Meter\n");
      printf("3. Centimeter\n");
      printf("\n\033[0;36mPilih satuan : ");
      scanf("%s\033[0m", &satuanAwal);
      getchar();

      while (strcmp(satuanAwal, "1") != 0 && strcmp(satuanAwal, "2") != 0 &&
             strcmp(satuanAwal, "3") != 0) {
        printf("\033[0;31mInput tidak valid, pilih satuan awal yang ingin "
               "dikonversikan : \033[0m\n");
        printf("1. Kilometer\n");
        printf("2. Meter\n");
        printf("3. Centimeter\n");
        printf("\n\033[0;36mPilih satuan : ");
        scanf("%s\033[0m", &satuanAwal);
        getchar();
      }

      printf("\n\033[0;36mPilih satuan konversi akhir\033[0m\n");
      printf("1. Kilometer\n");
      printf("2. Meter\n");
      printf("3. Centimeter\n");
      printf("\n\033[0;36mPilih satuan : ");
      scanf("%s\033[0m", &satuanAkhir);
      getchar();

      while (strcmp(satuanAkhir, "1") != 0 && strcmp(satuanAkhir, "2") != 0 &&
             strcmp(satuanAkhir, "3") != 0) {
        printf("\033[0;31mInput tidak valid, pilih satuan akhir yang ingin "
               "dikonversikan : \033[0m\n");
        printf("1. Kilometer\n");
        printf("2. Meter\n");
        printf("3. Centimeter\n");
        printf("\n\033[0;36mPilih satuan : ");
        scanf("%s\033[0m", &satuanAkhir);
        getchar();
      }

      validCheck = 0;
      while (validCheck == 0) {
        valid = 0;
        printf("\033[0;36mMasukkan nilai jarak yang akan dikonversi : ");
        scanf("%s\033[0m", &inputChar);
        getchar();

        for (int m = 0; m < strlen(inputChar); m++) {
          for (int n = 0; n < strlen(rangeInput); n++) {
            if (inputChar[m] == rangeInput[n]) {
              valid++;
            }
          }
        }
        if (valid == strlen(inputChar)) {
          validCheck = 1;
        }
        while (valid != strlen(inputChar)) {
          printf("\033[0;31mInput tidak valid, hanya diizinkan angka bulat dan "
                 "desimal\033[0m\n");
          valid = 0;
          validCheck = 0;
          break;
        }
      }

      input = atof(inputChar);
      if (strcmp(satuanAwal, "1") == 0 && strcmp(satuanAkhir, "2") == 0) {
        hasilKonversi = input * 1000;
        strcpy(satuanKonversi, "meter");
      } else if (strcmp(satuanAwal, "1") == 0 &&
                 strcmp(satuanAkhir, "3") == 0) {
        hasilKonversi = input * 100000;
        strcpy(satuanKonversi, "centimeter");
      } else if (strcmp(satuanAwal, "2") == 0 &&
                 strcmp(satuanAkhir, "1") == 0) {
        hasilKonversi = input / 1000;
        strcpy(satuanKonversi, "kilometer");
      } else if (strcmp(satuanAwal, "2") == 0 &&
                 strcmp(satuanAkhir, "3") == 0) {
        hasilKonversi = input * 100;
        strcpy(satuanKonversi, "centimeter");
      } else if (strcmp(satuanAwal, "3") == 0 &&
                 strcmp(satuanAkhir, "1") == 0) {
        hasilKonversi = input / 100000;
        strcpy(satuanKonversi, "kilometer");
      } else if (strcmp(satuanAwal, "1") == 0 &&
                 strcmp(satuanAkhir, "1") == 0) {
        hasilKonversi = input;
        strcpy(satuanKonversi, "kilometer");
      } else if (strcmp(satuanAwal, "2") == 0 &&
                 strcmp(satuanAkhir, "2") == 0) {
        hasilKonversi = input;
        strcpy(satuanKonversi, "meter");
      } else if (strcmp(satuanAwal, "3") == 0 &&
                 strcmp(satuanAkhir, "3") == 0) {
        hasilKonversi = input;
        strcpy(satuanKonversi, "centimeter");
      }
      // m = input*1000.00;
      // cm = input*100000.00;
      printf("\n\033[0;32m====================================================="
             "==============");
      printf("\nHasil konversi jarak adalah : %.4lf %s", hasilKonversi,
             satuanKonversi);
      printf("\n==============================================================="
             "===\033[0m\n");
      printf(
          "\n\nApakah Anda ingin memulai program kembali? (1 Ya / 2 Tidak) : ");
      scanf("%s", &option);
    }

    while (strcmp(option, "3") == 0) {
      printf("------------------------------------------------------------\n");
      printf("Program ini merupakan program konversi nilai jarak dari dan ke "
             "satuan\nkilometer (km), meter (m) dan centimeter (cm).\n");
      printf("Program dibuat untuk memenuhi tugas personal 1 mata "
             "kuliah\nAlgorithm and Programming yang diampu oleh dosen bapak "
             "Tri Asih Budiono.\n");
      printf("\n\033[0;36mProgram dibuat oleh : \n");
      printf("Nama\t\t: Wahyu Mentari Mayadita\n");
      printf("NIM\t\t\t: 2702347723\n");
      printf("Kelas\t\t: JCCA\033[0m\n");
      printf("------------------------------------------------------------\n");
      printf("Apakah Anda ingin memulai program? (1 Ya / 2 Tidak) : ");
      scanf("%s", &option);
    }
    if (strcmp(option, "2") == 0) {
      menu = 2;
    }
  }

  if (menu == 2) {
    printf("\033[0;32m\nMengakhiri program...\033[0m");
  }

  return 0;
}
