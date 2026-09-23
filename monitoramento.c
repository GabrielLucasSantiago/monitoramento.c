#include <stdio.h>

int main() {
    float limite;
    float temperatura;

    float soma = 0.0;
    float maior = 0.0;
    float menor = 0.0;

    int quantidade = 0;
    int acimaDoLimite = 0;
    int consecutivas = 0;

    // ==========================================
    // DEFINIÇÃO E VALIDAÇÃO DO LIMITE
    // ==========================================

    do {
        printf("========================================\n");
        printf("     SISTEMA DE MONITORAMENTO\n");
        printf("========================================\n\n");

        printf("Digite o limite de temperatura (0 a 100): ");
        scanf("%f", &limite);

        if (limite < 0 || limite > 100) {
            printf("\nValor invalido! O limite deve estar entre 0 e 100.\n\n");
        }

    } while (limite < 0 || limite > 100);

    printf("\nLimite definido: %.2f °C\n", limite);
    printf("Digite -999 para encerrar o monitoramento manualmente.\n\n");

    // ==========================================
    // LEITURA DAS TEMPERATURAS
    // ==========================================

    while (consecutivas < 3) {

        printf("Digite a temperatura: ");
        scanf("%f", &temperatura);

        // Permite que o usuário encerre manualmente
        if (temperatura == -999) {
            printf("\nMonitoramento encerrado pelo usuario.\n");
            break;
        }

        // ==========================================
        // VALIDAÇÃO DA TEMPERATURA
        // ==========================================

        if (temperatura < -50 || temperatura > 100) {
            printf("Temperatura invalida! Digite um valor entre -50 e 100 °C.\n\n");

            // Temperatura inválida não entra nos cálculos
            continue;
        }

        // ==========================================
        // CÁLCULOS DAS LEITURAS
        // ==========================================

        quantidade++;
        soma += temperatura;

        // Na primeira leitura válida, inicializamos
        // maior e menor com o próprio valor.
        if (quantidade == 1) {
            maior = temperatura;
            menor = temperatura;
        } else {
            if (temperatura > maior) {
                maior = temperatura;
            }

            if (temperatura < menor) {
                menor = temperatura;
            }
        }

        // ==========================================
        // VERIFICAÇÃO DO LIMITE
        // ==========================================

        if (temperatura > limite) {
            acimaDoLimite++;
            consecutivas++;

            printf("ALERTA: temperatura acima do limite!\n");
            printf("Temperaturas consecutivas acima do limite: %d\n\n",
                   consecutivas);

            // Se chegar a 3 temperaturas consecutivas,
            // o monitoramento será encerrado.
            if (consecutivas == 3) {
                printf("ATENCAO: foram registradas 3 temperaturas ");
                printf("consecutivas acima do limite!\n");
                printf("Monitoramento encerrado automaticamente.\n\n");
            }

        } else {
            // Quando uma temperatura está dentro do limite,
            // a sequência de temperaturas acima do limite é zerada.
            consecutivas = 0;

            printf("Temperatura dentro do limite.\n");
            printf("Contador de consecutivas reiniciado.\n\n");
        }
    }

    // ==========================================
    // RELATÓRIO FINAL
    // ==========================================

    printf("\n========================================\n");
    printf("           RELATORIO FINAL\n");
    printf("========================================\n");

    if (quantidade == 0) {
        printf("Nenhuma temperatura valida foi registrada.\n");
    } else {
        float media = soma / quantidade;
        float percentual = ((float)acimaDoLimite / quantidade) * 100;

        printf("Limite definido: %.2f °C\n", limite);
        printf("Quantidade de leituras: %d\n", quantidade);
        printf("Media das temperaturas: %.2f °C\n", media);
        printf("Maior temperatura: %.2f °C\n", maior);
        printf("Menor temperatura: %.2f °C\n", menor);
        printf("Temperaturas acima do limite: %d\n", acimaDoLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    }

    printf("========================================\n");

    return 0;
}

