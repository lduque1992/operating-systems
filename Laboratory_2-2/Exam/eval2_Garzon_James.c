#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct proc_{
  int id;
  char name[10];
  int size;
} PROC;

int print_menu();
int load_procs(FILE* procf_desc, PROC** p_procs, int n_entries);
void print_procs(PROC* p_procs, int n_entries);
int create_proc(PROC**, int*);
int delete_proc(PROC**, int*);
void save_procs(PROC* p_procs, int n_entries, FILE** procf_desc);

char* proc_file_name = "proc_file";

int main(){
  FILE *in_file;
  int ch;
  int n_entries = 0;
  int option = 0;
  PROC *p_procs;

  in_file = fopen(proc_file_name, "r+"); //Open file

  // Verificate if file exist
  if (in_file == NULL) { // File doesn't exist
  printf("No se puede abrir el archivo %s\n", proc_file_name);
  exit(8);
}

// Get the number of lines
while(!feof(in_file)){
  ch = fgetc(in_file);
  if(ch == '\n'){
    n_entries++;
  }
}

//  Sets the file position to the beginning of the file
rewind(in_file);

load_procs(in_file, &p_procs, n_entries);
fclose(in_file);

while (option != 4 && option != 5) {
  option = print_menu();
  switch (option) {
    case 1:
    print_procs(p_procs, n_entries);
    break;
    case 2:
    create_proc(&p_procs, &n_entries);
    print_procs(p_procs, n_entries);
    break;
    case 3:
    print_procs(p_procs, n_entries);
    delete_proc(&p_procs, &n_entries);
    break;
    case 4:
    save_procs(p_procs, n_entries, &in_file);
    break;
  }
}

printf("\nHas salido del programa\n\n");
return 0;
}

int print_menu(){
  int option = 0;

  printf("\nMENU DE OPCIONES\n");
  printf("1) Mostrar información\n");
  printf("2) Crear nueva entrada\n");
  printf("3) Eliminar una entrada del proceso\n");
  printf("4) Guardar cambios y salir\n");
  printf("5) Descartar cambios y salir\n\n");
  printf("Seleccione una opcion: ");

  setbuf(stdin, NULL);
  scanf("%d", &option);
  setbuf(stdin, NULL);

  return option;
}

int create_proc(PROC** p_procs, int* n_entries){
  PROC newProcess;
  *n_entries = *n_entries+1;
  *p_procs = realloc (*p_procs, sizeof (PROC)*(*n_entries));

  printf("Crear nuevo entrada\n");
  printf("Ingrese el id: ");
  scanf("%d", &newProcess.id);
  printf("\nIngrese el nombre: ");
  scanf("%s", newProcess.name);
  printf("\nIngrese el tamaño del archivo: ");
  scanf("%d", &newProcess.size);

  (*p_procs)[*n_entries-1] = newProcess;
  return 0;
}

int delete_proc(PROC** p_procs, int* n_entries){
  int id;
  int flag=0;
  printf("\nEliminar una entrada\n");
  printf("Ingrese el Id: ");
  scanf("%d", &id);

  for (int i = 0; i < *n_entries; i++) {
    if ((*p_procs)[i].id == id) {
      flag = 1;
    }
    if (flag == 1 && i < *n_entries-1) {
      (*p_procs)[i] = (*p_procs)[i+1];
    }
  }
  if (flag == 1) {
    *n_entries = *n_entries-1;
    *p_procs = realloc(*p_procs, sizeof(PROC)*(*n_entries));
    printf("\n¡Entrada eliminada!\n");
  }else{
    printf("\n¡No se encontro el Id!\n");
  }

  return flag;
}


int load_procs(FILE* procf_desc, PROC** p_procs, int n_entries){
  int i = 0;
  *p_procs = malloc (sizeof (PROC)*n_entries);

  if (p_procs == NULL){
    printf("Problemas separando la información al heap\n" );
    return -1;
  }
  while (fscanf(procf_desc, "%d\t%10s\t%d",  &(*p_procs+i)->id, (*p_procs+i)->name, &(*p_procs+i)->size) != EOF) {
    i++;
  }
  return i;
}

void print_procs(PROC* p_procs, int n_entries){
  const char id[] = "Id";
  const char name[] = "Nombre";
  const char size[] = "Tamaño";
  printf("\n|%s\t|%10s\t|%s\n", id, name, size);
  printf("-------------------------------\n");
  for (int i = 0; i < n_entries; i++) {
    printf("|%d\t|%10s\t|%d\n", (p_procs+i)->id, (p_procs+i)->name, (p_procs+i)->size);
  }
}

void save_procs(PROC* p_procs, int n_entries, FILE** procf_desc){
  *procf_desc = fopen(proc_file_name, "w+");
  for (int i = 0; i < n_entries; i++) {
    fprintf(*procf_desc, "%d\t%10s\t%d\n", p_procs[i].id, p_procs[i].name, p_procs[i].size);
  }
  fclose(*procf_desc);
  printf("\nSe han guardado los cambios exitosamente");
}
