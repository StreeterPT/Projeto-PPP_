#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include <time.h>
#include "structs_reservas.h"
#include "structs_pre_reservas.h"
#include "funcoes.h"
#include "stack.h"
#include <limits.h>


/*Horario e slots de tempo*/
#define HORA_ABERTURA 8
#define HORA_FECHO 18



#define MAX_TELEFONE 9
#define MAX_NOME 15




// Example usage
int main() {
  // Initialize a new Reserva list
  listaReservas* lista = criar_lista_reservas();
  lista_Pre_Reservas* lista_pre = criar_lista_pre_reservas();
  



  char nome[MAX_NOME];
  char apelido[MAX_NOME];
  int user_input;

  
  while(1){
  show_Menu();
  scanf("%d",&user_input);
  while (user_input < 1 || user_input > 10) {
    printf("Introduza um numero valido (1-10).\n");
    while (getchar() != '\n');
    scanf("%d", &user_input);
  }
  switch(user_input){

// Caso o user selecione a opcao de criar uma reserva:
    case 1 :
            Cliente* cliente;
            cliente = (Cliente*) malloc(sizeof(Cliente));
            printf("Introduza o seu primeiro nome\n");
            scanf("%s",cliente->nome);
            printf("Introduza o seu apelido\n");
            scanf("%s",cliente->apelido);
            printf("Introduza o seu numero de telemovel\n");
            scanf("%s",cliente->n_telemovel);
            int tipo,mes,ano,dia,hora,minutos;
            printf("Selecione o tipo de Reservas.\n\n1. Lavagem\n2. Manutencao\n");
            scanf("%d",&tipo);
            while(tipo!=1 && tipo!=2){
                printf("Introduza um tipo válido.\nn1. Lavagem\n2. Manutencao\n");
                while (getchar() != '\n');
                scanf("%d", &tipo);}
            char date_input[11];
            char hour_input[6];
            printf("Introduza a data da reservas em formato dia/mes/ano)\n");
            scanf("%s", date_input);
            dia = atoi(strtok(date_input, "/"));
            mes = atoi(strtok(NULL, "/"));
            ano = atoi(strtok(NULL, "/"));
            printf("Introduza o horario que deseja marcar a reserva em formato hora:minutos.\nTenha em conta o horario da oficina(08:00 as 18:00)\n");
        while (1) {
            scanf("%s", hour_input);
            sscanf(hour_input, "%d:%d", &hora, &minutos);
            if (is_store_open(hora, minutos, tipo)) {
                if (is_available(lista, ano, mes, dia, hora, minutos, tipo)) {
                    add_Reserva_ordem_oposta(lista, cliente, ano, mes, dia, hora, minutos, tipo);
                    printf("Reserva concluida.\n");
                    break;
                } else {
                    printf("O horario selecionado encontra-se ocupado.\n");
                    printf("Escolha uma opcao:\n");
                    printf("1. Introduzir outro horario\n");
                    printf("2. Voltar ao menu\n");
                    printf("3. Passar a Pre-Reserva.\n");
                    

                    int option;
                    scanf("%d", &option);

                    if (option == 1) {
                        printf("Introduza o novo horario em formato horas:minutos.\n");
                        continue;
                    } else if (option == 2) {
                        break;
                    } else if(option == 3) {
                        int ordem=flag(lista_pre);
                        add_Pre_Reserva_ordem(lista_pre,cliente,ano,mes,dia,hora,minutos,tipo);
                        printf("Pre-Reserva adicionada.\n");
                        break;
                    //else if(option == 3){Inserir opção de marcar pré reserva}
                    } else {
                        printf("Opcao invalida. A redirecionar ao menu...\n");
                        break;
                    }
                }
            } else {
                printf("A loja está fechada.\n");
                continue;
            }
        }
                sleep(3);
            break;


  





    case 2 : 
            printf("Cancelar Reserva\n");
            printf("Introduza o seu nome\n ");
            scanf("%s",nome);
            printf("Introduza o seu apelido\n");
            scanf("%s",apelido);
            check_if_there_is_reservation_and_erase_2(lista,lista_pre,nome,apelido);
            sleep(3); 
            break;

            





    case 3 : 
            printf("Cancelar Pre Reserva\n");
            printf("Introduza o seu nome\n ");
            scanf("%s",nome);
            printf("Introduza o seu apelido\n");
            scanf("%s",apelido);
            check_if_there_is_pre_reservation_and_erase(lista_pre,nome,apelido); 
            sleep(2);
            break;


           
    case 5 : 
            printf("Listagem das reservas de um cliente\n");
            printf("Introduza o seu nome\n ");
            scanf("%s",nome);
            printf("Introduza o seu apelido\n");
            scanf("%s",apelido);
            printf("\nReservas marcadas en nome de %s %s.\n",nome,apelido);
            show_reserves_client_reverse(lista,nome,apelido);
            printf("\nPre-Reservas marcadas em nome de %s %s",nome,apelido);
            show_pre_reserves_client_reverse(lista_pre,nome,apelido);
            sleep(4);
            break;
    case 4 :
            printf("Lista de Reservas:\n");
            print_Reservas(lista);
            printf("\nLista de Pre-Reservas:\n");
            print_Pre_Reservas(lista_pre);
            sleep(3);
            break;
    case 6 :
            if(lista->head != NULL){advance_time_with_pre_reservations(lista,lista_pre);printf("A reserva foi realizada.\n");}
            else {printf("A lista de reservas esta vazia\n");} 
            sleep(2);
            break;
    case 7 :
            printf("A carregar os dados do ficheiro... \n");
            sleep(1);
            readReservationsFromFile(lista);
            readPreReservationsFromFile(lista_pre);
            printf("Dados carregados com sucesso.\n");
            sleep(2);
            break;

            
    case 8 : 
            printf("A salvar os dados...\n");
            sleep(1);
            writeReservationsToFile(lista);
            writePreReservationsToFile(lista_pre);
            printf("Dados salvos.\n");
            sleep(2);
            break;
    case 9 : 
            printf("Sair\n");
            break;

  
}if (user_input==9){break;}}
return 0;}





