# Indexador e Buscador de Palavras

Este projeto é um indexador e buscador de palavras implementado em C. Ele lê um arquivo de texto, indexa todas as palavras únicas utilizando uma estrutura de dados escolhida pelo usuário e permite realizar buscas eficientes para encontrar em quais linhas as palavras aparecem.

## Funcionalidades

- **Indexação de Palavras:** Lê um arquivo de texto e armazena as palavras e suas ocorrências (linhas).
- **Múltiplas Estruturas de Dados:** Suporta três tipos de estruturas para indexação:
    - Árvore Binária (`arvore`)
    - Lista Ligada (`lista`)
    - Tabela Hash (`hash`)
- **Busca Interativa:** Interface de linha de comando para buscar palavras e visualizar resultados.
- **Estatísticas:** Exibe o número de comparações realizadas durante a indexação e busca.

## Como Compilar e Rodar

### Pré-requisitos

- Compilador GCC
- Make

### Compilação

Para compilar o projeto, execute o comando `make` na raiz do diretório:

```bash
make
```

Isso irá gerar o executável `main` dentro da pasta `build/`.

### Execução

Para rodar o programa, utilize o seguinte formato:

```bash
./build/main <arquivo_de_texto> <tipo_de_estrutura>
```

- `<arquivo_de_texto>`: Caminho para o arquivo que deseja indexar (ex: `texto_pequeno.txt`, `texto_medio.txt`, `texto_grande.txt`).
- `<tipo_de_estrutura>`: Estrutura de dados a ser utilizada. Opções:
    - `arvore`
    - `lista`
    - `hash`

**Exemplo:**

```bash
./build/main texto_pequeno.txt arvore
```

## Comandos Disponíveis

Após iniciar o programa, você pode utilizar os seguintes comandos no prompt `> `:

- `busca <palavra>`: Procura por uma palavra dentro do texto e exibe as linhas onde ela ocorre.
- `print`: Imprime todas as palavras indexadas.
- `help`: Mostra a lista de comandos disponíveis.
- `fim`: Encerra o programa.

**Exemplo de uso:**

```text
> busca casa
Existe(m) 2 ocorrencia(s) da palavra 'casa' na(s) seguinte(s) linha(s):
00001: Era uma casa muito engracada
00004: Porque na casa nao tinha chao.
Numero de comparacoes: 12
> fim
```