#pragma once
#include <SFML/Grahpics.hpp>
using namespace sf;

class Player {
private:
  const float START_SPEED = 200;
  const float START_HEALTH = 100;
  // Player location
  Vector2f m_Position;
  // The Sprite
  Sprite m_Sprite;
  // And a Texture
  Texture m_Texture;
  // what is the screen resolution
  Vector2f m_Resolution;
  // What size is the current arena
  IntRect m_Arena;
  // How big is each tile of the arena
  int m_TileSize;
  // which direction the player is moving
  bool m_UpPressed;
  bool m_DownPressed;
  bool m_LeftPressed;
  bool m_RightPressed;
  // how much health does the player have
  int m_Health;
  // what is the max health the player can have
  int m_MaxHealth;
  // when was the player last hit
  Time m_LastHit;
  // Speed in pixels per second
  float m_Speed;
  // public functions next
public:
  Player();
  void spawn(IntRect arena, Vector2f resolution, int tileSize);
  // call this at very end of game
  void resetPlayerStats();
  // handle player getting hit by zombie
  bool hit(Time timeHit);
  // how long ago was the player last hit
  bool getHitLastTime();
  // where is player
  FloatRect getPosition();
  // where is player's center
  Vector2f getCenter();
  // what angle is the player facing
  float getRotation();
  // send a copy of sprite to main func
  Sprite getSprite();
  // move the player
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
  // stop the player
  void stopLeft();
  void stopRight();
  void stopUp();
  void stopDown();
  // call once per frame,
  void update(float elapsedTime, Vector2i mousePosition);
  // speed power-up
  void upgradeSpeed();
  // health power-up
  void upgradeHealth();
  // max health increase boost
  void increaseHealthLevel(int amount);
  // get player health
  int getHealth();
};
