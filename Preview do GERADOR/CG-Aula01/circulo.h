//
//  circulo.h
//  CG-FORMAS-PRIMARIAS
//
//  Created by Hélder José Alves Gonçalves on 27/02/14.
//  Copyright (c) 2014 Hélder José Alves Gonçalves. All rights reserved.
//

#ifndef CG_FORMAS_PRIMARIAS_circulo_h
#define CG_FORMAS_PRIMARIAS_circulo_h

#include <GL/glew.h>
#include <GLUT/glut.h>
#include <iostream>
#include <math.h>



void circulo(float raio, int lados, int sep, float alt,int ori);
void anel(float raio_fora, float raio_dentro, int fatias, int aneis, int ori);

void circuloVBO(float raio, int lados,int sep, float alt,int ori);
void drawCirculo();

#endif
