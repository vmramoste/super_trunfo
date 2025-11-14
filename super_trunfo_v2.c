#include <stdio.h>
#include <string.h>
#include <locale.h>
int main(){
    // Caracteres especiais
    setlocale(LC_ALL,"Portuguese_Brazil");
    // Variáveis independentes
    int opcao_1 = 0, opcao_2 = 0; //Opção menus
    int ganhador_1 = 0, ganhador_2 = 0, ganhador_3 = 0; // Ganhador em cada categoria
    double parametro_comparador_1, parametro_comparador_3; // Carta 1
    double parametro_comparador_2, parametro_comparador_4; // Carta 2
    double soma_atributos_1, soma_atributos_2; // Soma dos atributos (3ª comparação)
    const char *opcao_txt_1, *opcao_txt_2; // Nome da categoria
    

    /* Variáveis para Carta 1*/
    char estado_1, codigo_carta_1[5], nome_cidade_1[20];
    unsigned long long populacao_1;
    int numero_pontos_turisticos_1;
    double area_km_1, pib_1;
    float densidade_populacional_1, pib_per_capta_1;

    /* Variáveis para Carta 2*/
    char estado_2, codigo_carta_2[5], nome_cidade_2[20];
    unsigned long long populacao_2;
    int numero_pontos_turisticos_2;
    double area_km_2, pib_2;
    float densidade_populacional_2, pib_per_capta_2;

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
    "1. População \n2. Área \n3. PIB \n4. Número de pontos turísticos \n5. Densidade demográfica \n");
    scanf("%d", &opcao_1); 
    switch(opcao_1){
        case 1:
            printf("Digite a segunda opção selecionada para comparação: \n"
            "2. Área \n3. PIB \n4. Número de pontos turísticos \n5. Densidade demográfica \n");
            scanf("%d", &opcao_2);
            break;
        case 2:
            printf("Digite a segunda opção selecionada para comparação: \n"
            "1. População \n3. PIB \n4. Número de pontos turísticos \n5. Densidade demográfica \n");
            scanf("%d", &opcao_2);
            break;
        case 3:
            printf("Digite a segunda opção selecionada para comparação: \n"
            "1. População \n2. Área \n4. Número de pontos turísticos \n5. Densidade demográfica \n");
            scanf("%d", &opcao_2);
            break;
        case 4:
            printf("Digite a segunda opção selecionada para comparação: \n"
            "1. População \n2. Área \n3. PIB \n5. Densidade demográfica \n");
            scanf("%d", &opcao_2);
            break;
        case 5:
            printf("Digite a segunda opção selecionada para comparação: \n"
            "1. População \n2. Área \n3. PIB \n4. Número de pontos turísticos \n");
            scanf("%d", &opcao_2);
            break;
        default:
                printf("Opção inválida! ");
    }

    // Verificar ganhador do atributo 1
    switch (opcao_1)
    {
    case 1: /*População*/
        parametro_comparador_1 = populacao_1;
        parametro_comparador_2 = populacao_2;
        opcao_txt_1 = "População";
        if(populacao_1 > populacao_2){
            ganhador_1 = 1;
        }else if(populacao_1 < populacao_2){
            ganhador_1 = 2;
        }else{
            ganhador_1 = 3;
        }
        break;
    case 2: /* Área */
        parametro_comparador_1 = area_km_1;
        parametro_comparador_2 = area_km_2;
        opcao_txt_1 = "Área";
        if(area_km_1 > area_km_2){
            ganhador_1 = 1;
        }else if(area_km_1 < area_km_2){
            ganhador_1 = 2;
        }else{
            ganhador_1 = 3;
        }
        break;
    case 3: /* PIB */
        parametro_comparador_1 = pib_1;
        parametro_comparador_2 = pib_2;
        opcao_txt_1 = "PIB";
        if(pib_1 > pib_2){
            ganhador_1 = 1;
        }else if(pib_1 < pib_2){
            ganhador_1 = 2;
        }else{
            ganhador_1 = 3;
        }
        break;
    case 4: /* Pontos turísticos */
        parametro_comparador_1 = numero_pontos_turisticos_1;
        parametro_comparador_2 = numero_pontos_turisticos_2;
        opcao_txt_1 = "Pontos Turísticos";
        if(numero_pontos_turisticos_1 > numero_pontos_turisticos_2){
            ganhador_1 = 1;
        }else if(numero_pontos_turisticos_1 < numero_pontos_turisticos_2){
            ganhador_1 = 2;
        }else{
            ganhador_1 = 3;
        }
        break;
    case 5: /* Densidade demográfica (menor vence) */
        parametro_comparador_1 = densidade_populacional_1;
        parametro_comparador_2 = densidade_populacional_2;
        opcao_txt_1 = "Densidade Demográfica";
        if(densidade_populacional_1 > densidade_populacional_2){
            ganhador_1 = 2;
        }else if(densidade_populacional_1 < densidade_populacional_2){
            ganhador_1 = 1;
        }else{
            ganhador_1 = 3;
        }
        break;
    default: /* Entrada inválida, já há texto tratando a ocorrência anteriormente */
        printf("");
        ganhador_1 = 0;
        break;
    }

    // Verificar ganhador do atributo 2
    if(opcao_2 != 0){
        switch (opcao_2)
        {
        case 1: /*População*/
            parametro_comparador_3 = populacao_1;
            parametro_comparador_4 = populacao_2;
            opcao_txt_2 = "População";
            if(populacao_1 > populacao_2){
                ganhador_2 = 1;
            }else if(populacao_1 < populacao_2){
                ganhador_2 = 2;
            }else{
                ganhador_2 = 3;
            }
            break;
        case 2: /* Área */
            parametro_comparador_3 = area_km_1;
            parametro_comparador_4 = area_km_2;
            opcao_txt_2 = "Área";
            if(area_km_1 > area_km_2){
                ganhador_2 = 1;
            }else if(area_km_1 < area_km_2){
                ganhador_2 = 2;
            }else{
                ganhador_2 = 3;
            }
            break;
        case 3: /* PIB */
            parametro_comparador_3 = pib_1;
            parametro_comparador_4 = pib_2;
            opcao_txt_2 = "PIB";
            if(pib_1 > pib_2){
                ganhador_2 = 1;
            }else if(pib_1 < pib_2){
                ganhador_2 = 2;
            }else{
                ganhador_2 = 3;
            }
            break;
        case 4: /* Pontos turísticos */
            parametro_comparador_3 = numero_pontos_turisticos_1;
            parametro_comparador_4 = numero_pontos_turisticos_2;
            opcao_txt_2 = "Pontos Turísticos";
            if(numero_pontos_turisticos_1 > numero_pontos_turisticos_2){
                ganhador_2 = 1;
            }else if(numero_pontos_turisticos_1 < numero_pontos_turisticos_2){
                ganhador_2 = 2;
            }else{
                ganhador_2 = 3;
            }
            break;
        case 5: /* Densidade demográfica (menor vence) */
            parametro_comparador_3 = densidade_populacional_1;
            parametro_comparador_4 = densidade_populacional_2;
            opcao_txt_2 = "Densidade Demográfica";
            if(densidade_populacional_1 > densidade_populacional_2){
                ganhador_2 = 2;
            }else if(densidade_populacional_1 < densidade_populacional_2){
                ganhador_2 = 1;
            }else{
                ganhador_2 = 3;
            }
            break;
        default: 
            printf("Opção inválida! ");
            ganhador_2 = 0;
            break;
        }
    }
    // Verificamos se os atributos no menu foram válidos
    if(ganhador_1 == 0 || ganhador_2 == 0){
        printf("Tente Novamente! ");
    }else{ // Atributos válidos
        // Calculo da soma dos atributos
        soma_atributos_1 = parametro_comparador_1 + parametro_comparador_3;
        soma_atributos_2 = parametro_comparador_2 + parametro_comparador_4;
        ganhador_3 = (soma_atributos_1>soma_atributos_2) ? 1 : soma_atributos_1<soma_atributos_2 ? 2 : 3; 

        //Impressão Resultado final
        printf("Atributos escolhidos: %s, %s.\n", opcao_txt_1, opcao_txt_2);
        printf("Comparação de Cartas (%s): \n", opcao_txt_1);
        printf("Carta 1 - %s (%c): %.2lf \n", nome_cidade_1, estado_1, parametro_comparador_1);
        printf("Carta 2 - %s (%c): %.2lf \n \n", nome_cidade_2, estado_2, parametro_comparador_2);
        printf("Comparação de Cartas (%s): \n", opcao_txt_2);
        printf("Carta 1 - %s (%c): %.2lf \n", nome_cidade_1, estado_1, parametro_comparador_3);
        printf("Carta 2 - %s (%c): %.2lf \n", nome_cidade_2, estado_2, parametro_comparador_4);
        printf("Comparação de Cartas (Soma dos Atributos): \n");
        printf("Carta 1 - %s (%c): %.2lf \n", nome_cidade_1, estado_1, soma_atributos_1);
        printf("Carta 2 - %s (%c): %.2lf \n", nome_cidade_2, estado_2, soma_atributos_2);
        
        // Ganhador por atributo
        // Atributo 1
        if(ganhador_1 == 1){
            printf("A carta 1 foi a vecedora do atributo %s! \n", opcao_txt_1);
        }else if (ganhador_1 == 2){
            printf("A carta 2 foi a vecedorado do atributo %s! \n", opcao_txt_1);
        }else{
            printf("Empate no atributo %s! \n", opcao_txt_1);
        }
        // Atributo 2
        if(ganhador_2 == 1){
            printf("A carta 1 foi a vecedora do atributo %s! \n", opcao_txt_2);
        }else if (ganhador_2 == 2){
            printf("A carta 2 foi a vecedora do atributo %s! \n", opcao_txt_2);
        }else{
            printf("Empate no atributo %s! \n", opcao_txt_2);
        }
        // Soma dos Atributos
        if(ganhador_3 == 1){
            printf("A carta 1 foi a vecedora na soma dos atributos! \n");
        }else if (ganhador_3 == 2){
            printf("A carta 2 foi a vecedora na soma dos atributos! \n");
        }else{
            printf("Empate na soma dos atributos! \n");
        }
    }
    return 0;    
}