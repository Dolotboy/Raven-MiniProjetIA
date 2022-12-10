#include "Player.h"

Player::Player(Raven_Game* _world, Vector2D pos):Raven_Bot(_world, pos)
{
	m_bPossessed = true;
}