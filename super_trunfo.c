#include <stdio.h>
#include <string.h>

int main(){
    /* Variáveis para Carta 1*/
    char estado_1, codigo_carta_1[5], nome_cidade_1[20];
    int populacao_1, numero_pontos_turisticos_1;
    double area_km_1, pib_1;

    /* Variáveis para Carta 2*/
    char estado_2, codigo_carta_2[5], nome_cidade_2[20];
    int populacao_2, numero_pontos_turisticos_2;
    double area_km_2, pib_2;

    /* Pegar informações para Carta 1*/
    printf("Qual a letra que representa o Estado para esta carta? (Entre 'A' e 'H') ");
    scanf("%c", &estado_1);
    getchar();
    printf("Qual o código da carta? (Letra do estado e número entre 01 e 04) ");
    fgets(codigo_carta_1, 4, stdin);
    codigo_carta_1[strcspn(codigo_carta_1, "\n")] = 0;
    printf("Agora, qual o nome da cidade? "); 
    fgets(nome_cidade_1, 20, stdin); //Usamos fgets por ter espaços entre as palavras da string
    /* Limparemos 'nome_cidade' do valor que pode ter sido inserido "\n" na string */
    nome_cidade_1[strcspn(nome_cidade_1, "\n")] = 0;
    printf("Qual a população da cidade da carta? ");
    scanf("%d", &populacao_1);
    printf("Qual sua área, em km²? ");
    scanf("%lf", &area_km_1);
    printf("E seu PIB? ");
    scanf("%lf", &pib_1);
    printf("Por último, quantos pontos turísticos essa cidade têm? ");
    scanf("%d", &numero_pontos_turisticos_1);

    /* Pegar informações para Carta 2*/
    printf("Qual a letra que representa o Estado para esta carta? (Entre 'A' e 'H') ");
    scanf("%c", &estado_2);
    getchar();
    printf("Qual o código da carta? (Letra do estado e número entre 01 e 04) ");
    fgets(codigo_carta_2, 4, stdin);
    codigo_carta_2[strcspn(codigo_carta_2, "\n")] = 0;
    printf("Agora, qual o nome da cidade? "); 
    fgets(nome_cidade_2, 20, stdin);
    nome_cidade_2[strcspn(nome_cidade_2, "\n")] = 0;
    printf("Qual a população da cidade da carta? ");
    scanf("%d", &populacao_2);
    printf("Qual sua área, em km²? ");
    scanf("%lf", &area_km_2);
    printf("E seu PIB? ");
    scanf("%lf", &pib_2);
    printf("Por último, quantos pontos turísticos essa cidade têm? ");
    scanf("%d", &numero_pontos_turisticos_2);

    /* Exibição da carta 1 */
    printf("Carta 1: \n Estado: %c \n Código: %s \n Nome Da Cidade: %s \n População: %d \n Área: %.2lf \n PIB: %.2lf bilhões de Reais \n Número de Pontos turísticos: %d",
    estado_1, codigo_carta_1, nome_cidade_1, populacao_1, area_km_1, pib_1, numero_pontos_turisticos_1);

    /* Exibição da carta 2 */
    printf("Carta 2: \n Estado: %c \n Código: %s \n Nome Da Cidade: %s \n População: %d \n Área: %.2lf \n PIB: %.2lf bilhões de Reais \n Número de Pontos turísticos: %d",
    estado_2, codigo_carta_2, nome_cidade_2, populacao_2, area_km_2, pib_2, numero_pontos_turisticos_2);

} 