#define MAX_NOME 15
#define MAX_TELEFONE 9

typedef struct Cliente {
  char nome[MAX_NOME];
  char apelido[MAX_NOME];
  char n_telemovel[MAX_TELEFONE];
} Cliente;




typedef struct Reserva Reserva;

struct Reserva {
  Cliente* cliente;
  int ano;
  int mes;
  int dia;
  int hora;
  int minutos;
  int tipo;
  Reserva* next;
};

typedef struct listaReservas listaReservas;

struct listaReservas {
  Reserva* head;
};

