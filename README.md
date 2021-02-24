# Projeto de Compiladores

## Instalações
Antes de rodar, instale:
```sh
sudo apt-get update # se necessario

sudo apt-get install gcc # se nao tiver o gcc instalado

sudo apt-get install flex bison make
```

## Como rodar
Para rodar, tem que garantir que tá tudo instalado.

```sh
make all # para compilar e gerar o compilador cminus

./cminus exemplo/gcd.c # utilizar o compilador cminus para compilar o arquivo de exemplo
```

## Módulos a serem construídos
---
### Analisador Léxico - Scanner

O analisador léxico está definido no arquivo `cminus.l` e deve ser rodado utilizando o `flex`.

Precisamos:

[ ] mudar a ordem das coisas e talvez alguns nomes, sempre lembrando de refletir nos outros arquivos

---

### Analisador Sintático - Parser
O analisador sintático está definido no arquivo `cminus.y` e deve ser rodado utilizando o `bison` 

Precisamos:

[ ] melhorar o formato dos prints

[ ] remover o codigo comentado

[ ] estruturar conteudo de dentro das declarações (se der)

****ATENÇÃO! Não mexer na ordem das declarações!!**

---

### Gerenciador de tabelas de símbolos

Se não me engano tá no `symtab.c`, mas não tenho certeza. Sei que tem uma função `void printSymTab` lá que printa a tabela de simbolos. 

---

### Analisador Semântico

O analisador semântico está no arquivo `analyze.c`. 

Precisamos:

[ ] verificar se os codigos comentados influenciam no trabalho

[ ] 

---

### Arvore Sintática

A arvore sintatica parece estar no arquivo `symtab.c`.


Precisamos:

[ ] verificar se a arvore sintatica que esta sendo printada está correta

[ ] 

---

### Gerador de código intermediario

Provavelmente, isso estava no arquivo `cgen.c` do `loucomp.rar` da professora.

Precisamos:

[ ] descobrir como gerar esse codigo intermediario