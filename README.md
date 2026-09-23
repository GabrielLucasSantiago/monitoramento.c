# Projeto de Monitoramento de Temperatura

## 1. Identificação

**Aluno:** Gabriel Lucas Santiago Gonçalves 
**Disciplina:** Algoritmos e pensamentos computacional  
**Professora:** Profa. Karla Sartin  
**Título do projeto:** Sistema de Monitoramento de Temperatura

---

## 2. Objetivo

O objetivo deste projeto é desenvolver um programa em linguagem C capaz de realizar o monitoramento de temperaturas informadas pelo usuário.

O programa permite definir um limite de temperatura, receber diversas leituras, identificar temperaturas acima desse limite e controlar a ocorrência de temperaturas elevadas consecutivas.

O monitoramento é encerrado automaticamente quando são registradas três temperaturas consecutivas acima do limite definido.

---

## 3. Funcionamento do programa

### Definição do limite de temperatura

Inicialmente, o programa solicita ao usuário que informe o limite de temperatura.

O limite deve estar entre 0 °C e 100 °C. Caso seja informado um valor fora desse intervalo, o programa informa que o valor é inválido e solicita uma nova entrada.

Foi utilizado o laço `do...while` para garantir que o usuário informe um limite válido antes de iniciar o monitoramento.

### Leitura das temperaturas

Após definir o limite, o programa começa a solicitar as temperaturas.

As temperaturas válidas devem estar entre -50 °C e 100 °C.

O usuário também pode digitar `-999` para encerrar manualmente o monitoramento.

### Tratamento de valores inválidos

Quando uma temperatura fora do intervalo permitido é informada, o programa apresenta uma mensagem de erro e solicita uma nova temperatura.

As temperaturas inválidas não são consideradas nos cálculos do relatório final.

### Identificação de temperaturas acima do limite

Cada temperatura válida é comparada com o limite definido pelo usuário.

Quando a temperatura é maior que o limite, o programa apresenta uma mensagem de alerta e incrementa a quantidade de temperaturas acima do limite.

Quando a temperatura está dentro do limite, o contador de temperaturas consecutivas acima do limite é reiniciado.

### Contagem de temperaturas consecutivas

O programa possui um contador responsável por verificar quantas temperaturas acima do limite foram registradas consecutivamente.

A cada temperatura acima do limite, o contador é incrementado.

Quando uma temperatura igual ou inferior ao limite é registrada, o contador volta para zero.

Quando o contador chega a três, o programa encerra automaticamente o monitoramento.

### Condição de encerramento

O monitoramento pode ser encerrado de duas formas:

1. Automaticamente, quando são registradas três temperaturas consecutivas acima do limite.
2. Manualmente, quando o usuário informa o valor `-999`.

Ao final, o programa apresenta um relatório contendo os resultados das leituras realizadas.

---

## 4. Estruturas de repetição utilizadas

### `do...while`

O `do...while` foi utilizado na definição do limite de temperatura.

Essa estrutura foi escolhida porque o programa precisa solicitar o limite pelo menos uma vez e continuar solicitando enquanto o valor informado for inválido.

### `while`

O `while` foi utilizado para realizar o monitoramento das temperaturas.

O programa continua recebendo novas temperaturas enquanto o contador de temperaturas consecutivas acima do limite for menor que três.

A utilização do `while` permite que o monitoramento seja repetido até que uma das condições de encerramento seja atingida.

---

## 5. Como executar

Para compilar o programa, é necessário possuir um compilador da linguagem C, como o GCC.

No terminal, dentro da pasta do projeto, execute:

```bash
gcc monitoramento.c -o monitoramento
