#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Menu.h"
#include <time.h>
#include "estruturas_alfa.h"
#include "Funcoes_Reservas.h"


/*Horario e slots de tempo*/
#define HORA_ABERTURA 8
#define HORA_FECHO 18
#define slots_tempo 30

/*Status do time slot*/
#define Disponivel 1
#define Ocupado 0

#define MAX_TELEFONE 9
#define MAX_NOME 15



// Example usage
int main() {
  // Initialize a new Reserva list
  listaReservas* lista = criar_lista_reservas();
  show_Menu();
  int user_input;
  scanf("%d",&user_input);
  while (user_input < 1 || user_input > 10) {
    printf("Introduza um numero valido (1-10).\n");
    while (getchar() != '\n');
    scanf("%d", &user_input);
  }
  switch(user_input){

// Caso o user selecione a opcao de criar uma reserva:::
    case 1 :
    Cliente* cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("Introduza o seu nome\n");
    scanf("%s",&cliente->nome);
    printf("Introduza o seu apelido\n");
    scanf("%s",&cliente->apelido);
    printf("Introduza o seu numero de telemovel\n");
    scanf("%s",&cliente->n_telemovel);
    int tipo,mes,ano,dia,hora,minutos;
    printf("Selecione o tipo de Reserva.\n\n1. Lavagem\n2. Manutenção\n");
    scanf("%d",&tipo);
    char date_input[11];
    char hour_input[6];
    printf("Introduza a data da reserva em formato ano/mes/dia)\n");
    scanf("%s", date_input);
    ano = atoi(strtok(date_input, "/"));
    mes = atoi(strtok(NULL, "/"));
    dia = atoi(strtok(NULL, "/"));
    printf("Introduza o horario que deseja marcar a reserva em formato hora:minutos.\nTenha em conta o horario da oficina(08:00 ás 18:00)\n");
    scanf("%s", hour_input);
    sscanf(hour_input, "%d:%d", &hora, &minutos);
    add_Reserva(lista,cliente,ano,mes,dia,hora,minutos,tipo);
    print_Reservas(lista);  
            break;













    case 2 : printf("Nice choice");
            break;
    case 3 : printf("Nice choice");
            break;
    case 4 : printf("Nice choice");
            break;
    case 5 : printf("Nice choice");
            break;
    case 6 : printf("Nice choice");
            break;
    case 7 : printf("Nice choice");
            break;
    case 8 : printf("Nice choice");
            break;
    case 9 : printf("Nice choice");
            break;
    case 10 : printf("Sair\n");
            break;

  
}
return 0;}











/*
  listaReservas* lista = criar_lista_reservas();

  // Create some clientes
  Cliente* c1 = (Cliente*)malloc(sizeof(Cliente));
  strcpy(c1->nome, "Alice");
  strcpy(c1->email, "alice@example.com");

  Cliente* c2 = (Cliente*)malloc(sizeof(Cliente));
  strcpy(c2->nome, "Bob");
  strcpy(c2->email, "bob@example.com");

  // Add some Reservas
  add_Reserva(lista, c1, 2023, 5, 10, 8, 0);
  add_Reserva(lista, c2, 2023, 5, 10, 8, 1);

  print_Reservas(lista);

  return 0;}*/