/* 
  Autor: Gabrielly Silva
  Email: gabrielly.silvao@upe.br
  Data de criação: 14/09/2024
  Última atualização: 19/09/2024 19:22
  Descrição: Calculadora programadora que converte números em diferentes bases e realiza conversões de ponto flutuante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Procedimentos para conversões de base 10 para outras bases e BCD

void decimal_para_binario(int n) {
    int binario[32];
    int i = 0;
    
    // Converte decimal para binário
    printf("\nPasso a passo da conversao de decimal para binario:\n");
    while(n > 0){
        binario[i] = n % 2;
        printf("Dividindo %d por 2, resto = %d\n", n, binario[i]);
        n = n / 2;
        i++;
    }
    
    // Imprime o binário equivalente
    printf("\nO binario equivalente e: ");
    int j;
    for(j = i - 1; j >= 0; j--){
        printf("%d", binario[j]);
    }
    printf("\n\n\n");
}

void decimal_para_octal(int n) {
    if (n <= 0) {
        printf("\nNumero deve ser maior que 0.\n\n");
        return;
    }

    int octal[32];
    int i = 0;
    
    // Converte decimal para octal
    printf("\nPasso a passo da conversao de decimal para octal:\n");
    while (n > 0) {
        octal[i] = n % 8;
        printf("Dividindo %d por 8, resto = %d\n", n, octal[i]);
        n = n / 8;
        i++;
    }
    
    // Imprime o octal equivalente
    printf("\nO octal equivalente e: ");
    int j;
    for(j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n\n\n");
}

void decimal_para_hexadecimal(int n) {
    char hexadecimal[32];
    int i = 0;
    
    // Converte decimal para hexadecimal
    printf("\nPasso a passo da conversao de decimal para hexadecimal:\n");
    while (n > 0) {
        int resto = n % 16;
        char hex_digit;

        if (resto < 10) {
            hex_digit = 48 + resto; // '0' + resto
        } else {
            hex_digit = 55 + resto; // 'A' + (resto - 10)
        }

        // Exibe o valor decimal e a representação hexadecimal correspondente
        printf("Dividindo %d por 16, resto = %d (hexadecimal %c)\n", n, resto, hex_digit);
        
        hexadecimal[i] = hex_digit;
        n = n / 16;
        i++;
    }
    
    // Imprime o hexadecimal equivalente
    printf("\nO hexadecimal equivalente e: ");
    int j;
    for(j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n\n\n");
}

void decimal_para_bcd(int n) {
    printf("\nPasso a passo da conversao de decimal para BCD:\n");

    // Array para armazenar os dígitos decimais
    int decimal_digitos[10];
    int i = 0;

    // Converte o número decimal em seus dígitos individuais
    while (n > 0) {
        decimal_digitos[i] = n % 10;
        n = n / 10;
        i++;
    }

    // Exibe a conversão de cada dígito decimal para binário e BCD
    printf("\nConversao de cada digito para BCD:\n");
    
    int j;
	for (j = i - 1; j >= 0; j--) {
        int digito = decimal_digitos[j];
        
        // Mostrar conversão de decimal para binário
        printf("\nDigito decimal: %d\n", digito);
        printf("\nPasso a passo da conversao de %d para binario:\n", digito);
        int temp = digito;
        int binario[4];
        int k;
        for (k = 0; k < 4; k++) {
            binario[k] = temp % 2;
            printf("%d / 2 = %d com resto %d\n", temp, temp / 2, binario[k]);
            temp = temp / 2;
        }
        
        // Imprime o binário do dígito decimal
        printf("\nBinario do digito decimal %d: ", digito);
        for (k = 3; k >= 0; k--) {
            printf("%d", binario[k]);
        }
        printf("\n");
        
        // Imprime a conversão para BCD
        printf("Conversao para BCD: ");
        for (k = 3; k >= 0; k--) {
            printf("%d", binario[k]);
        }
        printf("\n");
    }

    // Exibe a concatenação final dos códigos BCD
    printf("\n\nRepresentacao final em BCD: ");
    
	for (j = i - 1; j >= 0; j--) {
        int digito = decimal_digitos[j];
        int k;
        
		for (k = 3; k >= 0; k--) {
            printf("%d", (digito >> k) & 1);
        }
    }
    printf("\n\n\n");
}

// Função principal do programa
int main() {
	int numero, opcao, base;
	double real;
	
	while(opcao !=3) {
			printf("---------- CALCULADORA CONVERSORA ----------\n\n");
        	printf("1 - Converter de base 10 para outras bases\n");
            printf("3 - Sair\n");
            printf("\nDigite a opcao desejada: ");
            scanf("%d", &opcao);
            
            switch(opcao){
            	case 1:
    			// Conversões de base 10 para outras bases
    				printf("\nDigite um numero inteiro em decimal: ");
    				scanf("%d", &numero);
    
   					int base;
    				int base_valida = 0; // Flag para verificar se a base é válida
    
    				do {
        				// Solicita a escolha da base
        				printf("\nSelecione a base de conversao:\n");
        				printf("1 - Base 2\n");
        				printf("2 - Base 8\n");
        				printf("3 - Base 16\n");
        				printf("4 - Codigo BCD\n\n");
        				scanf("%d", &base);
        
        				switch (base) {
            				case 1:
                				decimal_para_binario(numero);
                				base_valida = 1; // Marca que a base é válida
                				break;
            				case 2:
                				decimal_para_octal(numero);
                				base_valida = 1; // Marca que a base é válida
                				break;
            				case 3:
                				decimal_para_hexadecimal(numero);
                				base_valida = 1; // Marca que a base é válida
                				break;
            				case 4:
                				decimal_para_bcd(numero);
                				base_valida = 1; // Marca que a base é válida
                				break;
            				default:
                				printf("\nErro! Por favor, digite uma opcao valida.\n\n");
                				break; // Não define base_valida como 1, portanto o loop continua
        				}
    				} while (!base_valida); // Continua pedindo uma opção válida
					break;
					
				case 3:
					printf("\nEncerrando...");
					return 0;
					
				default:
					printf("\nErro! Por favor, digite uma opcao valida.\n\n\n");
					continue;
			}
		}
	
	return 0;
}