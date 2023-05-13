#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Menu.h"
#include <windows.h>
#include <time.h>
#include "estruturas_alfa.h"


/*Horario e slots de tempo*/
#define HORA_ABERTURA 8
#define HORA_FECHO 18
#define slots_tempo 30

/*Status do time slot*/
#define Disponivel 1
#define Ocupado 0





// Create a new Reserva and add it to the list
void add_Reserva(listaReservas* lista, Cliente* cliente, int ano, int mes, int dia, int hora, int slot) {
  // Check if the time slot is available
  // For example, you can use a 2D array to represent the time slots
  bool is_available = true; // Assume the time slot is available
  // Check if the time slot is already booked
  // For example, if the array is called `timeslots`
  
    // Create a new Reserva struct
    Reserva* res = (Reserva*)malloc(sizeof(Reserva));
    res->cliente = cliente;
    res->ano = ano;
    res->mes = mes;
    res->dia = dia;
    res->hora = hora;
    res->slot = slot;
    res->next = NULL;

    // Add the Reserva to the list
    if (lista->head == NULL) {
      // If the list is empty, set the head and tail pointers to the new Reserva
      lista->head = res;
      lista->tail = res;
    } else {
      // Otherwise, link the new Reserva into the list
      res->next = lista->head;
      lista->head = res;
    }

    // Mark the time slot as unavailable
    
  }

// Print all Reservas in the list
void print_Reservas(listaReservas* lista) {
  Reserva* res = lista->head;
  while (res != NULL) {
    printf("%d/%d/%d %d:%02d - %s (%s)\n", res->ano, res->mes, res->dia, res->hora, res->slot * 30, res->cliente->nome, res->cliente->email);
    res = res->next;
  }
}

// Example usage
int main() {
  // Initialize a new Reserva list
  show_Menu();
  int user_input;
  scanf("%d",&user_input);
  while (user_input < 1 || user_input > 10) {
    printf("Introduza um numero valido (1-10).\n");
    while (getchar() != '\n');
    scanf("%d", &user_input);
  }
  switch(user_input){
    case 1 : printf("Nice choice");
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
    case 10 : printf("Sair");
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