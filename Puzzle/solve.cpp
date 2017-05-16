
#include "move.h"
#include "fifteen.h"
#include <unordered_map>
#include <queue>

// Table of states and their levels:

using leveltable = std::unordered_map<fifteen, unsigned int, fifteen_hash, fifteen_equals>;

leveltable solve(const fifteen& start)
{
    leveltable levels;

    std::priority_queue<fifteen, std::vector<fifteen>, fifteen_further> unchecked;

    unchecked.push(start);
    levels[start] = 0;

    // We have start unexplored, at its level is zero.

    std::vector<move> moves = { move::up, move::down, move::left, move::right };
    // All possible moves in a vector.

    // As long as there is a state whose neighbours are unexplored,
    // we explore them:

    while (unchecked.size())
    {
        fifteen best = unchecked.top();
        unsigned int level = levels[best];
        // The best state is the state that is closest to the
        // solution. level is the number of moves that was required
        // to reach it.

        std::cout << "best = \n" << best;
        std::cout << "distance = " << best.distance() << "\n";

        if (best.issolved())
            return levels;

        unchecked.pop();

        for (auto m : moves)
        {
            fifteen next = best;
            try
            {
                next.makemove(m);
                auto p = levels.find(next);
                if (p == levels.end() || level + 1 < p->second)
                {
                    // We did not reach next before, or we reached it
                    // in more steps.

                    levels[next] = level + 1;
                    unchecked.push(next);
                }
            }
            catch (illegalmove& m)
            { /* catch and do nothing */
            }
        }
    }
    return levels; // In move we trust.
}

std::list<move>
findpath(const leveltable& levels, fifteen puzzle, unsigned int level)
{
    std::vector<move> moves = { move::up, move::down, move::left, move::right };
      // All possible moves in a vector.
    std::list<move> path;

    while(level)
    {
          for(auto i : moves)
          {
              try
              {
                  fifteen temp = puzzle;
                  temp.makemove(i);
                  auto lv = levels.at(temp);
                  std::cout << lv << "\texpected: " << level << "\n";
                  if(lv + 1 == level)
                  {
                      level--;
                      puzzle = temp;
                      std::cout << "negative move : " << i << "\texpected move : " << (-i) << std::endl;
                      path.push_front(-i);
                      break;
                  }
              }
              catch(illegalmove& e){}
              catch(std::out_of_range& e){}
          }
      }
      return path;
  }

int
main()
{
  leveltable test;

  fifteen puzzle{
    { 1, 3, 4, 12 },
    { 5, 2, 7, 11 },
    { 9, 6, 14, 10 },
    { 13, 15, 0, 8 }
  };

  auto dist = solve(puzzle);
  /*for (const auto& p : dist)
   {
    std::cout << "---------------------------\n";
    std::cout << p.first << " " << p.second << "\n";
    }*/

  /*auto path = findpath(dist, fifteen(), dist[fifteen()]);
  for (move m : path)
    std::cout << m << "\n";*/

  return 0;
}
