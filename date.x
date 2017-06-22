/* date.x - arquivo de especificações (IDL). */

program DATEPROG {
    version DATEVERS {
        long OBTER_DATA(void) = 1; /* núm. do procedimento = 1 */
    } = 1; /* versão do programa = 1*/
} = 0x3012225; /* número do programa remoto (precisa ser único)*/