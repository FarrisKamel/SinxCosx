#include <stdio.h>
#include <math.h>
#include <unistd.h>

char background_char = ' ';
int width = 100;
int height = 60;
char background_dimenstions[60][100];
int distance_from_left = 60;
float A = 1/(float)5;
float B = 1/(float)2;

// Function for calulating Cosx
float calculateCosx(float x, float C){
    return A * cos(B*x+C) + 10;
}

float negCalculateCosx(float x, float C){
    return -(A * cos(B*x+C)) + 10;
}

// Function for calculating Sinx
float calculateSinx(float x, float C){ 
    return A * sin(B*x+C) + 10;
}

float negCalculateSinx(float x, float C){
    return -(A * sin(B*x+C)) + 10;
}

// Function to produce the patterns needed for helix
void calculateHelix(float xp, float C, char symbol_cos, char symbol_sin){
    
    xp = (int) 10 * xp;                                // find x_position
    float yp_sinx = (10 * calculateCosx(xp, C));         // find y_position
    float yp_cosx = (10 * calculateSinx(xp, C));         // find y_position
    float yp_sinx_negative = (10 * negCalculateCosx(xp, C));         // find y_position
    float yp_cosx_negative = (10 * negCalculateSinx(xp, C));         // find y_position
    
    int xp_int = (int)xp;
    int yp_sinx_int = (int)yp_sinx - 50;
    int yp_cosx_int = (int)yp_cosx - 50;
    int yp_sinx_negative_int = (int)yp_sinx_negative - 50;
    int yp_cosx_negative_int = (int)yp_cosx_negative - 50;

    // First Graphs (Helix looking kinda)
    background_dimenstions[xp_int][yp_cosx_int] = symbol_cos;
    background_dimenstions[xp_int][yp_sinx_int] = symbol_sin;
    background_dimenstions[xp_int][yp_sinx_negative_int] = '.';
    background_dimenstions[xp_int][yp_cosx_negative_int] = '~';

    // Second Graphs
    background_dimenstions[xp_int][yp_cosx_int-15] = symbol_cos;
    background_dimenstions[xp_int][yp_sinx_int-15] = symbol_sin;
    
    // Third Graphs
    background_dimenstions[xp_int][yp_cosx_int+15] = symbol_cos;
    background_dimenstions[xp_int][yp_sinx_int+15] = symbol_sin;
    
    // Fourth Graphs
    background_dimenstions[xp_int][yp_cosx_int-30] = symbol_cos;
    background_dimenstions[xp_int][yp_sinx_int-30] = symbol_sin;
    
    // Fifth Graphs
    background_dimenstions[xp_int][yp_cosx_int+30] = symbol_cos;
    background_dimenstions[xp_int][yp_sinx_int+30] = symbol_sin;
}

int main (void){

    float C = 0;
    float two_pi = 2*3.14;
    printf("\x1b[2J");   
    while (1){

        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                background_dimenstions[y][x] = background_char;
            }
        }
        
        // Create shape 
        for (float i = 0; i < two_pi; i = i + 0.1){
            calculateHelix(i, C, '$', '@');
        }
        
        // Used to get an idea of where the beginning and end are
        background_dimenstions[0][10] = '$';
        background_dimenstions[59][99] = '$';

        printf("\x1b[2J\x1b[H");

        // Print new screen
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){
                putchar(background_dimenstions[y][x]);
            }
            printf("\n");
        }
        C += 0.01;
        usleep(8000*2);
    }
    return 0;
}
