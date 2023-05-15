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

