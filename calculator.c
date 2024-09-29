/* 
  Autor: Gabrielly Silva
  Email: gabrielly.silvao@upe.br
  Data de criação: 14/09/2024
  Última atualização: 29/09/2024 13:35
  Descrição: Calculadora programadora que converte números em diferentes bases e realiza conversões de ponto flutuante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Procedimentos para conversões (incluindo implementações de base 10 para binário, octal, hexadecimal e BCD)
// Procedimentos de impressão de bits de float e double

// Função para imprimir a parte inteira em binário
void imprimir_binario_inteiro(int n) {
    int binario[16];
    int i = 0;
    
    n = abs(n); // Usar o valor absoluto

    if (n == 0) {
        printf("0");
        return;
    }

    printf("\nPasso a passo da conversao da parte inteira para binario:\n");
    while (n > 0) {
        binario[i] = n % 2;
        printf("%d / 2 = %d com resto %d\n", n, n / 2, binario[i]);
        n = n / 2;
        i++;
    }

    printf("\nParte inteira em binario: ");
    
    int j;
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n\n");
}

// Função para imprimir a parte fracionária em binário para float
void imprimir_binario_fracionario(float f) {
    printf("\nPasso a passo da conversao da parte fracionaria para binario:\n");

    float frac = fabs(f) - (int)fabs(f); // Usar o valor absoluto
    int count = 0;
    int bit;

    while (frac > 0 && count < 23) { // Limite de 23 bits para float
        frac *= 2;
        bit = (int)frac;
        printf("%.15f * 2 = %.15f com parte inteira %d\n", frac / 2, frac, bit);
        frac -= bit;
        count++;
    }

    printf("\nParte fracionaria em binario: ");
    
    int i;
    for (i = 0; i < 23; i++) {
        printf("%d", (int)(fabs(f) * pow(2, i)) % 2); // Usar o valor absoluto
    }
    printf("\n");
}

// Função para imprimir os bits de float e suas partes
void imprimir_bits_float(float f) {
    unsigned int *ptr = (unsigned int*)&f;
    int sinal, expoente;
    unsigned int fracao;

    sinal = (*ptr >> 31) & 1; // Considera o sinal do número original
    expoente = (*ptr >> 23) & 0xFF;
    fracao = (*ptr & 0x7FFFFF);  // Máscara para a mantissa

    // Exibir o sinal
    printf("\nSinal: %d\n", sinal);

    // Exibir o expoente
    printf("Expoente: ");
    
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf(" (Decimal: %d - 127 = %d)\n", expoente, expoente - 127);

    // Exibir a fração
    printf("Fracao: ");
    for (i = 22; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf("\n");

    // Calcular e exibir a normalização
    int expoente_real = expoente - 127;
    printf("\nRepresentar o numero em forma normalizada:\n");
    printf("Em forma normalizada: 1.");
    
    for (i = 22; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf(" x 2^%d\n", expoente_real);

    // Exibir a representação binária completa
    printf("\nRepresentacao binaria em float: ");
    printf("%d", sinal);
    
    for (i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    for (i = 22; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf("\n\n");
}

// Função para converter e mostrar float
void converter_real_para_float(float f) {
    printf("\nNumero convertido para float: %f\n", f);
    printf("Parte inteira: %d\n", (int)fabs(f)); // Usar o valor absoluto
    imprimir_binario_inteiro((int)fabs(f)); // Usar o valor absoluto
    imprimir_binario_fracionario(f);
    imprimir_bits_float(f);
}

// Função para imprimir os bits de double e suas partes
void imprimir_bits_double(double d) {
    unsigned long long *ptr = (unsigned long long*)&d;
    int sinal, expoente;
    unsigned long long fracao;

    sinal = (*ptr >> 63) & 1; // Considera o sinal do número original
    expoente = (*ptr >> 52) & 0x7FF;
    fracao = (*ptr & 0xFFFFFFFFFFFFF);  // Máscara para a mantissa

    // Exibir o sinal
    printf("\nSinal: %d\n", sinal);

    // Exibir o expoente
    printf("Expoente: ");
    
    int i;
    for (i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    printf(" (Decimal: %d - 1023 = %d)\n", expoente, expoente - 1023);

    // Exibir a fração
    printf("Fracao: ");
    for (i = 51; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf("\n");

    // Calcular e exibir a normalização
    int expoente_real = expoente - 1023;
    printf("\nRepresentar o numero em forma normalizada:\n");
    printf("Em forma normalizada: 1.");
    for (i = 51; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf(" x 2^%d\n", expoente_real);

    // Exibir a representação binária completa
    printf("\nRepresentacao binaria em double: ");
    printf("%d", sinal);
    for (i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }
    for (i = 51; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
    printf("\n\n");
}

// Função para converter e mostrar double
void converter_real_para_double(double d) {
    printf("\nNumero convertido para double: %lf\n", d);
    printf("Parte inteira: %d\n", (int)fabs(d)); // Usar o valor absoluto
    imprimir_binario_inteiro((int)fabs(d)); // Usar o valor absoluto
    printf("\nParte fracionaria em binario:\n");

    double frac = fabs(d) - (int)fabs(d); // Usar o valor absoluto
    int count = 0;
    int bit;

    while (frac > 0 && count < 52) { // Limite de 52 bits para double
        frac *= 2;
        bit = (int)frac;
        printf("%.15lf * 2 = %.15lf com parte inteira %d\n", frac / 2, frac, bit);
        frac -= bit;
        count++;
    }

    printf("\nParte fracionaria em binario: ");
    
    int i;
    for (i = 0; i < 52; i++) {
        printf("%d", (int)(fabs(d) * pow(2, i)) % 2); // Usar o valor absoluto
    }
    printf("\n");

    imprimir_bits_double(d);
}

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
	int numero;
    int opcao;
	double real;
	
	while(opcao !=3) {
			printf("---------- CALCULADORA CONVERSORA ----------\n\n");
        	printf("1 - Converter de base 10 para outras bases\n");
            printf("2 - Converter um numero real em float e double\n");
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
                				break; // N�o define base_valida como 1, portanto o loop continua
        				}
    				} while (!base_valida); // Continua pedindo uma opção válida
					break;
				
				case 2:
					printf("\nDigite um numero real: ");
                    scanf("%lf", &real);
                    converter_real_para_float((float)real);
                    converter_real_para_double(real);
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