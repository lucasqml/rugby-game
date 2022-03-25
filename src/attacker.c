// Standard headers
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PRIVATE FUNCTIONS                             */
/*----------------------------------------------------------------------------*/

direction_t choose_pos_atk(direction_t directions[])
{
  srand((unsigned) time(NULL));

  int pos = rand() % 7;

  return directions[pos];
}


/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) 
{
  // TODO: unused parameters, remove these lines later
  UNUSED(defender_spy);

  direction_t  directions_atk[7] = 
  {
    (direction_t) DIR_UP,
    (direction_t) DIR_UP_RIGHT,
    (direction_t) DIR_DOWN_RIGHT,
    (direction_t) DIR_DOWN,
    (direction_t) DIR_DOWN_LEFT,
    (direction_t) DIR_LEFT,
    (direction_t) DIR_UP_LEFT,
  };

  static position_t last_position = INVALID_POSITION;

  if(equal_positions(last_position, attacker_position) == false)
  {
    return (direction_t) DIR_RIGHT;
  }
  else
  {
    return choose_pos_atk(directions_atk);
  }

  last_position = attacker_position;
}
