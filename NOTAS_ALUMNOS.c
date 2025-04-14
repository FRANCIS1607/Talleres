#include <stdio.h>

int main() {
    int nEst, nMaterias;

    // Solicita el numero de estudiantes y materias
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &nEst);

    printf("Ingrese el numero de materias: ");
    scanf("%d", &nMaterias);

    // Declaracion de matrices y arreglos para almacenar las calificaciones, promedios, maximos, minimos y cantidad de aprobados/reprobados
    float calificaciones[nEst][nMaterias];
    float promEst[nEst], promMaterias[nMaterias];
    float maxEst[nEst], minEst[nEst];
    float maxMateria[nMaterias], minMateria[nMaterias];
    int aprobados[nMaterias], reprobados[nMaterias];

    // Ingreso de calificaciones
    for (int i = 0; i < nEst; i++) {
        for (int j = 0; j < nMaterias; j++) {
            float nota;
            do {
                // Solicita la calificacion del estudiante en la materia correspondiente
                printf("Ingrese la nota del estudiante %d en la materia %d (0-10): ", i + 1, j + 1);
                scanf("%f", &nota);
                // Valida que la calificacion este en el rango correcto
                if (nota < 0 || nota > 10)
                    printf("Nota invalida! Intente nuevamente.\n");
            } while (nota < 0 || nota > 10); // Se repite hasta que la calificacion sea valida
            calificaciones[i][j] = nota;
        }
    }

    // Calculos de promedios, maximos, minimos, aprobados y reprobados
    for (int i = 0; i < nEst; i++) {
        maxEst[i] = minEst[i] = calificaciones[i][0]; 
        for (int j = 0; j < nMaterias; j++) {
            float nota = calificaciones[i][j];
            promEst[i] += nota;      
            promMaterias[j] += nota; 

            // Calcula el maximo y minimo de calificaciones por estudiante
            if (nota > maxEst[i]) maxEst[i] = nota;
            if (nota < minEst[i]) minEst[i] = nota;

            // Calcula el maximo y minimo de calificaciones por materia
            if (i == 0) {
                maxMateria[j] = minMateria[j] = nota;
            } else {
                if (nota > maxMateria[j]) maxMateria[j] = nota;
                if (nota < minMateria[j]) minMateria[j] = nota;
            }

            // Cuenta aprobados y reprobados por materia
            if (nota >= 6)
                aprobados[j]++;
            else
                reprobados[j]++;
        }
        // Calcula el promedio del estudiante
        promEst[i] /= nMaterias;
    }

    // Calcula el promedio de cada materia
    for (int j = 0; j < nMaterias; j++) {
        promMaterias[j] /= nEst;
    }

    // Resultados: Promedios, maximos y minimos por estudiante  
    printf("\n--- Promedios por Estudiante ---\n");
    for (int i = 0; i < nEst; i++) {
        printf("Estudiante %d: Promedio = %.2f | Maxima = %.2f | Minima = %.2f\n",
               i + 1, promEst[i], maxEst[i], minEst[i]);
    }

    // Resultados: Promedios, maximos y minimos por materia
    printf("\n--- Promedios por Materia ---\n");
    for (int j = 0; j < nMaterias; j++) {
        printf("Materia %d: Promedio = %.2f | Maxima = %.2f | Minima = %.2f\n",
               j + 1, promMaterias[j], maxMateria[j], minMateria[j]);
    }

    // Resultados: Aprobados y Reprobados por materia
    printf("\n--- Aprobados y Reprobados por Materia ---\n");
    for (int j = 0; j < nMaterias; j++) {
        printf("Materia %d: Aprobados = %d | Reprobados = %d\n",
               j + 1, aprobados[j], reprobados[j]);
    }

    return 0;
}
