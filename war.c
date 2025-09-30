//Biibliotecas necessarias
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

//Definição das variiaveis globais
#define TAM_MAX 5
#define TAM_NOME 30
#define TAM_COR 10

//Criação do tipo de dado struct
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

//Função para limpar buffer a cada entrada, evita da leitura pular linhas
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função principal do sistema
int main() {
    
    //Definição para aceitar acentuação
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    //Criação do vetor do tipo Territorio(struct) e atribuição do espaço máximo
    Territorio territorios[5];
    //Variavel para guardar o total de tropas cadastradas
    int totalTropa = 0;
    //Variavel para guardar o valor das opções (1,2,0,etc)
    int opcao;

    // ---- Laço principal do menu ----
    do {
        //Exibe o menu de opções
        printf("==========================================\n");
        printf(" ----- JOGO WAR -----\n");
        printf("==========================================\n");
        printf(" 1 - Cadastrar novo territorio\n");
        printf(" 2 - Listar territorios cadastrados\n");
        printf(" 0 - Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opção:");

        //Lê a opção digitada e guarda o valor na variavel 'opcao'
        scanf("%d", &opcao);
        // Limpa o '\n' deixado pelo scanf
        limparBufferEntrada(); 

        // ---- Processamento da Opção ----
        switch (opcao) {
            //Case 1 chama o laço após selecionar a opção 1
            case 1:
                //Exibe a mensagem noo console
                printf("---- Cadastro de Tropas ----\n");

                //Inicia o laço e enquanto o total das tropas não atingir o TAM_MAX[5] o sistema permiirá inclusão de um novo erritorio
                while (totalTropa < TAM_MAX) {
                    //Exibe a mensagem noo console
                    printf("Digite o nome do territorio: ");
                    /*Lê uma linha do teclado (stdin: enrada padrão) e amazena na string nome do territorio atual, TAM_NOME define a quantidade máxima de 
                    caracteres. Usamos fgets pois ele lê espaços ex:("BANANA PRATA") */
                    fgets(territorios[totalTropa].nome, TAM_NOME, stdin);
                    /*Essa linha remove o caractere \n (Enter) que a função fgets() guarda no final da string quando o usuário pressiona Enter.
                    fgets guarda o \n(enter) dai entra o strspn(função: procura onde está o \n que o fgets guardou e substibui esse valor por \0 (marca o fim da string). ) */
                    territorios[totalTropa].nome[strcspn(territorios[totalTropa].nome, "\n")] = 0;
                    
                    printf("Digite a cor do territorio: ");
                    fgets(territorios[totalTropa].cor, TAM_COR, stdin);
                    territorios[totalTropa].cor[strcspn(territorios[totalTropa].cor, "\n")] = 0;

                    printf("Digite a quantidade de tropas: ");
                    scanf("%d", &territorios[totalTropa].tropas);
                    //Chamando função para limpar buffer
                    limparBufferEntrada(); 

                    //Incrementa +1 à variavel totalTropa, ex: totalTropa = totalTropa + 1
                    totalTropa++;

                    //Criamos a estrutura de controle, definindo o paramero para enquanto totalTropa for menor que TAM_MAX(variavel global de tamanhoo 5)
                    if (totalTropa < TAM_MAX) {
                        //Criamos a variavel ''escolha'  
                        char escolha;
                        //Exibe a mensagem no console
                        printf("Territorio cadastrado com successo! Deseja cadastrar outro? (s/n): \n");
                        //Lê a opção digitada e guarda o valor na variavel 'escolha'
                        scanf(" %c", &escolha);
                        //Chama função para limpar buffer de entrada
                        limparBufferEntrada();

                        //// Verifica se a resposta do usuário foi diferente de 's' ou 'S'; se for, interrompe o cadastro de novos territórios
                        if (escolha != 's' && escolha != 'S') {
                            // sai do while
                            break; 
                        }
                    }
                }

                //Criamos a estrutura e definimos que quando totalTropa for igual a TAM_MAX deve exibir a mensagem noo console
                if (totalTropa == TAM_MAX) {
                    //Exibe a mensagem no console
                    printf("\nVocê cadastrou o número máximo de territórios (%d).\n", TAM_MAX);
                }

                //Exibe a mensagem no console
                printf("\nPressione Enter para continuar...");
                // getchar() lê um único caractere do teclado, aqui é usado para "pausar" o programa até o usuário pressionar Enter
                getchar();
                //Encerra o bloco atual e volta ao menu inicial
                break;

                //Case 2 chama o laço após selecionar a opção 2
                case 2:
                //Exibe a mensagem no console
                printf("---- Lista de Territorios Cadastrados ----\n");

                //Criamos a estrutura e definimos que se totalTropa for igual a zero exibe a mensagem no console
                if (totalTropa == 0) {
                    //Exibe mensagem no console (totalTropa==0)
                    printf("Nenhum Territorio cadastrado ainda.\n");

                //Definimos que, caso o if seja falso o else será executado
                } else {
                    //Criamos a variavel i do tipo inteiro e atribuimos valor 0, depois definimos que enquanto i for menor que totalTropa somamos +1 ao valor
                    for (int i = 0; i < totalTropa; i++) {
                        printf("------------------------------------\n");
                        //Exibe os dados dos territorios cadastrados e define o tipo de dado
                        printf("Território: %d\n", i + 1); 
                        //Exibe o nome, definimos o tipo de dado e selecionamos o vetor territorios e [i].nome buscamos no indice o campo da struct que queremos acessar             
                        printf("Nome: %s\n", territorios[i].nome);         
                        printf("Cor: %s\n", territorios[i].cor);           
                        printf("Tropas: %d\n\n", territorios[i].tropas);   
                        printf("---------------------------------------\n");
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;
            
            //Case 0 chama o laço após selecionar a opção 0
            case 0:
                printf("\nSaindo do sistema...\n");
                break;

                /*Esse é o caso padrão do switch. Se nenhuma das outras opções (case 1, case 2, case 0) for escolhida
                 o programa executa o código dentro do default. Serve para tratar entradas inválidas.*/
                default:
                printf("\nOpcao invalida! Tente novamente\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

    } 
    //O laço continua enquanto a variável 'opcao' for diferente de 0.
    while (opcao != 0);
    
    //Sinaliza que o programa terminou com sucesso.
    return 0;
}
