#pragma once
#include "Raven_Bot.h"
#include "Raven_Game.h"


class Player : public Raven_Bot
{

public:
	Player(Raven_Game* _world, Vector2D pos);
};
