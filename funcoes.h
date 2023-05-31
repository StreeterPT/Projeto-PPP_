#define HORA_ABERTURA 8
#define HORA_FECHO 18

#define true 1
#define false 0

// Initialize a new Reserva list
listaReservas* criar_lista_reservas() {
  listaReservas* lista = (listaReservas*)malloc(sizeof(listaReservas));
  lista->head = NULL;
  return lista;
}



// Print all Reservas in the list
void print_Reservas(listaReservas* lista) {
  Reserva* res = lista->head;
  while (res != NULL) {
    printf("%d/%d/%d %02d:%02d - %s %s", res->dia, res->mes, res->ano, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
    if(res->tipo==1)printf("\tLavagem\n");
    if(res->tipo==2)printf("\tManutencao\n");
    res = res->next;
  }
}

void print_Pre_Reservas(lista_Pre_Reservas* lista) {
  Pre_Reserva* pre_res = lista->head;
  while (pre_res != NULL) {
    printf("%d/%d/%d %02d:%02d - %s %s", pre_res->dia, pre_res->mes, pre_res->ano, pre_res->hora, pre_res->minutos, pre_res->cliente->nome, pre_res->cliente->apelido);
    if (pre_res->tipo == 1) printf("\tLavagem\n");
    if (pre_res->tipo == 2) printf("\tManutencao\n");
    pre_res = pre_res->next;
  }
}

void check_if_there_is_reservation_and_erase(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
    Reserva* res = lista->head;
    Reserva* reserva_anterior = NULL;
    int user_inp;

    while (res != NULL) {
        if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
            printf("%d/%d/%d %02d:%02d - %s %s", res->dia, res->mes, res->ano, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
            if (res->tipo == 1) {
                printf("\tLavagem\n");
            }
            if (res->tipo == 2) {
                printf("\tManutencao\n");
            }
            printf("Deseja cancelar esta reserva?\n\n1. Sim\n2. Nao\n");
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



void check_if_there_is_pre_reservation_and_erase(lista_Pre_Reservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
    Pre_Reserva* res = lista->head;
    Pre_Reserva* reserva_anterior = NULL;
    int user_inp;

    while (res != NULL) {
        if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
            printf("%d/%d/%d %02d:%02d - %s %s", res->dia, res->mes, res->ano, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
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
                printf("A pre reserva foi cancelada.\n");
            } else if (user_inp == 2) {
                printf("A reserva não será cancelada.\n");
            }
        }

        reserva_anterior = res;
        res = res->next;
    }
}


int is_store_open(int hora,int minutos,int tipo){
    if (hora < HORA_ABERTURA || hora >= HORA_FECHO)
        return 0;

    else if (tipo == 2 && hora == HORA_FECHO - 1 && minutos > 0)
            return 0;
  
    else if (tipo==1 && hora == HORA_FECHO - 1 && minutos > 30)
            return 0;
    

    else return 1;
}





void show_reserves_client(listaReservas* lista, char nome[MAX_NOME], char apelido[MAX_NOME]) {
  Reserva* res = lista->head;
  while (res != NULL) {
    if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
      printf("%d/%d/%d %02d:%02d - %s %s", res->ano, res->mes, res->dia, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
      if (res->tipo == 1) printf("\tLavagem\n");
      if (res->tipo == 2) printf("\tManutencao\n");
    }
    res = res->next;
  }
}



int is_more_recent(int year1, int month1, int day1, int hour1, int minute1,
                   int year2, int month2, int day2, int hour2, int minute2) {
    if (year1 != year2)
        return year1 > year2;
    if (month1 != month2)
        return month1 > month2;
    if (day1 != day2)
        return day1 > day2;
    if (hour1 != hour2)
        return hour1 > hour2;
    return minute1 > minute2;
}






int is_available(listaReservas* lista, int ano, int mes, int dia, int hora, int minutos, int tipo) {
    Reserva* res = lista->head;
    int minutos_inicial = (hora * 60) + minutos;
    int minutos_final = minutos_inicial + (tipo * 30);

    while (res != NULL) {
        if (res->ano == ano && res->mes == mes && res->dia == dia) {
            int reserva_minutos_inicial = (res->hora * 60) + res->minutos;
            int reserva_minutos_final = reserva_minutos_inicial + (res->tipo * 30);

            if (!(minutos_inicial >= reserva_minutos_final || minutos_final <= reserva_minutos_inicial)) {
                return 0;  // Return 0 indicating a collision when there is an overlapping reservation
            }
        }
        res = res->next;
    }

    return 1;  // Return 1 indicating the time slot is available when no collisions are found
}

int is_available_pre_reservas(lista_Pre_Reservas* lista_, int ano, int mes, int dia, int hora, int minutos, int tipo) {
     Pre_Reserva* pre_reserva = lista_->head;

    int minutos_inicial = (hora * 60) + minutos;
    int minutos_final = minutos_inicial + (tipo * 30);

    while (pre_reserva != NULL) {
        if (pre_reserva->ano == ano && pre_reserva->mes == mes && pre_reserva->dia == dia) {
            int pre_reservaerva_minutos_inicial = (pre_reserva->hora * 60) + pre_reserva->minutos;
            int pre_reservaerva_minutos_final = pre_reservaerva_minutos_inicial + (pre_reserva->tipo * 30);

            if (!(minutos_inicial >= pre_reservaerva_minutos_final || minutos_final <= pre_reservaerva_minutos_inicial)) {
                return 0;  // Return 0 indicating a collision when there is an overlapping pre_reservaervation
            }
        }
        pre_reserva = pre_reserva->next;
    }

    return 1;  // Return 1 indicating the time slot is available when no collisions are found
}




void add_Pre_Reserva_ordem(lista_Pre_Reservas* lista, Cliente* cliente, int ano, int mes, int dia, int hora, int minutos, int tipo) {


    // Create a new Reserva struct
   Pre_Reserva* pre_res = (Pre_Reserva*)malloc(sizeof(Pre_Reserva));
    pre_res->cliente = cliente;
    pre_res->ano = ano;
    pre_res->mes = mes;
    pre_res->dia = dia;
    pre_res->hora = hora;
    pre_res->minutos = minutos;
    pre_res->tipo = tipo;
    pre_res->flag = flag(lista);
    pre_res->next = NULL;
    


    // Add the Reserva to the list
    if (lista->head == NULL) {
        // If the list is empty, set the head and tail pointers to the new Reserva
        lista->head = pre_res;}
     
     else if (!is_more_recent(ano, mes, dia, hora, minutos, lista->head->ano, lista->head->mes,
                             lista->head->dia, lista->head->hora, lista->head->minutos)) {
        // If the new reservation is older than the current head, make it the new head
        pre_res->next = lista->head;
        lista->head = pre_res;
    } else {
        // Find the appropriate position to insert the new reservation in the sorted list
        Pre_Reserva* current = lista->head;
        while (current->next != NULL &&
               is_more_recent(ano, mes, dia, hora, minutos, current->next->ano, current->next->mes,
                               current->next->dia, current->next->hora, current->next->minutos)) {
            current = current->next;
        }

        // Insert the new reservation after the current node
        pre_res->next = current->next;
        current->next = pre_res;

        
    }
}






void add_Reserva_ordem_oposta(listaReservas* lista, Cliente* cliente, int ano, int mes, int dia, int hora, int minutos, int tipo) {
    // Create a new Reserva struct
    Reserva* res = (Reserva*)malloc(sizeof(Reserva));
    res->cliente = cliente;
    res->ano = ano;
    res->mes = mes;
    res->dia = dia;
    res->hora = hora;
    res->minutos = minutos;
    res->tipo = tipo;
    res->next = NULL;

    // Add the Reserva to the list
    if (lista->head == NULL) {
        // If the list is empty, set the head and tail pointers to the new Reserva
        lista->head = res;
    } else if (!is_more_recent(ano, mes, dia, hora, minutos, lista->head->ano, lista->head->mes,
                             lista->head->dia, lista->head->hora, lista->head->minutos)) {
        // If the new reservation is more recent than the current head, make it the new head
        res->next = lista->head;
        lista->head = res;
    } else {
        // Find the appropriate position to insert the new reservation in the sorted list
        Reserva* current = lista->head;
        while (current->next != NULL &&
               is_more_recent(ano, mes, dia, hora, minutos, current->next->ano, current->next->mes,
                               current->next->dia, current->next->hora, current->next->minutos)) {
            current = current->next;
        }

        // Insert the new reservation after the current node
        res->next = current->next;
        current->next = res;
    }
}






void advance_time_with_pre_reservations(listaReservas* lista, lista_Pre_Reservas* lista_) {
    Reserva* primeira_reserva = lista->head;

    if (primeira_reserva == NULL) {
        // No reservations in the list
        return;
    }

    Reserva* segunda = primeira_reserva->next;
    lista->head = segunda;

    // Remove pre-reservations that collide with the first reservation
    Pre_Reserva* pre_reserva = lista_->head;
    Pre_Reserva* previous = NULL;

    while (pre_reserva != NULL) {
        if (is_available_pre_reservas(lista_, primeira_reserva->ano, primeira_reserva->mes, primeira_reserva->dia,
                                      primeira_reserva->hora, primeira_reserva->minutos, primeira_reserva->tipo)) {
            // No collision, keep the pre-reservation
            previous = pre_reserva;
            pre_reserva = pre_reserva->next;
        } else {
            // Collision, remove the pre-reservation
            if (previous != NULL) {
                previous->next = pre_reserva->next;
            } else {
                lista_->head = pre_reserva->next;
            }
            Pre_Reserva* colide = pre_reserva;
            pre_reserva = pre_reserva->next;
            free(colide);
        }
    }

    free(primeira_reserva);
}




void writePreReservationsToFile(lista_Pre_Reservas* lista){
    
    FILE* file = fopen("Dados Pre Reservas.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "Dados do Sistema de Reservas\n");
    fprintf(file, "Pre Reservas:\n");
    Pre_Reserva* current = lista->head;
    while (current != NULL) {
        const char* tipoString = (current->tipo == 1) ? "lavagem" : "manutencao";
        fprintf(file, "%02d/%02d/%04d %02d:%02d - %s %s %s %s\n",
                current->dia, current->mes, current->ano,
                current->hora, current->minutos,
                current->cliente->nome, current->cliente->apelido,current->cliente->n_telemovel,tipoString);
        
        current = current->next;
    }
fclose(file);

}

void readPreReservationsFromFile(lista_Pre_Reservas* lista) {
    FILE* file = fopen("Dados Pre Reservas.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file);  // Read the header line
    fgets(line, sizeof(line), file);  // Read the "Pre Reservas:" line

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '\n')  // Skip empty lines
            continue;
        Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
        int dia, mes, ano, hora, minutos, tipo;
        char tipoString[15];

        sscanf(line, "%2d/%2d/%4d %2d:%2d - %[^ ] %[^ ] %[^ ] %[^ ]",
               &dia, &mes, &ano, &hora, &minutos, cliente->nome, cliente->apelido, cliente->n_telemovel, tipoString);

        if (strcmp(tipoString, "manutencao") == 0) {
            tipo = 2;
        } else {
            tipo = 1;
        }

        // Assuming you have a function named 'add_Pre_Reserva' to add pre-reservations
        add_Pre_Reserva_ordem(lista,cliente,ano,mes,dia,hora,minutos,tipo);
    }

    fclose(file);
}



void writeReservationsToFile(listaReservas* lista) {
    FILE* file = fopen("Dados Reservas.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Write the title and subtitle
    fprintf(file, "Dados do Sistema de Reservas\n");
    fprintf(file, "Reservas:\n");

    // Iterate over the reservation list and write the reservations
    Reserva* current = lista->head;
    while (current != NULL) {
        const char* tipoString = (current->tipo == 1) ? "lavagem" : "manutencao";
        fprintf(file, "%02d/%02d/%04d %02d:%02d - %s %s %s %s\n",
                current->dia, current->mes, current->ano,
                current->hora, current->minutos,
                current->cliente->nome, current->cliente->apelido,current->cliente->n_telemovel,tipoString);
        
        current = current->next;
    }
    fclose(file);

}



void readReservationsFromFile(listaReservas* lista) {
    FILE* file = fopen("Dados Reservas.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[100];
    fgets(line, sizeof(line), file);  // Read the header line
    fgets(line, sizeof(line), file);  // Read the "Reservas:" line

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '\n')  // Skip empty lines
            continue;
        Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
        int dia, mes, ano, hora, minutos, tipo;
        char tipoString[15];

        sscanf(line, "%2d/%2d/%4d %2d:%2d - %[^ ] %[^ ] %[^ ] %[^ ]",
               &dia, &mes, &ano, &hora, &minutos, cliente->nome, cliente->apelido, cliente->n_telemovel, tipoString);

        if (strcmp(tipoString, "manutencao") == 0) {
            tipo = 2;
        } else {
            tipo = 1;
        }

        // Assuming you have a function named 'add_Pre_Reserva' to add pre-reservations
       add_Reserva_ordem_oposta(lista,cliente,ano,mes,dia,hora,minutos,tipo);
    }

    fclose(file);
}










Pre_Reserva* find_available_pre_reserva(lista_Pre_Reservas* lista_pre_reservas, int ano, int mes, int dia, int hora, int minutos, int tipo) {
    Pre_Reserva* pre_reserva = lista_pre_reservas->head;
    Pre_Reserva* available_pre_reserva = NULL;
    int lowest_flag = INT_MAX;

    while (pre_reserva != NULL) {
        if (pre_reserva->ano == ano && pre_reserva->mes == mes && pre_reserva->dia == dia) {
            int pre_reserva_minutos_inicial = (pre_reserva->hora * 60) + pre_reserva->minutos;
            int pre_reserva_minutos_final = pre_reserva_minutos_inicial + (pre_reserva->tipo * 30);

            int reserva_minutos_inicial = (hora * 60) + minutos;
            int reserva_minutos_final = reserva_minutos_inicial + (tipo * 30);

            if (pre_reserva_minutos_inicial >= reserva_minutos_inicial && pre_reserva_minutos_final <= reserva_minutos_final) {
                if (pre_reserva->flag < lowest_flag) {
                    lowest_flag = pre_reserva->flag;
                    available_pre_reserva = pre_reserva;
                }
            }
        }

        pre_reserva = pre_reserva->next;
    }

    return available_pre_reserva;
}



void free_pre_reserva(lista_Pre_Reservas* lista_pre_reservas, Pre_Reserva* pre_reserva) {
    if (pre_reserva == NULL) {
        return;  // Invalid pre-reservation pointer
    }

    Pre_Reserva* current = lista_pre_reservas->head;
    Pre_Reserva* previous = NULL;

    // Find the pre-reservation in the list
    while (current != NULL && current != pre_reserva) {
        previous = current;
        current = current->next;
    }

    // If pre-reservation not found
    if (current == NULL) {
        return;  // Pre-reservation not found in the list
    }

    // Update pointers and deallocate memory
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        lista_pre_reservas->head = current->next;
    }

    free(pre_reserva);
}

Pre_Reserva* find_conflicting_pre_reserva(lista_Pre_Reservas* lista_, int ano, int mes, int dia, int hora, int minutos, int tipo) {
    Pre_Reserva* pre_reserva = lista_->head;
    Pre_Reserva* conflicting_pre_reserva = NULL;
    int lowest_flag = INT_MAX;

    int minutos_inicial = (hora * 60) + minutos;
    int minutos_final = minutos_inicial + (tipo * 30);

    while (pre_reserva != NULL) {
        if (pre_reserva->ano == ano && pre_reserva->mes == mes && pre_reserva->dia == dia) {
            int pre_reserva_minutos_inicial = (pre_reserva->hora * 60) + pre_reserva->minutos;
            int pre_reserva_minutos_final = pre_reserva_minutos_inicial + (pre_reserva->tipo * 30);

            if (!(minutos_inicial >= pre_reserva_minutos_final || minutos_final <= pre_reserva_minutos_inicial)) {
                if (pre_reserva->flag < lowest_flag) {
                    lowest_flag = pre_reserva->flag;
                    conflicting_pre_reserva = pre_reserva;
                }
            }
        }
        pre_reserva = pre_reserva->next;
    }

    return conflicting_pre_reserva;  // Return the conflicting pre_reserva with the lowest flag value or NULL if no conflict is found
}

void check_if_there_is_reservation_and_erase_2(listaReservas* lista, lista_Pre_Reservas* lista_pre_reservas, char nome[MAX_NOME], char apelido[MAX_NOME]) {
    Reserva* res = lista->head;
    Reserva* reserva_anterior = NULL;
    int user_inp;

    while (res != NULL) {
        if (strcmp(res->cliente->nome, nome) == 0 && strcmp(res->cliente->apelido, apelido) == 0) {
            printf("%d/%d/%d %02d:%02d - %s %s", res->dia, res->mes, res->ano, res->hora, res->minutos, res->cliente->nome, res->cliente->apelido);
            if (res->tipo == 1) {
                printf("\tLavagem\n");
            }
            if (res->tipo == 2) {
                printf("\tManutenção\n");
            }
            printf("Deseja cancelar esta reserva?\n\n1. Sim\n2. Nao\n");
            scanf("%d", &user_inp);

            if (user_inp == 1) {
                int ano = res->ano;
                int mes = res->mes;
                int dia = res->dia;
                int hora = res->hora;
                int minutos = res->minutos;
                int tipo = res->tipo;
                

                if (reserva_anterior != NULL) {
                    reserva_anterior->next = res->next;
                } else {
                    lista->head = res->next;
                }

                printf("A reserva foi cancelada.\n");
                free(res);
                //
                
                


                Pre_Reserva* current_pre_reserva = lista_pre_reservas->head;
                Pre_Reserva* previous_pre_reserva = NULL;
                
                while (current_pre_reserva != NULL) {
                if (!is_available_pre_reservas(lista_pre_reservas,ano,mes,dia,hora,minutos,tipo) && is_available(lista,current_pre_reserva->ano, current_pre_reserva->mes,  current_pre_reserva->dia,current_pre_reserva->hora,  current_pre_reserva->minutos, current_pre_reserva->tipo)){
                    Cliente* cliente_ = (Cliente*) malloc(sizeof(Cliente));
                    strcpy(cliente_->nome,current_pre_reserva->cliente->nome);
                    strcpy(cliente_->apelido,current_pre_reserva->cliente->apelido);
                    strcpy(cliente_->n_telemovel,current_pre_reserva->cliente->n_telemovel);
                    add_Reserva_ordem_oposta(lista,cliente_,current_pre_reserva->ano,current_pre_reserva->mes,current_pre_reserva->dia,current_pre_reserva->hora,current_pre_reserva->minutos,current_pre_reserva->tipo);
                    if (previous_pre_reserva == NULL) {
                    // The current pre_reserva is the head of the list
                    lista_pre_reservas->head = current_pre_reserva->next;
                    } else {
                    // The current pre_reserva is not the head of the list
                    previous_pre_reserva->next = current_pre_reserva->next;
                    }
                    
                    Pre_Reserva* next_pre_reserva = current_pre_reserva->next;
                    free(current_pre_reserva);
                    current_pre_reserva= next_pre_reserva;
                     // Move to the next pre_reserva in the list
                    printf("A reserva foi substituida por uma pre-reserva.\n");}
                else {
                    previous_pre_reserva = current_pre_reserva;
                    current_pre_reserva = current_pre_reserva->next;
                    }}
                    break;
                
                
            
                }
                }

            
        reserva_anterior = res;
        res = res->next;
        }

    }

