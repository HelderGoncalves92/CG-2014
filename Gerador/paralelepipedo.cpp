//
//  paralelepipedo.cpp
//  CG-FORMAS-PRIMARIAS
//
//  Created by Hélder José Alves Gonçalves on 10/03/14.
//  Copyright (c) 2014 Hélder José Alves Gonçalves. All rights reserved.
//

#include "paralelepipedo.h"


void paralelepipedo(float altura, float lado_x, float lado_z, int camadas, int fatias, int fatias_z, FILE* f){
    
	int flag=0;

	fprintf(f,"%d\n",2*(2*camadas*fatias + 2*fatias_z*camadas + 2*fatias*fatias_z)*9);

    plano(altura, lado_x, camadas, fatias, lado_z/2, 1,f, flag);
    plano(altura, lado_x, camadas, fatias, -lado_z/2, 2,f, flag);
    
    plano(altura, lado_z, camadas, fatias_z, lado_x/2, 3,f, flag);
    plano(altura, lado_z, camadas, fatias_z, -lado_x/2, 4,f, flag);
    
    plano(lado_x, lado_z, fatias, fatias_z, altura/2, 5,f, flag);
    plano(lado_x, lado_z, fatias, fatias_z, -altura/2, 6,f, flag);
}

void paralelepipedoVBO(float lado_y, float lado_x, float lado_z, int camadas, int fatias_x, int fatias_z, FILE *f){
    int     k=0,j=0,v=0, i=0, avanco=0;
    float   change_x=lado_x/fatias_x,
            change_z=lado_z/fatias_z,
            change_y=lado_y/camadas,
            begin_y=-lado_y/2,
            begin_x=-lado_x/2,
            begin_z=-lado_z/2,
            altura_aux,lado_aux;
    
    int n_pontos=(2*(fatias_x+1)*(camadas+1) + 2*(fatias_z+1)*(camadas+1) + 2*(fatias_x+1)*(fatias_z+1))*3;
    int n_indices=(2*fatias_x*camadas + 2*fatias_z*camadas + 2* fatias_x*fatias_z)*3*2;
    
    float *vertexB=(float*)malloc(n_pontos*sizeof(float));
    int *indices=(int*)malloc(n_indices*sizeof(int));
    
    //1
    for(altura_aux=begin_y;j<=camadas;j++){
        k=0;

        for(lado_aux=begin_x;k<=fatias_x;k++){
            //Inserir Ponto
            vertexB[v++]=lado_aux;vertexB[v++]=altura_aux;vertexB[v++]=fabs(begin_z);
            if(k!=fatias_x && j!=camadas){
                indices[i++]=avanco+k;
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_x+1+k;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_x+1+k+1;
                indices[i++]=avanco+fatias_x+1+k;
            }
            lado_aux+=change_x;
        }
        avanco+=fatias_x+1;
        altura_aux+=change_y;
    }
    
    //2
    j=0;
    for(altura_aux=begin_y;j<=camadas;j++){
        k=0;
        for(lado_aux=begin_x;k<=fatias_x;k++){
            //Inserir Ponto
            vertexB[v++]=lado_aux;vertexB[v++]=altura_aux;vertexB[v++]=begin_z;
            if(k!=fatias_x && j!=camadas){
                indices[i++]=avanco+k;
                indices[i++]=avanco+fatias_x+1+k;
                indices[i++]=avanco+k+1;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_x+1+k;
                indices[i++]=avanco+fatias_x+1+k+1;
            }
            lado_aux+=change_x;
        }
        avanco+=fatias_x+1;
        altura_aux+=change_y;
    }
    
    //3
    j=0;
    for(altura_aux=begin_y;j<=camadas;j++){
        k=0;
        for(lado_aux=begin_z;k<=fatias_z;k++){
            //Inserir Ponto
            vertexB[v++]=fabs(begin_x);vertexB[v++]=altura_aux;vertexB[v++]=lado_aux;
            if(k!=fatias_z && j!=camadas){
                indices[i++]=avanco+k;
                indices[i++]=avanco+fatias_z+1+k;
                indices[i++]=avanco+k+1;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                indices[i++]=avanco+fatias_z+1+k+1;
            }
            lado_aux+=change_z;
        }
        avanco+=fatias_z+1;
        altura_aux+=change_y;
    }
    
    //4
    j=0;
    for(altura_aux=begin_y;j<=camadas;j++){
        k=0;
        for(lado_aux=begin_z;k<=fatias_z;k++){
            //Inserir Ponto
            vertexB[v++]=begin_x;vertexB[v++]=altura_aux;vertexB[v++]=lado_aux;
            if(k!=fatias_z && j!=camadas){
                indices[i++]=avanco+k;
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                
            }
            lado_aux+=change_z;
        }
        avanco+=fatias_z+1;
        altura_aux+=change_y;
    }
    
    //5
    j=0;
    for(altura_aux=begin_x;j<=fatias_x;j++){
        k=0;
        for(lado_aux=begin_z;k<=fatias_z;k++){
            //Inserir Ponto
            vertexB[v++]=altura_aux;vertexB[v++]=fabsf(begin_y);vertexB[v++]=lado_aux;
            if(k!=fatias_z && j!=fatias_x){
                indices[i++]=avanco+k;
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                
            }
            lado_aux+=change_z;
        }
        avanco+=fatias_z+1;
        altura_aux+=change_x;
    }
    
    //6
    j=0;
    for(altura_aux=begin_x;j<=fatias_x;j++){
        k=0;
        for(lado_aux=begin_z;k<=fatias_z;k++){
            //Inserir Ponto
            vertexB[v++]=altura_aux;vertexB[v++]=begin_y;vertexB[v++]=lado_aux;
            if(k!=fatias_z && j!=fatias_x){
                indices[i++]=avanco+k;
                indices[i++]=avanco+fatias_z+1+k;
                indices[i++]=avanco+k+1;
                
                indices[i++]=avanco+k+1;
                indices[i++]=avanco+fatias_z+1+k;
                indices[i++]=avanco+fatias_z+1+k+1;
            }
            lado_aux+=change_z;
        }
        avanco+=fatias_z+1;
        altura_aux+=change_x;
    }

    //Imprimir os vertices e indices
    fprintf(f, "%d\n",n_pontos);
    for(i=0;i<n_pontos;i+=3)
        fprintf(f, "%f %f %f\n",vertexB[i],vertexB[i+1],vertexB[i+2]);

    fprintf(f, "%d\n",n_indices);
    for(i=0;i<n_indices;i+=3)
        fprintf(f, "%d %d %d\n",indices[i],indices[i+1],indices[i+2]); 

}


