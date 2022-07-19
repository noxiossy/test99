﻿#include "stdafx.h"
#include "reward_event_generator.h"
#include "game_state_accumulator.h"
#include "game_base.h"
#include "game_cl_mp.h"

#include "rewarding_state_events.h"
#include "rewarding_events_handlers.h"
#include "best_scores_helper.h"

#include "MainMenu.h"
#include "login_manager.h"
#include "stats_submitter.h"
#include "atlas_submit_queue.h"

namespace award_system
{

reward_event_generator::reward_event_generator(u32 const max_rewards_per_game) :
	m_max_rewards(max_rewards_per_game)
{
	m_local_player				= NULL;
	m_rewarded					= 0;
	m_state_accum				= xr_new<game_state_accumulator>();
	event_action_delegate_t		tmp_delegate(this, &reward_event_generator::AddRewardTask);
	m_state_event_checker		= xr_new<rewarding_state_events>(m_state_accum, tmp_delegate);
	
	m_event_handlers			= xr_new<rewarding_event_handlers>(m_state_accum, tmp_delegate);
	m_best_scores_helper		= xr_new<best_scores_helper>(m_state_accum);
	m_event_handlers->set_null_handler(m_best_scores_helper);

	m_state_event_checker->init	();
	m_state_accum->init			();
	m_event_handlers->init		();
}

reward_event_generator::~reward_event_generator()
{
	xr_delete		(m_state_accum);
	xr_delete		(m_state_event_checker);
	xr_delete		(m_event_handlers);
	xr_delete		(m_best_scores_helper);
}

void reward_event_generator::init_player(game_PlayerState* local_player)
{
	m_local_player					= local_player;
	m_state_accum->init_player		(local_player);
}

void reward_event_generator::init_bone_groups(CActor* first_spawned_actor)
{
	m_state_accum->init_bone_groups(first_spawned_actor);
}

void reward_event_generator::update()
{
	m_state_accum->update	();
}

void reward_event_generator::OnWeapon_Fire(u16 sender, u16 sender_weapon_id)
{
	m_state_accum->OnWeapon_Fire	(sender, sender_weapon_id);
	m_event_handlers->OnWeapon_Fire	(sender, sender_weapon_id);
}

void reward_event_generator::OnBullet_Fire(u16 sender, u16 sender_weapon_id, const Fvector& position, const Fvector& direction)
{
	m_state_accum->OnBullet_Fire	(sender, sender_weapon_id, position, direction);
	m_event_handlers->OnBullet_Fire	(sender, sender_weapon_id, position, direction);
}

void reward_event_generator::OnBullet_Hit(CObject const * hitter, CObject const * victim, CObject* weapon, u16 const bone)
{
	m_state_accum->OnBullet_Hit				(hitter, victim, weapon, bone);
	m_event_handlers->OnBullet_Hit			(hitter, victim, weapon, bone);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnArtefactSpawned()
{
	m_state_accum->OnArtefactSpawned();
	m_event_handlers->OnArtefactSpawned();
	m_state_event_checker->check_for_events();
}

void reward_event_generator::OnPlayerTakeArtefact(game_PlayerState const * ps)
{
	m_state_accum->OnPlayerTakeArtefact		(ps);
	m_event_handlers->OnPlayerTakeArtefact	(ps);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnPlayerDropArtefact(game_PlayerState const * ps)
{
	m_state_accum->OnPlayerDropArtefact		(ps);
	m_event_handlers->OnPlayerDropArtefact	(ps);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnPlayerBringArtefact(game_PlayerState const * ps)
{
	m_state_accum->OnPlayerBringArtefact	(ps);
	m_event_handlers->OnPlayerBringArtefact	(ps);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnPlayerSpawned(game_PlayerState const * ps)
{
	m_event_handlers->OnPlayerSpawned		(ps);
	m_state_accum->OnPlayerSpawned			(ps);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnPlayerKilled	(u16 killer_id, u16 target_id, u16 weapon_id, std::pair<KILL_TYPE, SPECIAL_KILL_TYPE> kill_type)
{
	m_event_handlers->OnPlayerKilled		(killer_id, target_id, weapon_id, kill_type);
	m_state_accum->OnPlayerKilled			(killer_id, target_id, weapon_id, kill_type);
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnPlayerChangeTeam(s8 team)
{
	m_event_handlers->OnPlayerChangeTeam	(team);
	m_state_accum->OnPlayerChangeTeam		(team);
	m_state_event_checker->check_for_events	();
}
void reward_event_generator::OnPlayerRankdChanged()
{
	m_event_handlers->OnPlayerRankChanged	();
	m_state_accum->OnPlayerRankChanged		();
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnRoundEnd()
{
	m_event_handlers->OnRoundEnd			();
	m_state_accum->OnRoundEnd				();
	m_state_event_checker->check_for_events	();
}

void reward_event_generator::OnRoundStart()
{
	m_rewarded								= 0;
	m_state_event_checker->clear_events		();
	m_state_event_checker->init				();
	m_state_accum->reset_player_game		();
	m_event_handlers->OnRoundStart			();
	m_state_accum->OnRoundStart				();
}

void __stdcall reward_event_generator::AddRewardTask(u32 award_id)
{
}

void reward_event_generator::CommitBestResults()
{
}

} //namespace award_system
