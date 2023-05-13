#include <stdio.h>


void show_Menu(){
    printf("\t.Bem.Vindo ao Sistema de Gestão de Reservas.\n\nSelecione a opção que deseja realizar (1 a 9)\nNo caso de inserir mais que um numero será tido em conta apenas o primeiro digito\n\n1.Agendar uma lavagem ou manutenção de carro\n2.Pré-agendar uma lavagem ou manutenção de carro\n3.Cancelar uma reserva\n4.Cancelar uma pré-agenda\n5.Listar reservas e pré-agendas\n6.Listar agendamentos e pré-agendamentos de um cliente\n7.Realizar uma lavagem ou manutenção\n8.Carregar informações de reserva do arquivo\n9.Salvar informações de reserva no arquivo\n10.Sair\n\n Insira a sua escolha\n\n");
    }




void print_morning_time_slots() {
    int time_slot = 1;
    for (int hour = HORA_ABERTURA; hour < 13; hour++) {
        for (int minute = 0; minute < 60; minute += 30) {
            printf("%d. %02d:%02d\n", time_slot, hour, minute);
            time_slot++;
        }
    }
}



void print_afternoon_time_slots_washing() {
    int time_slot = 1;
    for (int hour = 13; hour < 18; hour++) {
        for (int minute = 0; minute < 60; minute += 30) {
            printf("%d. %02d:%02d\n", time_slot, hour, minute);
            time_slot++;
        }
    }
  
}


void print_afternoon_time_slots_maintenance(){
    int time_slot = 1;
    for (int hour = 13; hour < 17; hour++) {
        for (int minute = 0; minute < 60; minute += 30) {
            printf("%d. %02d:%02d\n", time_slot, hour, minute);
            time_slot++;
        }
    }
  printf("%d. %02d:00\n", time_slot, 17); // add the 18:00 time slot
}