//
// Created by lfaiv on 24/10/2025.
//

#include "dessin.h"
#include <math.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Remplit un cercle (ou une tranche)
void fill_circle(SDL_Renderer *renderer, int cx, int cy, int r) {
    for (int dy = -r; dy <= r; dy++) {
        int dx = (int)sqrt(r * r - dy * dy);
        SDL_RenderDrawLine(renderer, cx - dx, cy + dy, cx + dx, cy + dy);
    }
}

// Remplit une tranche circulaire (entre r_inner et r_outer, entre start_angle et end_angle)
void fill_sector(SDL_Renderer *renderer, int cx, int cy, int r_inner, int r_outer, double start_angle, double end_angle) {
    for (double angle = start_angle; angle < end_angle; angle += 0.001) {
        int x1 = cx + (int)(r_inner * cos(angle));
        int y1 = cy + (int)(r_inner * sin(angle));
        int x2 = cx + (int)(r_outer * cos(angle));
        int y2 = cy + (int)(r_outer * sin(angle));
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

void dessiner_plateau(SDL_Renderer *renderer, int width, int height) {
    int cx = width / 2;
    int cy = height / 2;
    int r_outer = 300; // cercle principal
    int r_inner = 250;  // petit cercle plus petit

    // Dessiner les 40 cases blanches
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < 40; i++) {
        double start_angle = (2 * M_PI / 40) * i;
        double end_angle = (2 * M_PI / 40) * (i + 1);
        fill_sector(renderer, cx, cy, r_inner, r_outer, start_angle, end_angle);
    }

    // Tracer les lignes noires fines pour séparer les tranches
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i < 40; i++) {
        double angle = (2 * M_PI / 40) * i;
        int x1 = cx + (int)(r_inner * cos(angle));
        int y1 = cy + (int)(r_inner * sin(angle));
        int x2 = cx + (int)(r_outer * cos(angle));
        int y2 = cy + (int)(r_outer * sin(angle));
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }

    // Petit cercle central (vert)
    SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
    fill_circle(renderer, cx, cy, r_inner);

}
