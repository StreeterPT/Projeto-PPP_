#define HORA_ABERTURA 8
#define HORA_FECHO 18


// Initialize a new Reserva list
listaReservas* criar_lista_reservas() {
  listaReservas* lista = (listaReservas*)malloc(sizeof(listaReservas));
  lista->head = NULL;
  lista->tail = NULL;
  return lista;
}





// Create a new Reserva and add it to the list
void add_Reserva(listaReservas* lista, Cliente* cliente, int ano, int mes, int dia, int hora, int minutos,int tipo) {
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
    res->minutos=minutos;
    res->tipo = tipo;
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
    
  }

// Print all Reservas in the list
void print_Reservas(listaReservas* lista) {
  Reserva* res = lista->head;
  while (res != NULL) {
    printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
    if(res->tipo==1)printf("\tLavagem\n");
    if(res->tipo==2)printf("\tManutenção\n");
    res = res->next;
  }
}



/* void check_if_there_is_reservation_and_erase(listaReservas* lista,char nome[MAX_NOME],char apelido[MAX_NOME]){
    Reserva* res = lista->head;
    Reserva* reserva_anterior = NULL;
    int user_inp;
    while(res != NULL){
        if (res->cliente->nome == nome && res->cliente->apelido == apelido){
            printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido,);
            if(res->tipo==1)printf("\tLavagem\n");
            if(res->tipo==2)printf("\tManutenção\n");
            printf("Deseja cancelar esta reserva?\n\n1.Sim\n2.Não\n");
            scanf("%d",&user_inp);
            if(user_inp==1){
                    if (reserva_anterior != NULL) {
                        reserva_anterior->next = res->next;}
                    else {
                        lista->head = res->next;}
                   
                    free(res);
                    printf("A reserva foi cancelada.\n");}
                    
            if(user_inp==2){
                    printf(" A reserva não será cancelada.\n");}
                    
            reserva_anterior = res;
            res = res->next;
                    


        }
    else{reserva_anterior = res;
            res = res->next;}

    }
} */


void check_if_there_is_reservation_and_erase(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
    Reserva* res = lista->head;
    Reserva* reserva_anterior = NULL;
    int user_inp;

    while (res != NULL) {
        if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
            printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
            if (res->tipo == 1) {
                printf("\tLavagem\n");
            }
            if (res->tipo == 2) {
                printf("\tManutenção\n");
            }
            printf("Deseja cancelar esta reserva?\n\n1. Sim\n2. Não\n");
            scanf("%d", &user_inp);

            if (user_inp == 1) {
                if (reserva_anterior != NULL) {
                    reserva_anterior->next = res->next;
                } else {
                    lista->head = res->next;
                }
                
                free(res);
                printf("A reserva foi cancelada.\n");
            } else if (user_inp == 2) {
                printf("A reserva não será cancelada.\n");
            }
        }

        reserva_anterior = res;
        res = res->next;
    }
}











int check_if_booking_is_free(listaReservas* lista, int ano, int mes, int dia, int hora, int minutos){

}


/*int check_if_reservation_exists(listaReservas* lista, int ano, int mes, int dia, int hora, int minutos) {
    Reserva* reserva = lista->head;
    while (reserva != NULL) {
        if (reserva->ano == ano && reserva->mes == mes && reserva->dia == dia && reserva->hora == hora && reserva->minutos == minutos) {
            return 1; // Reservation exists
        }
        reserva = reserva->prox;
    }
    return 0; // Reservation does not exist
}

int check_if_reservation_conflicts(listaReservas* lista, int ano, int mes, int dia, int hora, int minutos) {
    Reserva* reserva = lista->head;
    while (reserva != NULL) {
        // Check for conflicts based on date and time range
        if (reserva->ano == ano && reserva->mes == mes && reserva->dia == dia) {
            if (hora >= reserva->hora && hora < reserva->hora + RESERVATION_DURATION) {
                return 1; // Conflict found
            }
        }
        reserva = reserva->prox;
    }
    return 0; // No conflicts found
}

*/

int check_if_store_open(int hour,int minutes,int tipo){
    if(tipo == 2){
        if(hour < HORA_ABERTURA || hour > HORA_FECHO )return 0;
        if(hour == HORA_FECHO-1){if(minutes>0)return 0;}
        else {return 1;}}
    if(tipo == 1){
        if(hour < HORA_ABERTURA || hour > HORA_FECHO )return 0;
        if(hour == HORA_FECHO){if(minutes>30)return 0;}
        else return 1;}
    }



/* void show_reserves_client(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]){
  Reserva* res = lista->head;
  while (res != NULL) {
    if(res->cliente->nome == nome && res->cliente->apelido == apelido){
    printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
    if(res->tipo==1)printf("\tLavagem\n");
    if(res->tipo==2)printf("\tManutenção\n");}
  }res = res->next;
} */

void show_reserves_client(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
  Reserva* res = lista->head;
  while (res != NULL) {
    if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
      printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
      if (res->tipo == 1) printf("\tLavagem\n");
      if (res->tipo == 2) printf("\tManutenção\n");
    }
    res = res->next;
  }
}