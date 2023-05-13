
typedef struct Cliente {
  char nome[15];
  char apelido[15];
  char email[30];
  int n_telefone;
} Cliente;

typedef struct Reserva Reserva;

struct Reserva {
  Cliente* cliente;
  int ano;
  int mes;
  int dia;
  int hora;
  int slot;
  Reserva* next;
};

typedef struct listaReservas listaReservas;

struct listaReservas {
  Reserva* head;
  Reserva* tail;
};

// Initialize a new Reserva list
listaReservas* criar_lista_reservas() {
  listaReservas* lista = (listaReservas*)malloc(sizeof(listaReservas));
  lista->head = NULL;
  lista->tail = NULL;
  return lista;
}