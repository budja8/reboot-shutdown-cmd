#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu();
void commandShutdown(int tiempo);
void shutdownNow();
void messageAlert();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;
    do{
    	printf("\tPrograma Util en C\n\n");
	    printf("\t1. Reiniciar BIOS.\n");
	    printf("\n");
	    printf("\t2. Apagar PC en 5 minutos.\n");
	    printf("\t3. Apagar PC en 10 minutos.\n");
	    printf("\t4. Apagar PC en 15 minutos.\n");
	    printf("\t5. Apagar PC en 20 minutos.\n");
	    printf("\t6. Apagar PC en 30 minutos.\n");
	    printf("\t7. Apagar PC en 60 minutos.\n");
	    printf("\t8. Agregar un valor personalizado.\n");	
	    printf("\n");
	    printf("\t9. Apagar ya.\n");
	    printf("\t10. Cancelar apagado automatico.\n");
	    printf("\n");
	    printf("\t11. Salir.\n\n");
	    printf("\tElegir una opcion: ");
	    scanf("%d", &opcion); // Captura la elección del usuario
	
	    switch (opcion) {
	        case 1:
	        	system("shutdown /r /fw /f /t 0");
	            getch();
	            system("cls");
	            break;
	        case 2:
	            commandShutdown(300); // 5 minutos
	            break;
	        case 3:
	            commandShutdown(600); // 10 minutos
	            break;
	        case 4:
	            commandShutdown(900); // 15 minutos
	            break;
	        case 5:
	            commandShutdown(1200); // 20 minutos
	            break;
	        case 6:
	            commandShutdown(1800); // 30 minutos
	            break;
	        case 7:
	            commandShutdown(3600); // 60 minutos
	            break;
	        case 8:
	            int tiempoPersonalizado;
	            printf("\tIngresa el tiempo personalizado en segundos: ");
	            scanf("%d", &tiempoPersonalizado);
	            commandShutdown(tiempoPersonalizado); // Usar tiempo personalizado
	            break;
	        case 9:
	            shutdownNow();
	            break;
	        case 10:
	            system("shutdown /a");
	            system("cls");
	            break;
	        case 11:
	            break;
	        default:
	        	system("cls");
	            printf("\tOpcion invalida. ");
	            getch();
	            system("cls");
	    }
	}while(opcion!=11);
}

void commandShutdown(int tiempo) {
    char command[100];
    sprintf(command, "shutdown -s -t %d", tiempo);
    system(command);
    system("cls");
}

void shutdownNow(){
	messageAlert();
	system("shutdown /s /f /t 0");
	system("cls");
}

void messageAlert(){
	printf("\n");
	printf("\tEstas seguro de apagar?(S/N) ");
	getch();
	printf("\n");
	printf("\tDe verdad estas seguro?(S/N) ");
	getch();
	printf("\n");
	printf("\tEsta es la ultima advertencia\n\tDe verdad quieres hacerlo?(S/N)\n");	
}


