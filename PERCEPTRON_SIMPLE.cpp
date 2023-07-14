#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAINING_SET_SIZE 26
#define TESTING_SET_SIZE 6


int index_is_duplicate(int array[], int size, int index) {
    for (int i = 0; i < size; i++) {
        if (array[i] == index) {
            return 1;  // El índice es duplicado
        }
    }
    return 0;  // El índice no es duplicado
}

void print_values(int ejemplos[][6], int deseada[], float peso[]) {
    for (int i = 0; i < 26; i++) {
        float sumaXiWi = 0.0;
        for (int j = 0; j < 6; j++) {
            sumaXiWi += ejemplos[i][j] * peso[j];
        }
        int obtenida = (sumaXiWi > 0) ? 1 : 0;

        printf("%d %d %d %d %d %d  deseada: %d obtenida: %d   ", ejemplos[i][0], ejemplos[i][1], ejemplos[i][2],
               ejemplos[i][3], ejemplos[i][4], ejemplos[i][5], deseada[i], obtenida);

        printf("W1=%.2f W2=%.2f W3=%.2f W4=%.2f W5=%.2f W6=%.2f\n", peso[0], peso[1], peso[2], peso[3], peso[4], peso[5]);
    }
    printf("\n");
}

int main() {
    int ejemplos[32][6];
    int deseada[32];
    float peso[6];
    int training_indices[TRAINING_SET_SIZE];
    int testing_indices[TESTING_SET_SIZE];

    // ejemplos      X1   X2   X3   X4   X5   X6 (bias)   Sd
    ejemplos[0][0] = 1; ejemplos[0][1] = 1; ejemplos[0][2] = 1; ejemplos[0][3] = 1; ejemplos[0][4] = 1; ejemplos[0][5] = 1; deseada[0] = 1;
    ejemplos[1][0] = 1; ejemplos[1][1] = 1; ejemplos[1][2] = 1; ejemplos[1][3] = 1; ejemplos[1][4] = 0; ejemplos[1][5] = 1; deseada[1] = 1;
    ejemplos[2][0] = 1; ejemplos[2][1] = 1; ejemplos[2][2] = 1; ejemplos[2][3] = 0; ejemplos[2][4] = 1; ejemplos[2][5] = 1; deseada[2] = 1;
    ejemplos[3][0] = 1; ejemplos[3][1] = 1; ejemplos[3][2] = 1; ejemplos[3][3] = 0; ejemplos[3][4] = 0; ejemplos[3][5] = 1; deseada[3] = 1;
    ejemplos[4][0] = 1; ejemplos[4][1] = 1; ejemplos[4][2] = 0; ejemplos[4][3] = 1; ejemplos[4][4] = 1; ejemplos[4][5] = 1; deseada[4] = 1;
    ejemplos[5][0] = 1; ejemplos[5][1] = 1; ejemplos[5][2] = 0; ejemplos[5][3] = 1; ejemplos[5][4] = 0; ejemplos[5][5] = 1; deseada[5] = 1;
    ejemplos[6][0] = 1; ejemplos[6][1] = 1; ejemplos[6][2] = 0; ejemplos[6][3] = 0; ejemplos[6][4] = 1; ejemplos[6][5] = 1; deseada[6] = 1;
    ejemplos[7][0] = 1; ejemplos[7][1] = 1; ejemplos[7][2] = 0; ejemplos[7][3] = 0; ejemplos[7][4] = 0; ejemplos[7][5] = 1; deseada[7] = 0;
    ejemplos[8][0] = 1; ejemplos[8][1] = 0; ejemplos[8][2] = 1; ejemplos[8][3] = 1; ejemplos[8][4] = 1; ejemplos[8][5] = 1; deseada[8] = 1;
    ejemplos[9][0] = 1; ejemplos[9][1] = 0; ejemplos[9][2] = 1; ejemplos[9][3] = 1; ejemplos[9][4] = 0; ejemplos[9][5] = 1; deseada[9] = 1;
    ejemplos[10][0] = 1; ejemplos[10][1] = 0; ejemplos[10][2] = 1; ejemplos[10][3] = 0; ejemplos[10][4] = 1; ejemplos[10][5] = 1; deseada[10] = 1;
    ejemplos[11][0] = 1; ejemplos[11][1] = 0; ejemplos[11][2] = 1; ejemplos[11][3] = 0; ejemplos[11][4] = 0; ejemplos[11][5] = 1; deseada[11] = 0;
    ejemplos[12][0] = 1; ejemplos[12][1] = 0; ejemplos[12][2] = 0; ejemplos[12][3] = 1; ejemplos[12][4] = 1; ejemplos[12][5] = 1; deseada[12] = 1;
    ejemplos[13][0] = 1; ejemplos[13][1] = 0; ejemplos[13][2] = 0; ejemplos[13][3] = 1; ejemplos[13][4] = 0; ejemplos[13][5] = 1; deseada[13] = 0;
    ejemplos[14][0] = 1; ejemplos[14][1] = 0; ejemplos[14][2] = 0; ejemplos[14][3] = 0; ejemplos[14][4] = 1; ejemplos[14][5] = 1; deseada[14] = 0;
    ejemplos[15][0] = 1; ejemplos[15][1] = 0; ejemplos[15][2] = 0; ejemplos[15][3] = 0; ejemplos[15][4] = 0; ejemplos[15][5] = 1; deseada[15] = 0;
    ejemplos[16][0] = 0; ejemplos[16][1] = 1; ejemplos[16][2] = 1; ejemplos[16][3] = 1; ejemplos[16][4] = 1; ejemplos[16][5] = 1; deseada[16] = 1;
    ejemplos[17][0] = 0; ejemplos[17][1] = 1; ejemplos[17][2] = 1; ejemplos[17][3] = 1; ejemplos[17][4] = 0; ejemplos[17][5] = 1; deseada[17] = 1;
    ejemplos[18][0] = 0; ejemplos[18][1] = 1; ejemplos[18][2] = 1; ejemplos[18][3] = 0; ejemplos[18][4] = 1; ejemplos[18][5] = 1; deseada[18] = 1;
    ejemplos[19][0] = 0; ejemplos[19][1] = 1; ejemplos[19][2] = 1; ejemplos[19][3] = 0; ejemplos[19][4] = 0; ejemplos[19][5] = 1; deseada[19] = 0;
    ejemplos[20][0] = 0; ejemplos[20][1] = 1; ejemplos[20][2] = 0; ejemplos[20][3] = 1; ejemplos[20][4] = 1; ejemplos[20][5] = 1; deseada[20] = 1;
    ejemplos[21][0] = 0; ejemplos[21][1] = 1; ejemplos[21][2] = 0; ejemplos[21][3] = 1; ejemplos[21][4] = 0; ejemplos[21][5] = 1; deseada[21] = 0;
    ejemplos[22][0] = 0; ejemplos[22][1] = 1; ejemplos[22][2] = 0; ejemplos[22][3] = 0; ejemplos[22][4] = 1; ejemplos[22][5] = 1; deseada[22] = 0;
    ejemplos[23][0] = 0; ejemplos[23][1] = 1; ejemplos[23][2] = 0; ejemplos[23][3] = 0; ejemplos[23][4] = 0; ejemplos[23][5] = 1; deseada[23] = 0;
    ejemplos[24][0] = 0; ejemplos[24][1] = 0; ejemplos[24][2] = 1; ejemplos[24][3] = 1; ejemplos[24][4] = 1; ejemplos[24][5] = 1; deseada[24] = 1;
    ejemplos[25][0] = 0; ejemplos[25][1] = 0; ejemplos[25][2] = 1; ejemplos[25][3] = 1; ejemplos[25][4] = 0; ejemplos[25][5] = 1; deseada[25] = 0;
    ejemplos[26][0] = 0; ejemplos[26][1] = 0; ejemplos[26][2] = 1; ejemplos[26][3] = 1; ejemplos[26][4] = 1; ejemplos[26][5] = 1; deseada[26] = 1;
    ejemplos[27][0] = 0; ejemplos[27][1] = 0; ejemplos[27][2] = 1; ejemplos[27][3] = 1; ejemplos[27][4] = 0; ejemplos[27][5] = 1; deseada[27] = 0;
    ejemplos[28][0] = 0; ejemplos[28][1] = 0; ejemplos[28][2] = 0; ejemplos[28][3] = 0; ejemplos[28][4] = 1; ejemplos[28][5] = 1; deseada[28] = 0;
    ejemplos[29][0] = 0; ejemplos[29][1] = 0; ejemplos[29][2] = 0; ejemplos[29][3] = 0; ejemplos[29][4] = 0; ejemplos[29][5] = 1; deseada[29] = 0;
    ejemplos[30][0] = 0; ejemplos[30][1] = 0; ejemplos[30][2] = 0; ejemplos[30][3] = 1; ejemplos[30][4] = 1; ejemplos[30][5] = 1; deseada[30] = 0;
    ejemplos[31][0] = 0; ejemplos[31][1] = 0; ejemplos[31][2] = 0; ejemplos[31][3] = 1; ejemplos[31][4] = 0; ejemplos[31][5] = 1; deseada[31] = 0;
   
    peso[0] = 1.0; peso[1] = 3.0; peso[2] = 4.0; peso[3] = 0.0; peso[4] = 6.0; peso[5] = 0.0;

    srand(time(NULL));

    // Generar índices aleatorios para el conjunto de entrenamiento (80%) y el conjunto de prueba (20%)
   
    for (int i = 0; i < TRAINING_SET_SIZE; i++) {
        int index;
        do {
            index = rand() % 32;
        } while (index_is_duplicate(training_indices, i, index));
        training_indices[i] = index;
    }

    for (int i = 0; i < TESTING_SET_SIZE; i++) {
        int index;
        do {
            index = rand() % 32;
        } while (index_is_duplicate(training_indices, TRAINING_SET_SIZE, index) || index_is_duplicate(testing_indices, i, index));
        testing_indices[i] = index;
    }

    printf("Indices de entrenamiento: ");
    for (int i = 0; i < TRAINING_SET_SIZE; i++) {
        printf("%d ", training_indices[i]);
    }
    printf("\n");

    printf("Indices de prueba: ");
    for (int i = 0; i < TESTING_SET_SIZE; i++) {
        printf("%d ", testing_indices[i]);
    }
    printf("\n\n");

    // Entrenamiento
    int epocas = 0;
    int ok;
    do {
        epocas++;
        ok = 0;
        
        for (int i = 0; i < TRAINING_SET_SIZE; i++) {
            int example_index = training_indices[i];

            float sumaXiWi = 0.0;
            for (int j = 0; j < 6; j++) {
                sumaXiWi += ejemplos[example_index][j] * peso[j];
            }

            int obtenida = (sumaXiWi > 0) ? 1 : 0;

            if (deseada[example_index] != obtenida) {
                if (deseada[example_index] > obtenida) {
                    for (int j = 0; j < 6; j++) {
                        peso[j] += ejemplos[example_index][j];
                    }
                } else {
                    for (int j = 0; j < 6; j++) {
                        peso[j] -= ejemplos[example_index][j];
                    }
                }
            } else {
                ok++;
            }
        }
        
        printf("Época %d:\n", epocas);
        printf("\nX1 X2 X3 X4 X5 bias\n");
        print_values(ejemplos, deseada, peso);
    } while (ok < TRAINING_SET_SIZE);
    
    int error_prueba = 0;
for (int i = 0; i < TESTING_SET_SIZE; i++) {
    int example_index = testing_indices[i];
    float sumaXiWi = 0.0;
    for (int j = 0; j < 6; j++) {
        sumaXiWi += ejemplos[example_index][j] * peso[j];
    }
    int obtenida = (sumaXiWi > 0) ? 1 : 0;

    if (deseada[example_index] != obtenida) {
        error_prueba++;
    }
}

float porcentaje_error_prueba = (float)error_prueba / TESTING_SET_SIZE * 100;
printf("Porcentaje de error en el conjunto de prueba: %.2f%%\n", porcentaje_error_prueba);


    printf("SE NECESITARON %d EPOCAS\n", epocas);

    printf("\nValores del conjunto de prueba:\n");
    for (int i = 0; i < TESTING_SET_SIZE; i++) {
        int example_index = testing_indices[i];
        float sumaXiWi = 0.0;
        for (int j = 0; j < 6; j++) {
            sumaXiWi += ejemplos[example_index][j] * peso[j];
        }
        int obtenida = (sumaXiWi > 0) ? 1 : 0;

        printf("%d %d %d %d %d %d  deseada: %d obtenida: %d   ", ejemplos[example_index][0], ejemplos[example_index][1],
               ejemplos[example_index][2], ejemplos[example_index][3], ejemplos[example_index][4], ejemplos[example_index][5],
               deseada[example_index], obtenida);

        printf("W1=%.2f W2=%.2f W3=%.2f W4=%.2f W5=%.2f W6=%.2f\n", peso[0], peso[1], peso[2], peso[3], peso[4], peso[5]);
    }

    return 0;
}

