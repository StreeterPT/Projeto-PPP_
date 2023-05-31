

typedef struct Pre_Reserva {
  Cliente* cliente;
  int ano;
  int mes;
  int dia;
  int hora;
  int minutos;
  int tipo;
  int flag;
  
  struct Pre_Reserva* next;
} Pre_Reserva;

typedef struct lista_Pre_Reservas {
  Pre_Reserva* head;
} lista_Pre_Reservas;


lista_Pre_Reservas* criar_lista_pre_reservas() {
  lista_Pre_Reservas* lista_pre = (lista_Pre_Reservas*)malloc(sizeof(lista_Pre_Reservas));
  lista_pre->head = NULL;
  return lista_pre;
}

int flag(lista_Pre_Reservas* lista){
    int flag=1;
    Pre_Reserva* pre_res = lista->head;
    while( pre_res != NULL ){
        pre_res = pre_res->next;
        flag++;
        }
    return flag;
}

