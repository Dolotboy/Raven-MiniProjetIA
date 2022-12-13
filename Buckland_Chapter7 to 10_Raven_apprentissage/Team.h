#pragma once
#include <vector>
#include <iosfwd>
#include <map>
#include <list>

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "Raven_TargetingSystem.h"

class Raven_Bot;

class Team
{
private:
	std::vector<Vector2D>   m_SpawnPoints;

	std::list<Raven_Bot*>	members;
	Raven_Bot* team_leader;

	Raven_Bot* target;
	std::string				name_team;


	Vector2D				lootingLocation;
	int						m_teamId;
public:
	Team();
	Team(Vector2D lootingLocation, std::string name,int teamId);
	~Team();

	std::string	GetName() { return name_team; }

	void		Addmember(Raven_Bot* new_memeber);
	Raven_Bot*	GetTeamLeader() { return team_leader; }
	void		SetTeamLeader(Raven_Bot* teamLeader) { team_leader = teamLeader; }

	void		AddSpawnPoint(Vector2D spawnPoint);
	const std::vector<Vector2D>& GetSpawnPoints()const { return m_SpawnPoints; }
	Vector2D    GetRandomSpawnPoint() { return m_SpawnPoints[RandInt(0, m_SpawnPoints.size() - 1)]; }
	Vector2D    GetLootingLocation() { return lootingLocation; }

	void		UpdateNewTarget(Raven_Bot* bot, int id_sender);
	void		ProtectLeader(int id_sender);
	Raven_Bot*	GetTarget() { return target; }
	void		ClearTarget(int id_sender);

	int			GetTeamId(){return m_teamId;}

};

