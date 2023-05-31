typedef struct StackNode {
  Reserva* data;
  struct StackNode* next;
} StackNode;

typedef struct Stack {
  StackNode* top;
} Stack;




Stack* create_stack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

int is_empty(Stack* stack) {
  return (stack->top == NULL);
}

void push(Stack* stack, Reserva* data) {
  StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

Reserva* pop(Stack* stack) {
  if (is_empty(stack)) {
    printf("Stack underflow error\n");
    return NULL;
  }
  StackNode* temp = stack->top;
  Reserva* poppedData = temp->data;
  stack->top = temp->next;
  free(temp);
  return poppedData;
}

void free_stack(Stack* stack) {
  while (!is_empty(stack)) {
    pop(stack);
  }
  free(stack);
}

typedef struct Pre_ReservaStackNode {
  Pre_Reserva* data;
  struct Pre_ReservaStackNode* next;
} Pre_ReservaStackNode;

typedef struct Pre_ReservaStack {
  Pre_ReservaStackNode* top;
} Pre_ReservaStack;

Pre_ReservaStack* create_pre_reserva_stack() {
  Pre_ReservaStack* stack = (Pre_ReservaStack*)malloc(sizeof(Pre_ReservaStack));
  stack->top = NULL;
  return stack;
}

int is_pre_reserva_stack_empty(Pre_ReservaStack* stack) {
  return (stack->top == NULL);
}

void push_pre_reserva(Pre_ReservaStack* stack, Pre_Reserva* data) {
  Pre_ReservaStackNode* newNode = (Pre_ReservaStackNode*)malloc(sizeof(Pre_ReservaStackNode));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

Pre_Reserva* pop_pre_reserva(Pre_ReservaStack* stack) {
  if (is_pre_reserva_stack_empty(stack)) {
    printf("Pre_Reserva stack underflow error\n");
    return NULL;
  }
  Pre_ReservaStackNode* temp = stack->top;
  Pre_Reserva* poppedData = temp->data;
  stack->top = temp->next;
  free(temp);
  return poppedData;
}

void free_pre_reserva_stack(Pre_ReservaStack* stack) {
  while (!is_pre_reserva_stack_empty(stack)) {
    pop_pre_reserva(stack);
  }
  free(stack);
}

void show_reserves_client_reverse(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
  Stack* stack = create_stack();
  Reserva* res = lista->head;
  
  // Push reservations of the specified client onto the stack in their original order
  while (res != NULL) {
    if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
      push(stack, res);
    }
    res = res->next;
  }
  
  // Print reservations in reverse order by popping them from the stack
  while (!is_empty(stack)) {
    Reserva* popped_reserva = pop(stack);
    printf("%d/%d/%d %02d:%02d - %s %s", popped_reserva->dia, popped_reserva->mes, popped_reserva->ano, popped_reserva->hora, popped_reserva->minutos, popped_reserva->cliente->nome, popped_reserva->cliente->apelido);
    if (popped_reserva->tipo == 1) printf("\tLavagem\n");
    if (popped_reserva->tipo == 2) printf("\tManutencao\n");
  }
  
  // Free the stack memory
  free_stack(stack);
}

void show_pre_reserves_client_reverse(lista_Pre_Reservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
  Pre_ReservaStack* stack = create_pre_reserva_stack();
  Pre_Reserva* pre_res = lista->head;
  
  // Push pre-reservations of the specified client onto the stack in their original order
  while (pre_res != NULL) {
    if (strcmp(pre_res->cliente->nome, nome) == 0 && strcmp(pre_res->cliente->apelido, apelido) == 0) {
      push_pre_reserva(stack, pre_res);
    }
    pre_res = pre_res->next;
  }
  
  // Print pre-reservations in reverse order by popping them from the stack
  while (!is_pre_reserva_stack_empty(stack)) {
    Pre_Reserva* popped_pre_reserva = pop_pre_reserva(stack);
    printf("%d/%d/%d %02d:%02d - %s %s", popped_pre_reserva->dia, popped_pre_reserva->mes, popped_pre_reserva->ano, popped_pre_reserva->hora, popped_pre_reserva->minutos, popped_pre_reserva->cliente->nome, popped_pre_reserva->cliente->apelido);
    if (popped_pre_reserva->tipo == 1) printf("\tLavagem\n");
    if (popped_pre_reserva->tipo == 2) printf("\tManutencao\n");
  }
  
  // Free the stack memory
  free_pre_reserva_stack(stack);
}