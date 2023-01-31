// Super Mario 64 in SuperTux by Headshotnoby

#ifndef HEADER_SUPERTUX_MARIO_MANAGER_HPP
#define HEADER_SUPERTUX_MARIO_MANAGER_HPP

#include <stdint.h>

extern "C" {
#include <libsm64.h>
}

#include "mario/mario_instance.hpp"
#include "util/currenton.hpp"

class MarioManager final : public Currenton<MarioManager>
{
public:
  MarioManager();

  std::string error_message;
  bool Loaded() const { return loaded; }

  uint16_t mario_indices[SM64_GEO_MAX_TRIANGLES * 3];
  uint32_t mario_texture_handle;
  uint32_t health_texture_handle;
  uint32_t ui_texture_handle;

private:
  bool loaded;
  uint8_t *mario_texture;
  uint8_t *health_texture;
  uint8_t *ui_texture;

private:
  MarioManager(const MarioManager&) = delete;
  MarioManager& operator=(const MarioManager&) = delete;
};

#endif
