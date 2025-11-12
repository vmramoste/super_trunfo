#include <stdio.h>
#include <string.h>

int main(){
    /* Variáveis independentes */
    int opcao = 0, ganhador = 0;
    double parametro_comparador_1, parametro_comparador_2;
    const char *opcao_txt;

    /* Variáveis para Carta 1*/
    char estado_1, codigo_carta_1[5], nome_cidade_1[20];
    unsigned long long populacao_1;
    int numero_pontos_turisticos_1;
    double area_km_1, pib_1;
    float densidade_populacional_1, pib_per_capta_1, super_poder_1;

    /* Variáveis para Carta 2*/
    char estado_2, codigo_carta_2[5], nome_cidade_2[20];
    unsigned long long populacao_2;
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
    scanf("%llu", &populacao_1);
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
    scanf("%llu", &populacao_2);
    getchar();
    printf("Qual sua área, em km²? ");
    scanf("%lf", &area_km_2);
    getchar();
    printf("E seu PIB? ");
    scanf("%lf", &pib_2);
    getchar();
    printf("Por último, quantos pontos turísticos essa cidade têm? ");
    scanf("%d", &numero_pontos_turisticos_2);
    getchar();

    /*Calcular Densidade Populacional e PIB per capta carta 1 e 2 */
    densidade_populacional_1 = (float) populacao_1/area_km_1;
    pib_per_capta_1 = (float) pib_1/populacao_1;
    densidade_populacional_2 = (float) populacao_2/area_km_2;
    pib_per_capta_2 = (float) pib_2/populacao_2;

    // Menu para o usuário escolher o atributo para comparação
    printf("Digite a opção selecionada para comparação: \n"
    "1. População \n 2. Área \n 3. PIB \n 4. Número de pontos turísticos \n 5. Densidade demográfica \n");
    scanf("%d", &opcao); 
    switch (opcao)
    {
    case 1: /*População*/
        parametro_comparador_1 = populacao_1;
        parametro_comparador_2 = populacao_2;
        opcao_txt = "População";
        if(populacao_1 > populacao_2){
            ganhador = 1;
        }else if(populacao_1 < populacao_2){
            ganhador = 2;
        }else{
            ganhador = 3;
        }
        break;
    case 2: /* Área */
        parametro_comparador_1 = area_km_1;
        parametro_comparador_2 = area_km_2;
        opcao_txt = "Área";
        if(area_km_1 > area_km_2){
            ganhador = 1;
        }else if(area_km_1 < area_km_2){
            ganhador = 2;
        }else{
            ganhador = 3;
        }
        break;
    case 3: /* PIB */
        parametro_comparador_1 = pib_1;
        parametro_comparador_2 = pib_2;
        opcao_txt = "PIB";
        if(pib_1 > pib_2){
            ganhador = 1;
        }else if(pib_1 < pib_2){
            ganhador = 2;
        }else{
            ganhador = 3;
        }
        break;
    case 4: /* Pontos turísticos */
        parametro_comparador_1 = numero_pontos_turisticos_1;
        parametro_comparador_2 = numero_pontos_turisticos_2;
        opcao_txt = "Pontos Turísticos";
        if(numero_pontos_turisticos_1 > numero_pontos_turisticos_2){
            ganhador = 1;
        }else if(numero_pontos_turisticos_1 < numero_pontos_turisticos_2){
            ganhador = 2;
        }else{
            ganhador = 3;
        }
        break;
    case 5: /* Densidade demográfica (menor vence) */
        parametro_comparador_1 = densidade_populacional_1;
        parametro_comparador_2 = densidade_populacional_2;
        opcao_txt = "Densidade Demográfica";
        if(densidade_populacional_1 > densidade_populacional_2){
            ganhador = 2;
        }else if(densidade_populacional_1 < densidade_populacional_2){
            ganhador = 1;
        }else{
            ganhador = 3;
        }
        break;
    default: /* Entrada inválida */
        printf("A entrada informada foi inválida. Tente novamente! ");
        ganhador = 0;
        break;
    }
    if(ganhador != 0){
        printf("Comparação de Cartas (%s): \n \n", opcao_txt);
        printf("Carta 1 - %s (%c): %.2lf \n", nome_cidade_1, estado_1, parametro_comparador_1);
        printf("Carta 2 - %s (%c): %.2lf \n", nome_cidade_2, estado_2, parametro_comparador_2);
        if(ganhador == 1){
            printf("A carta 1 foi a vecedora!");
        }else if (ganhador == 2){
            printf("A carta 2 foi a vecedora!");
        }else{
            printf("Empate!");
        }
        
    }
    
return 0;
} 