# Calculadora Programadora
Calculadora programadora desenvolvida em C como parte da disciplina de Arquitetura de Computadores, ministrada pelo professor Fernando Ferreira de Carvalho no curso de Sistemas de Informação ofertado pela Universidade de Pernambuco (UPE). O projeto realiza conversões entre bases numéricas (decimal, binário, octal, hexadecimal e BCD) e converte números reais em float e double, exibindo passo a passo as operações, incluindo a visualização dos bits de sinal, expoente e fração. 

## Funcionalidades

* Conversão de inteiros para binário, octal e hexadecimal: Exibe o processo passo a passo das conversões e o resultado final.
* Conversão de decimais para BCD: Exibe a conversão dos dígitos de um número decimal em binário e a concatenação do código BCD resultante.
* Conversão de números reais (float e double): Converte a parte inteira e fracionária para binário e exibe os bits detalhados de sinal, expoente e fração.
* Exibição dos bits de números reais: Para os tipos `float` e `double`, exibe os bits de cada parte (sinal, expoente e fração) e calcula a representação normalizada.

## Ferramentas
<div align="left">
  <img src="https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=5cc7e7&color=1b1b1b">
  <img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=5cc7e7&color=1b1b1b">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=5cc7e7&color=1b1b1b">
</div>


## Principais Procedimentos
* `imprimir_binario_inteiro(int n)`<br>
Converte a parte inteira de um número para binário, mostrando o processo detalhado e o resultado final.

* `imprimir_binario_fracionario(float f)`<br>
Converte a parte fracionária de um número float para binário, limitando a 23 bits (precisão do tipo float).

* `imprimir_bits_float(float f)`<br>
Exibe os bits de um número float, incluindo o sinal, o expoente com o viés subtraído e a fração. Também apresenta a representação binária completa.

* `converter_real_para_float(float f)`<br>
Converte um número real float, exibindo tanto a parte inteira quanto a fracionária em binário e os detalhes dos bits de cada parte.

* `imprimir_bits_double(double d)`<br>
Exibe os bits de um número double, incluindo sinal, expoente e fração, com ênfase na representação normalizada e binária completa.

* `converter_real_para_double(double d)`<br>
Converte um número double, exibindo o processo de conversão da parte inteira e fracionária para binário e os bits detalhados de double.

* `decimal_para_binario(int n)`<br>
Converte um número decimal para binário, exibindo cada passo da divisão por 2.

* `decimal_para_octal(int n)`<br>
Converte um número decimal para octal, mostrando cada passo da divisão por 8.

* `decimal_para_hexadecimal(int n)`<br>
Converte um número decimal para hexadecimal, mostrando os valores decimais e suas representações hexadecimais correspondentes (incluindo letras como 'A', 'B', etc.).

* `decimal_para_bcd(int n)`<br>
Converte cada dígito de um número decimal para seu código BCD equivalente, mostrando a conversão de cada dígito decimal para binário e sua concatenação no final.

## Compilação e Execução
### 1. Instale o Git (se ainda não tiver)
Antes de tudo, você precisará do Git instalado na sua máquina para clonar o repositório. Se ainda não tiver o Git instalado, siga os passos abaixo:

* No Windows, baixe o instalador <a href="https://git-scm.com/download/win">aqui.</a>
* No Linux ou macOS, você pode instalar usando o terminal:
  * Linux: `sudo apt-get install git`
  * macOS: `brew install git`

### 2. Instale o GCC (Compilador para C)
Como o projeto é em C, você precisará de um compilador. O GCC é uma boa opção. Para instalar:

* Windows: Baixe o MinGW e siga as instruções de instalação.
* Linux ou macOS: Execute o comando no terminal:
  * Linux: `sudo apt-get install build-essential`
  * macOS: `xcode-select --install` (no macOS o GCC vem junto com o Xcode).
  
### 3. Clone o repositório
Agora, abra o terminal (ou o Git Bash no Windows) e execute o comando abaixo para clonar o repositório do GitHub:
```
git clone https://github.com/gabriellydasi/programmer-calculator.git
```
Isso irá baixar todo o conteúdo do repositório para sua máquina.

### 4. Navegue até o diretório do projeto
Depois de clonar, entre na pasta do projeto:
```
cd programmer-calculator
```

### 5. Compile o código
Com o GCC instalado, compile o arquivo `calculator.c` usando o seguinte comando:
```
gcc calculator.c -o calculator
```
Isso irá compilar o código e gerar um executável chamado calculator.

### 6. Execute o programa
Após a compilação, execute o programa da seguinte maneira:

* No Windows:
```
calculator.exe
```

* No Linux/macOS:
```
./calculator
```

### 7. Interaja com a calculadora
Agora você poderá utilizar a calculadora programador para conversões e outras operações que ela oferece. Basta seguir as instruções exibidas pelo programa.<br><br>
![image](https://github.com/user-attachments/assets/c2511e43-71bd-44ad-ab0d-82efd573cba8)

## Licença
Este projeto é de código aberto e está disponível sob a <a href="https://github.com/gabriellydasi/programmer-calculator/blob/main/LICENSE">licença MIT</a>.

