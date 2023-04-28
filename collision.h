//bool check_collision(SDL_Rect,SDL_Rect);

bool check_collision_wall(SDL_Rect ,SDL_Rect );
bool is_collision()              //Returns true when collision happen ,otherwise returns false..
{
     SDL_Rect rect;
     rect.x=bike_x;
     rect.y=bike_y;
     rect.w=bike->w;
     rect.h=bike->h;

          for(int i=0;i<SMAX_WALL;i++)    //Check collision of PIPE..
               if(w1[i].get_state())     //When enabled PIPE is found only then check the collision and exit the loop...
               {
                    if (check_collision_wall(rect ,w1[i].get_rect()))   //Check collision of the MARIO and PIPE 0...
                    return true;
                    break;
               }
          for(int i=0;i<BMAX_WALL;i++)    //Check collision of PIPE..
               if(w2[i].get_state())     //When enabled PIPE is found only then check the collision and exit the loop...
               {

                    if (check_collision_wall(rect, w2[i].get_rect()))   //Check collision of the MARIO and PIPE 0...
                    {
                         return true;
                         break;
                    }

               }
          return false;
}

bool check_collision_wall(SDL_Rect source,SDL_Rect destination)
{

         if( ((source.x + source.w) < destination.x) or  source.x > ( destination.x + destination.w))
         {
              if((bike_stand-bike->h) == destination.y  - source.h)
              bike_stand = LAYER_Y;
              return false;
         }
         if(( (source.y + source.h) <= destination.y))
         {
              bike_stand = destination.y ;
              return false;
         }
         if(((source.y + source.h) <= (destination.y + 20)) and ((source.y + source.h)>= destination.y - 10) )
          {
               bike_stand = destination.y ;
               bike_y = destination.y - source.h;
               return false;
          }
         apply_surface(100,300,die,screen);
         SDL_Flip(screen);
         SDL_Delay(2000);
         return true;
}
