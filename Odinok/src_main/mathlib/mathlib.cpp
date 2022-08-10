#include "mathlib.h"

// radians version
float rlengthdir_x(float length, float angle)
{
  return cos(angle) * length;
}

// radians version
float rlengthdir_y(float length, float angle)
{
  return sin(angle) * length;
}

// degrees version
float dlengthdir_x(float length, float angle)
{
  return cos(DEG2RAD(angle)) * length;
}

// degrees version
float dlengthdir_y(float length, float angle)
{
  return sin(DEG2RAD(angle)) * length;
}