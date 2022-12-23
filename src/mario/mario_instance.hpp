// Super Mario 64 in SuperTux by Headshotnoby

#ifndef HEADER_SUPERTUX_MARIO_INSTANCE_HPP
#define HEADER_SUPERTUX_MARIO_INSTANCE_HPP

#define MAX_SURFACES 256
#define MARIO_SCALE 1

#include <stdint.h>

extern "C" {
#include <libsm64.h>
}

#include "math/vector.hpp"
#include "object/tilemap.hpp"

class MarioInstance
{
  int mario_id;
  float tick;
  uint32_t loaded_surfaces[MAX_SURFACES];

  /** for mesh interpolation */
  Vector m_pos, m_last_pos, m_curr_pos;
  float m_last_geometry_pos[SM64_GEO_MAX_TRIANGLES * 9], m_curr_geometry_pos[SM64_GEO_MAX_TRIANGLES * 9];

  /** sm64 surface objects */
  void delete_blocks();
  bool add_block(int x, int y, int *i, TileMap* solids);
  void load_new_blocks(int x, int y);

public:
  MarioInstance();
  ~MarioInstance();

  void spawn(float x, float y);
  void destroy();
  void update(float tickspeed);

  bool spawned() const { return mario_id != -1; }
  int ID() const { return mario_id; }
  Vector get_pos() const { return m_pos; }

  SM64MarioState state;
  SM64MarioInputs input;
  SM64MarioGeometryBuffers geometry;
};

#endif
