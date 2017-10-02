
-------------------------------------------

int length (const char *);

int main(int argc, const char *argv[])
{
    int len,i,j;
    char st[100];
    len = (int)sizeof(argv);
    strcpy(st, "");
    for (i = 1; i < len; ++i)
    {   
        if(argv[i] !='\0'){
            strcat(st,(char *)argv[i]);
            strcat(st," ");
        }else{
            i = len;
        }
    }
    strcat(st,"\n");
    j =length(st);
    write(1,(const char *)st, j);
    return 0;
}

int length (const char * d){
    int i;
    for (i = 0;d[i]!='\0'; i++);
    return i;
}

------------------------------------------
int main()
{   
    
    int n= sizeof("\033[2J\033[1;1H");
    write(1,"\033[2J\033[1;1H",n);
    return 0;
}

--------------------------------------------




int main(int argc, char **argv){    
    if (argc < 2){
        printf("usage: ./kill PID");
        return -1;
    }
    int signal = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);
    
    if(signal == -9 || signal == -7 || signal == 0 || signal == -1 || signal == -2 || signal == -3){
        kill(pid , SIGKILL);
    }
    else{
        printf("Señal invalida\n");
    }
    return 0;
}

-------------------------------------------------------
main() {
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);

    char output[128];

    strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
    printf("Fecha y Hora: %s\n",output);

    //system("PAUSE>NULL");
}

----------------------------------------------------------
int main()
{
    int n= sizeof("Presione [Enter] para continuar: ... ");
    write(1,"Presione [Enter] para continuar: ... ",n);
    
    while ( getchar() != '\n');
    return 0;
}