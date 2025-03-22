#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
int n=0, Nx, Ny;
double Up, Down, Left, Right, k;
double **U_temp,**U;
void allocateMem() { //Cap phat bo nho
    U_temp = (double**)malloc(sizeof(double*)*Nx);
    U = (double**)malloc(sizeof(double*)*Nx);
    for (int x=0; x<Nx; x++) {
        U_temp[x] = (double*)malloc(sizeof(double)*Ny);
        U[x] = (double*)malloc(sizeof(double)*Ny);
    }
}
void freeMem() { //Giai phong bo nho
    for (int y=0; y<Nx; y++) {
        free(U_temp[y]);
        free(U[y]);
    }
    free(U_temp);
    free(U);
}
void input() { //Du lieu dau vao
    printf("Nhap sai so:\n");
    scanf("%lf",&k);
    printf("Nhap so dong:\n");
    scanf("%d",&Nx);
    printf("Nhap so cot:\n");
    scanf("%d",&Ny);
    allocateMem();
    printf("Nhap dieu kien bien tren:\n");
    scanf("%lf",&Up);
    printf("Nhap dieu kien bien duoi:\n");
    scanf("%lf",&Down);
    printf("Nhap dieu kien bien trai:\n");
    scanf("%lf",&Left);
    printf("Nhap dieu kien bien phai:\n");
    scanf("%lf",&Right);
    for (int a=0; a<Ny; a++) {
        U[0][a] = Up;
        U[Nx-1][a] = Down;
    }
    for (int b=1; b<(Nx-1); b++) {
        U[b][0] = Left;
        U[b][Ny-1] = Right;
    }
    for (int a=1; a<(Nx-1); a++) {
        for (int b=1; b<(Ny-1); b++) {
            U[a][b] = 0;
        }
    }
    for (int a=0; a<Nx; a++) {
        for (int b=0; b<Ny; b++) {
            U_temp[a][b] = U[a][b];
        }
    }
}
void output() { //Du lieu dau ra
    printf("Tong so lan lap: %d\n",n);
    printf("Luoi thu duoc:\n");
    for (int z=0; z<Nx; z++) {
        for (int t=0; t<Ny; t++) {
            printf("%10.6lf ",U_temp[z][t]);
        }
        printf("\n");
    }
}
bool converged() { //Dieu kien dung
    for (int i=1; i<(Nx-1); i++) {
        for (int j=1; j<(Ny-1); j++) {
            if (fabs(U_temp[i][j]-U[i][j])>=k) {
                return false;
            }
        }
    }
    return true;
}
void loop() { //Vong lap
    while (true) {
        n++;
        for (int i=1; i<(Nx-1); i++) {
            for (int j=1; j<(Ny-1); j++) {
                U_temp[i][j] = (U[i+1][j]+U[i-1][j]+U[i][j+1]+U[i][j-1])/4;
            }
        }
        if (converged()) {
            break;
        }
        for (int i=1; i<(Nx-1); i++) {
            for (int j=1; j<(Ny-1); j++) {
                U[i][j] = U_temp[i][j];
            }
        }  
    }
}
int main() {
    input();
    loop();
    output();
    freeMem();
    return 0;
}
