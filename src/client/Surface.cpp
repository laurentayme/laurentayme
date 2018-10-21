/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>

using namespace render;

Surface::Surface(){
    quads[0].position=sf ::Vector2f(0,0);
    quads[1].position=sf ::Vector2f(149,0);
    quads[2].position=sf ::Vector2f(149,149);
    quads[3].position=sf ::Vector2f(0,149);
    
}
