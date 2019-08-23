/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matriz.c
 * Author: meira
 * 
 * Created on August 31, 2018, 3:11 PM
 */

#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz* criaMatriz(int li, int co) {
    Matriz * ma = (Matriz *) malloc(sizeof (Matriz));
    ma->m = (int **) malloc(sizeof (int *)*li);
    for (int linha = 0; linha < li; linha++) {
        ma->m[linha] = (int *) malloc(sizeof (int)*co);
    }
    ma->co = co;
    ma->li = li;
    
    for (int linha = 0; linha < ma->li; linha++) {
        for (int col = 0; col < ma->co; col++) {
            ma->m[linha][col]=0;
        }        
    }
    
    return ma;
}

void freeMatriz(Matriz *ma) {
    for (int linha = 0; linha < ma->li; linha++) {
        free(ma->m[linha]);
    }
    free(ma->m);
    free(ma);
}

void imprime(Matriz * ma) {
    for (int linha = 0; linha < ma->li; linha++) {
        for (int col = 0; col < ma->co; col++) {
            printf("%d ", ma->m[linha][col]);
        }
        printf("\n");
    }
}

Matriz * soma(Matriz *a, Matriz *b) {
    if ((a->co != b->co) || (a->li != b->li)) {
        printf("Incompativeis");
        exit(EXIT_FAILURE);
    }
    Matriz * c = criaMatriz(a->li, a->co);
    for (int linha = 0; linha < a->li; linha++) {
        for (int col = 0; col < a->co; col++) {
            c->m[linha][col] = a->m[linha][col] +
                    b->m[linha][col];
        }
    }
    return c;
}

Matriz * identidade(int n) {
    Matriz * ma = criaMatriz(n, n);
    for (int linha = 0; linha < n; linha++) {
        for (int col = 0; col < n; col++) {
            if(linha==col){
                ma->m[linha][col]=1;
            }else{
                ma->m[linha][col]=0;
            }
        }
    }
    return ma;
}

void persiste(Matriz *ma, char * fname){
    FILE *fp = fopen(fname,"w");
    fprintf(fp,"%d %d\n",ma->li,ma->co);
    for (int linha = 0; linha < ma->li; linha++) {
        for (int col = 0; col < ma->co; col++) {
            fprintf(fp,"%d ", ma->m[linha][col]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    
}

Matriz * carrega(char *fname){
    FILE *fp = fopen(fname,"r");
    int li,col;
    Matriz * ma;
    fscanf(fp,"%d %d\n",&li,&col);
    ma = criaMatriz(li,col);
     for (int linha = 0; linha < ma->li; linha++) {
        for (int col = 0; col < ma->co; col++) {
            fscanf(fp,"%d ", &ma->m[linha][col]);
        }        
    }
    return ma;
}
