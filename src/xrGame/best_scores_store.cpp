﻿#include "stdafx.h"
#include "best_scores_store.h"

namespace gamespy_profile
{


best_scores_store::best_scores_store(CGameSpy_Full* fullgs_obj)
{
	init_field_names	();
}

best_scores_store::~best_scores_store()
{
	//VERIFY(!m_scores_operation_cb);
}

void best_scores_store::init_field_names()
{
	for (int i = 0; i < bst_score_types_count; ++i)
	{
		m_field_names_store[i]	= ATLAS_GET_STAT_NAME(
			get_best_score_id_stat(static_cast<enum_best_score_type>(i))
		);
	}
}

void best_scores_store::reset_scores()
{
	m_result_scores.clear		();
	m_ltx_result_scores.clear	();

	for (int bsidx = 0; bsidx < bst_score_types_count; ++bsidx)
	{
		m_result_scores.insert(
			std::make_pair(
				enum_best_score_type(bsidx),
				0
			)
		);
	};
}

void best_scores_store::load_best_scores(store_operation_cb & opcb)
{
	m_scores_operation_cb		= opcb;
}

void best_scores_store::load_best_scores_from_ltx(CInifile& ini)
{
	for (int i = 0; i != bst_score_types_count; ++i)
	{
		enum_best_score_type bstype = static_cast<enum_best_score_type>(i);
		m_ltx_result_scores.insert(
			std::make_pair(
				bstype,
				ini.r_u32(get_best_score_name(bstype), best_score_value_line)
			)
		);
	}
}

void best_scores_store::merge_sake_to_ltx_best_scores()
{
	for (all_best_scores_t::iterator i = m_ltx_result_scores.begin(),
		ie = m_ltx_result_scores.end(); i != ie; ++i)
	{
		all_best_scores_t::const_iterator tmp_bi = m_result_scores.find(
			i->first);
		if (tmp_bi != m_result_scores.end())
		{
			u32 tmp_value	= std::max(i->second, tmp_bi->second);
			i->second		= tmp_value;
		}
	}
}

all_best_scores_t& best_scores_store::get_player_best_scores()
{
	if (m_ltx_result_scores.empty())
		return m_result_scores;

	return m_ltx_result_scores;
}

bool best_scores_store::is_sake_equal_to_file() const
{
	VERIFY(!m_ltx_result_scores.empty());
	if (m_ltx_result_scores.empty())
		return true;

	for (all_best_scores_t::const_iterator i = m_ltx_result_scores.begin(),
		ie = m_ltx_result_scores.end(); i != ie; ++i)
	{
		all_best_scores_t::const_iterator tmp_iter = m_result_scores.find(i->first);
		R_ASSERT(tmp_iter != m_result_scores.end());

		if (i->second != tmp_iter->second)
			return false;
	}
	return true;
}
} //namespace gamespy_profile
