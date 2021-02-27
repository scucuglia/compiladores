# Trabalho Final de Compiladores

## Grupo

Julia Palmeira Scucuglia - RA 102030

Murilo Holtz Foltran - RA 133770

## Ambiente
O código foi construído em ambiente Linux na linguagem C, utilizando as ferramentas `flex` e `bison`.

## Antes de rodar o codigo
Antes de rodar o código, é necessário ter instalado também a ferramenta `make`, que vai nos auxiliar na hora de rodar o código.

Para instalar a ferramenta, é só dar um
```sh
sudo apt-get install make
```

## Para rodar o codigo
Para criar o compilador `cminus`, é só utilizar o comando
```sh
make all
```

Para compilar um código, por exemplo o `exemplo/gcd.cm`, é só fazer
```sh
./cminus exemplo/gcd.cm
```
