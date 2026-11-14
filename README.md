# 🐬 Sight Whale

Programa de linha de comando para registrar avistamentos de baleias. A cada registro, o usuário informa a espécie, o local e a atividade observada; o programa acrescenta essas informações, junto com a data, a hora e um código identificador, ao arquivo `whales.txt`. Foi desenvolvido para as aulas de Introduction to the C Programming Language do Centro Paula Souza, ministradas pelo Professor Luciano Gonçalves de Carvalho.

## Tecnologias

- **C** — padrão C99 ou posterior. O código usa recursos da biblioteca padrão, como entrada e saída, manipulação de texto e data/hora.
- **Compilador C** — GCC, Clang ou MSVC. O projeto não fixa uma versão específica do compilador.
- **Visual Studio Code** (opcional) e extensão **C/C++** da Microsoft (opcional) para edição e depuração. O projeto não fixa versões para o editor ou para a extensão.

Não há dependências de terceiros, gerenciador de pacotes ou banco de dados configurados.

## Pré-requisitos

- Um compilador C compatível com C99 ou posterior instalado e disponível no terminal.
- Um terminal: PowerShell no Windows, ou um terminal de shell no macOS/Linux.
- Git para clonar o repositório.
- Opcional: Visual Studio Code e a extensão C/C++ da Microsoft.

## Instalação e compilação

1. Clone o repositório:

   ```sh
   git clone <URL-do-repositorio>
   ```

2. Entre na pasta criada:

   ```sh
   cd c-sight-whale
   ```

3. Compile o programa:

   **Windows (GCC):**

   ```powershell
   gcc main.c -o main.exe
   ```

   **macOS/Linux (GCC ou Clang):**

   ```sh
   gcc main.c -o main
   ```

   Se estiver usando Clang, substitua `gcc` por `clang`. No Windows com MSVC, em um Developer Command Prompt, use:

   ```bat
   cl /W4 main.c
   ```

## Como executar

Execute o binário compilado a partir da pasta do projeto:

**Windows (PowerShell):**

```powershell
.\main.exe
```

**macOS/Linux:**

```sh
./main
```

Informe o código da espécie (1 para Blue, 2 para Humpback ou 3 para Sperm; outros valores são registrados como Other), o local e a atividade. Para cada campo de texto, digite um único termo, sem espaços. Responda `y` à pergunta para encerrar; qualquer outra resposta continua o registro.

Os registros são acrescentados a `whales.txt`, criado no diretório de execução se ainda não existir. Não são necessárias variáveis de ambiente nem configuração de banco de dados.

## Execução pelo Visual Studio Code

Com a extensão C/C++ da Microsoft e um compilador C instalados, abra a pasta do projeto no VS Code e use **F5** se a configuração de depuração do seu ambiente estiver definida para compilar e executar `main.c`.
