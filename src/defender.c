// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PRIVATE FUNCTIONS                             */
/*----------------------------------------------------------------------------*/

direction_t choose_pos_dfd(direction_t directions[])
{
  srand((unsigned) time(NULL));

  int pos = rand() % 8;

  return directions[pos];
}


/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  
  UNUSED(attacker_spy);

  direction_t  directions_dfd[8] = 
  {
    (direction_t) DIR_UP,
    (direction_t) DIR_UP_RIGHT,
    (direction_t) DIR_RIGHT,
    (direction_t) DIR_DOWN_RIGHT,
    (direction_t) DIR_DOWN,
    (direction_t) DIR_DOWN_LEFT,
    (direction_t) DIR_UP_LEFT,
    (direction_t) DIR_STAY
  };

  static position_t last_position = INVALID_POSITION;

  if(equal_positions(last_position, defender_position) == false)
  {
    return (direction_t) DIR_LEFT;
  }
  else
  {
    return choose_pos_dfd(directions_dfd);
  }

  last_position = defender_position;

}

/*----------------------------------------------------------------------------*/
