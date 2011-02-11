/* Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "h2oh"
 *
 * "h2oh" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "h2oh" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "h2oh" If not, see <http://www.gnu.org/licenses/>.
 */

#include <SDL/SDL.h>
#include <gl/gl.h>
#include "config.hpp"
#include "menu.hpp"
#include "game.hpp"

extern config_type config;
extern game_type   game;
extern menu_type   menu;
//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
   game_init();
   menu_init();
   //----------------------------------- Main loop --------------------------------
   while (!game.status_quit_active)
   {
      if (game.status_menu_active)
      {
         menu_display();
         menu_process();
      }
      if (game.status_game_active)
      {
         game_display();
         menu_process();
      }
   }
  //----------------------------------- Exit -------------------------------------
  game_deinit();
  return(0);
}
