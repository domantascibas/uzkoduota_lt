#ifndef SAFE_PUZZLE_H
#define SAFE_PUZZLE_H

#include "puzzle.h"

struct SafePuzzle : public Puzzle {
  SafePuzzle() : Puzzle() {
    cooldown = 120;
  }

  virtual void activate();
  virtual void solve();
};

#endif
