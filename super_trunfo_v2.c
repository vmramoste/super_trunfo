#include <stdio.h>
#include <string.h>

int main(){
    /* Variáveis para Carta 1*/
    char estado_1, codigo_carta_1[5], nome_cidade_1[20];
    unsigned long int populacao_1;
    int numero_pontos_turisticos_1;
    double area_km_1, pib_1;
    float densidade_populacional_1, pib_per_capta_1, super_poder_1;

    /* Variáveis para Carta 2*/
    char estado_2, codigo_carta_2[5], nome_cidade_2[20];
    unsigned long int populacao_2;
    int numero_pontos_turisticos_2;
    double area_km_2, pib_2;
    float densidade_populacional_2, pib_per_capta_2, super_poder_2;

    /* Pegar informações para Carta 1*/
    printf("Qual a letra que representa o Estado para esta carta? (Entre 'A' e 'H') ");
    scanf("%c", &estado_1);
    getchar();
    printf("Qual o código da carta? (Letra do estado e número entre 01 e 04) ");
    fgets(codigo_carta_1, 5, stdin);
    codigo_carta_1[strcspn(codigo_carta_1, "\n")] = 0;
    printf("Agora, qual o nome da cidade? "); 
    fgets(nome_cidade_1, 20, stdin); //Usamos fgets por ter espaços entre as palavras da string
    /* Limparemos 'nome_cidade' do valor que pode ter sido inserido "\n" na string */
    nome_cidade_1[strcspn(nome_cidade_1, "\n")] = 0;
    printf("Qual a população da cidade da carta? ");
    scanf("%lu", &populacao_1);
    getchar();
    printf("Qual sua área, em km²? ");
    scanf("%lf", &area_km_1);
    getchar();
    printf("E seu PIB? ");
    scanf("%lf", &pib_1);
    getchar();
    printf("Por último, quantos pontos turísticos essa cidade têm? ");
    scanf("%d", &numero_pontos_turisticos_1);
    getchar();

    /* Pegar informações para Carta 2*/
    printf("Qual a letra que representa o Estado para esta carta? (Entre 'A' e 'H') ");
    scanf("%c", &estado_2);
    getchar();
    printf("Qual o código da carta? (Letra do estado e número entre 01 e 04) ");
    fgets(codigo_carta_2, 5, stdin);
    codigo_carta_2[strcspn(codigo_carta_2, "\n")] = 0;
    printf("Agora, qual o nome da cidade? "); 
    fgets(nome_cidade_2, 20, stdin);
    nome_cidade_2[strcspn(nome_cidade_2, "\n")] = 0;
    printf("Qual a população da cidade da carta? ");
    scanf("%lu", &populacao_2);
    printf("Qual sua área, em km²? ");
    scanf("%lf", &area_km_2);
    printf("E seu PIB? ");
    scanf("%lf", &pib_2);
    printf("Por último, quantos pontos turísticos essa cidade têm? ");
    scanf("%d", &numero_pontos_turisticos_2);

    /*Calcular Densidade Populacional e PIB per capta carta 1 e 2 */
    densidade_populacional_1 = (float) populacao_1/area_km_1;
    pib_per_capta_1 = (float) pib_1/populacao_1;
    densidade_populacional_2 = (float) populacao_2/area_km_2;
    pib_per_capta_2 = (float) pib_2/populacao_2;

    // Calcular super poder
    super_poder_1 = (float) (populacao_1 + area_km_1 + pib_1 + numero_pontos_turisticos_1 + pib_per_capta_1 + (1/densidade_populacional_1));
    super_poder_2 = (float) (populacao_2 + area_km_2 + pib_2 + numero_pontos_turisticos_2 + pib_per_capta_2 + (1/densidade_populacional_2));

    // Início resposta
    printf("Comparação de Cartas (Densidade Populacional): \n \n");
    printf("Carta 1 - %s (%c): %f \n", nome_cidade_1, estado_1, densidade_populacional_1);
    printf("Carta 2 - %s (%c): %f \n", nome_cidade_2, estado_2, densidade_populacional_2);
    // Comparação atributo Densidade Populacional
    if(densidade_populacional_1 < densidade_populacional_2){
        printf("Resultado: Carta 1 (%s) venceu ", nome_cidade_1);
    }else{
        printf("Resultado: Carta 2 (%s) venceu ", nome_cidade_2);
    }
    
return 0;
} 