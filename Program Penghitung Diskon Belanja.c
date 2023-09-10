#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int error, start =1, input, validCheck, valid, countTransaksi = 0, diskon, totalBelanja = 0, totalDiskon = 0, loyalty = 0, totalLoyalty = 0;
	char pilihan[10], inputChar[13];
		printf("\033[0;32m====================================================\n");
		printf("\tPROGRAM PENGHITUNG DISKON BELANJA\n");
		printf("====================================================\n");
		printf("Selamat datang di Program Penghitung Diskon Belanja!\033[0m\n");
		while(start == 1)
			{	strcpy(pilihan, "1");
				while(strcmp(pilihan, "1") == 0)
				{	
					valid = 0;
					validCheck = 1;
					while(validCheck == 1)
					{
					printf("\n====================================================\nNilai belanja : Rp. ");
					scanf("%s", &inputChar);getchar();
					for (int i = 0; i < strlen(inputChar); i++)
					{
      					if (isdigit(inputChar[i])) {
        				valid++;
      					}
    				}
					while (valid != strlen(inputChar))
					{
      					printf("\033[0;31mNilai tidak valid, input nilai belanja dengan benar!\033[0m\n");
      					valid = 0;
      					break;
    				}
    				if (valid == strlen(inputChar))
					{
      					validCheck = 2;
    				}					
					}
					input = atol(inputChar);
					countTransaksi++;
					totalBelanja += input;
					printf("Pembelian ke : %d\n--------------------------\n", countTransaksi);
					if(input < 200000 && countTransaksi % 4 != 0)
					{	diskon = 0;
						loyalty = 0;
						printf("\033[0;31mMohon maaf Anda tidak mendapat diskon.\033[0m\n");
					}else
					if(input >= 200000 && input < 500000 && countTransaksi % 4 != 0)
					{	diskon = input*0.1;
						loyalty = 0;
						printf("\033[0;32mSelamat! Anda mendapat diskon 10%%!\033[0m\n");
					}else
					if(input >= 500000 && input < 1000000 && countTransaksi % 4 != 0)
					{	diskon = input*0.2;
						loyalty = 0;
						printf("\033[0;32mSelamat! Anda mendapat diskon 20%%!\033[0m\n");
					}else
					if(input >= 1000000 && countTransaksi % 4 != 0)
					{	diskon = input*0.3;
						loyalty = 0;
						printf("\033[0;32mSelamat! Anda mendapat diskon 30%%!\033[0m\n");
					}else
					if(input < 200000 && countTransaksi % 4 == 0)
					{	loyalty = 0.2*input;
						printf("\033[0;32mSelamat! Anda mendapatkan diskon loyalty sebesar 20%%!\033[0m\n");
					}else
					if(input >= 200000 && input < 500000 && countTransaksi % 4 == 0)
					{	diskon = input*0.1;
						loyalty = 0.2*(input-diskon);
						printf("\033[0;32mSelamat! Anda mendapatkan diskon belanja sebesar 10%% dan diskon loyalty sebesar 20%%!\033[0m\n");
					}else
					if(input >= 500000 && input < 1000000 && countTransaksi % 4 == 0)
					{	diskon = input*0.2;
						loyalty = 0.2*(input-diskon);
						printf("\033[0;32mSelamat! Anda mendapatkan diskon belanja sebesar 20%% dan diskon loyalty sebesar 20%%!\033[0m\n");
					}else
					if(input >= 1000000 && countTransaksi % 4 == 0)
					{	diskon = input*0.3;
						loyalty = 0.2*(input-diskon);
						printf("\033[0;32mSelamat! Anda mendapatkan diskon belanja sebesar 30%% dan diskon loyalty sebesar 20%%!\033[0m\n");
					}else
					{
						break;
					}
					totalDiskon +=  diskon;
					totalLoyalty += loyalty;
					printf("Nilai belanja\t: Rp. %d\n", input);
					printf("Diskon\t\t: Rp. %d\n", diskon);
					printf("Diskon loyalty\t: Rp. %d\n", loyalty);
					printf("Apakah anda ingin menambah transaksi? (1 Ya/2 Tidak) : ");
					scanf("%s", &pilihan);getchar();
				}
				while(strcmp(pilihan, "1") != 0 && strcmp(pilihan, "2") != 0) 
				{	printf("\033[0;31mInput tidak valid.\033[0m\n");
					printf("Apakah anda ingin menambah transaksi? (1 Ya/2 Tidak) : ");
					scanf("%[^\n]", &pilihan);getchar();
				}				
				if(strcmp(pilihan, "2") == 0)
				{	printf("\n\n\033[0;36m====================================================\n");
					printf("\t\t   REKAP BELANJA\n");
					printf("====================================================\n");
					printf("Jumlah transaksi\t: %d kali\n", countTransaksi);
					printf("Total belanja\t\t: Rp. %d", totalBelanja);
					printf("\nTotal diskon\t\t: Rp. %d", totalDiskon);
					printf("\nTotal diskon loyalty\t: Rp. %d", totalLoyalty);
					printf("\nTotal pembayaran\t: Rp. %d\033[0m", totalBelanja - totalDiskon - totalLoyalty);
					start = 0;
				}
			}
		if(start == 0)
		{	printf("\n\n====================================================\n");
			printf("     Terima kasih telah berbelanja di toko kami!");
			printf("\n====================================================\n");
		}
	return 0;
}
