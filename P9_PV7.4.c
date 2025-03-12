#include <stdio.h>
#include <stdint.h>
#include <math.h>

void displayMenu(); //Inicializar funci�n


int main(){

    uint32_t select;
    int32_t num1, num2;

    displayMenu();
    scanf("%u", &select);

    switch(select){ //Seg�n el caso ocurrir� una cosa u otra

    case 1:
        printf("SUMA -> Introduce dos numeros: ");
        scanf("%d %d", &num1, &num2); //Leer los n�meros introducidos
        printf("Resultado: %d\n", num1+num2); //Operar y mostrar resultado
        break;

    case 2:
        printf("RESTA -> Introduce dos numeros: ");
        scanf("%d %d", &num1, &num2);
        printf("Resultado: %d\n", num1-num2);
        break;

    case 3:
        printf("MULTIPLICACION -> Introduce dos numeros: ");
        scanf("%d %d", &num1, &num2);
        printf("Resultado: %d\n", num1*num2);
        break;

    case 4:
        printf("DIVISION -> Introduce dos numeros: ");
        scanf("%d %d", &num1, &num2);
        printf("Resultado: %d\n", num1/num2);
        break;
    }

    return 0;
}



void displayMenu(){

    printf("Selecciona una operacion \n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division entera\n");

}

