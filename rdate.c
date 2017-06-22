/* rdate.c - programa cliente */

#include <stdio.h>
#include <rpc/rpc.h>
#include <stdlib.h>
#include <time.h>
#include "date.h"

int main(int argc, char *argv[]) {
    CLIENT *cl;
    char *server;
    long *lres;
    
    struct tm date;
    char date_str[80];
    
    if (argc != 2) {
        fprintf(stderr, "uso: %s <ip do servidor>\n", argv[0]);
        exit(1);
    }
    
    server = argv[1];
    
    /* cria o handle do cliente */ 
    if ((cl = clnt_create(server, DATEPROG, DATEVERS, "udp")) == NULL) {
        printf("não foi possível conectar-se ao servidor %s\n", server);
        exit(2);
    }
    
    /* chamada ao procedimento remoto obter_data() */
    if ((lres = obter_data_1(NULL, cl)) == NULL) {
        printf("erro ao executar o procedimento remoto obter_data()\n");
        exit(3);
    }
    
    /* converte timestamp obtido em uma string */
    localtime_r(lres, &date);
    strftime(date_str, 80, "%d/%m/%Y - %H:%M:%S", &date);
    
    /* exibe a data obtida */
    printf("data no servidor %s: %s\n", server, date_str);
    
    clnt_destroy(cl); /* finaliza o handle */
    
    return 0;
}