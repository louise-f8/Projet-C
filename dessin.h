#ifndef PROJET_1_DESSIN_H
#define PROJET_1_DESSIN_H

#include <SDL.h>

void fill_circle(SDL_Renderer *renderer, int cx, int cy, int r);
void fill_sector(SDL_Renderer *renderer, int cx, int cy, int r_inner, int r_outer, double start_angle, double end_angle);
void dessiner_plateau(SDL_Renderer *renderer, int width, int height);

#endif //PROJET_1_DESSIN_H
