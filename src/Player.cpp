#include "Player.h"
Player::Player()
    : m_Speed(START_SPEED), m_Health(START_HEALTH), m_MaxHealth(START_HEALTH),
      m_Texture(), m_Sprite() {
  // associate a texture with a sprite
  // IMPORTANT
  m_Texture.openFromFile("graphics/player.png");
  m_Sprite.setTexture(m_Texture);
  // set the origin of the sprite to the center
  // for smooth rotation
  m_Sprite.setOrigin({25, 25});
}

void Player::spawn(IntRect arena, Vector2f resolution, int tileSize) {
  // place the player in the middle of the arena
  m_Position.x = arena.size.x / 2 m_Position.y = arena.size.y / 2;
  // copy details of the arena to player's arena
  m_Arena.position.x = arena.position.x;
  m_Arena.position.y = arena.position.y;
  m_Arena.size.x = arena.size.x;
  m_Arena.size.y = arena.size.y;
  // remember how big the arena is in tiles
  m_TileSize = tileSize;
  // store resolution for future use
  m_Resolution.x = resolution.x;
  m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats() {
  m_Speed = START_SPEED;
  m_Health = START_HEALTH;
  m_MaxHealth = START_HEALTH;
}

Time Player::getHitLastTime() { return m_LastHit; }

bool Player::hit(Time timeHit) {
  if (timeHit.asMilliSeconds() - m_LastHit.asMilliSeconds() > 200) {
    m_LastHit = timeHit;
    m_Health -= 10;
    return true;
  } else {
    return false;
  }
}

FloatRect Player::getPosition() { return m_Sprite.getGlobalBounds(); }
Vector2f Player::getCenter() { return m_Position; }
Float Player::getRotation() { return m_Sprite.getRotation(); }
Sprite Player::getSprite() { return m_Sprite; }
int Player::getHealth() { return m_Health }

// Player movement funcs
void Player::moveLeft() { m_LeftPressed = true; }
void Player::moveRight() { m_RightPressed = true; }
void Player::moveUp() { m_UpPressed = true; }
void Player::moveDown() { m_DownPressed = true; }
void Player::stopLeft() { m_LeftPressed = false; }
void Player::stopRight() { m_RightPressed = false; }
void Player::stopUp() { m_UpPressed = false; }
void Player::stopDown() { m_DownPressed = false; }

void Player::update(float elapsedTime, Vector2i mousePosition) {
  if (m_UpPressed) {
    m_Position.y -= m_Speed * elapsedTime;
  }
  if (m_DownPressed) {
    m_Position.y += m_Speed * elapsedTime;
  }
  if (m_RightPressed) {
    m_Position.x += m_Speed * elapsedTime;
  }
  if (m_LeftPressed) {
    m_Position.x -= m_Speed * elapsedTime;
  }
  m_Sprite.setPosition(m_Position);
  // keep player in arena
  if (m_Position.x > m_Arena.size.x - m_TileSize) {
    m_Position.x = m_Arena.size.x - m_TileSize;
  }
  if (m_Position.x < m_Arena.position.x + m_TileSize) {
    m_Position.x = m_Arena.position.x + m_TileSize;
  }
  if (m_Position.y > m_Arena.size.y - m_TileSize) {
    m_Position.y = m_Arena.size.y - m_TileSize;
  }
  if (m_Position.y < m_Arena.position.y + m_TileSize) {
    m_Position.y = m_Arena.position.y + m_TileSize;
  }
  // calculate angle player is facing
  float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
                       mousePosition.x - m_Resolution.x / 2) *
                 180) /
                3.141;
  m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed() { m_Speed += (START_SPEED * .2); }
void Player::upgradeHealth() { m_Health += (START_HEALTH * .2); }
void Player::increaseHealthLevel(int amount) {
  m_Health += amount;
  // but not beyond the max
  if (m_Health > m_MaxHealth) {
    m_Health = m_MaxHealth;
  }
}
