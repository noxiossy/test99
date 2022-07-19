﻿#include "stdafx.h"
#include "actor.h"
#include "weapon.h"
#include "mercuryball.h"
#include "inventory.h"
#include "character_info.h"
#include "xr_level_controller.h"
#include "UsableScriptObject.h"
#include "customzone.h"
#include "../xrEngine/gamemtllib.h"
#include "ui/UIMainIngameWnd.h"
#include "UIGameCustom.h"
#include "Grenade.h"
#include "WeaponRPG7.h"
#include "ExplosiveRocket.h"
#include "game_cl_base.h"
#include "Level.h"
#include "clsid_game.h"
#include "hudmanager.h"

#define PICKUP_INFO_COLOR 0xFFDDDDDD

void CActor::feel_touch_new				(CObject* O)
{
	CPhysicsShellHolder* sh=smart_cast<CPhysicsShellHolder*>(O);
	if(sh&&sh->character_physics_support()) m_feel_touch_characters++;

}

void CActor::feel_touch_delete	(CObject* O)
{
	CPhysicsShellHolder* sh=smart_cast<CPhysicsShellHolder*>(O);
	if(sh&&sh->character_physics_support()) m_feel_touch_characters--;
}

bool CActor::feel_touch_contact		(CObject *O)
{
	CInventoryItem	*item = smart_cast<CInventoryItem*>(O);
	CInventoryOwner	*inventory_owner = smart_cast<CInventoryOwner*>(O);

	if (item && item->Useful() && !item->object().H_Parent()) 
		return true;

	if(inventory_owner && inventory_owner != smart_cast<CInventoryOwner*>(this))
	{
		//CPhysicsShellHolder* sh=smart_cast<CPhysicsShellHolder*>(O);
		//if(sh&&sh->character_physics_support()) m_feel_touch_characters++;
		return true;
	}

	return		(false);
}

bool CActor::feel_touch_on_contact	(CObject *O)
{
	CCustomZone	*custom_zone = smart_cast<CCustomZone*>(O);
	if (!custom_zone)
		return	(true);

	Fsphere		sphere;
	Center		(sphere.P);
	sphere.R	= 0.1f;
	if (custom_zone->inside(sphere))
        return	(true);

	return		(false);
}

ICF static BOOL info_trace_callback(collide::rq_result& result, LPVOID params)
{
	BOOL& bOverlaped	= *(BOOL*)params;
	if(result.O)
	{
		if (Level().CurrentEntity()==result.O)
		{ //ignore self-actor
			return			TRUE;
		}else
		{ //check obstacle flag
			if(result.O->spatial.type&STYPE_OBSTACLE)
				bOverlaped			= TRUE;

			return			TRUE;
		}
	}else
	{
		//получить треугольник и узнать его материал
		CDB::TRI* T		= Level().ObjectSpace.GetStaticTris()+result.element;
		if (GMLib.GetMaterialByIdx(T->material)->Flags.is(SGameMtl::flPassable)) 
			return TRUE;
	}	
	bOverlaped			= TRUE;
	return				FALSE;
}

BOOL CActor::CanPickItem(const CFrustum& frustum, const Fvector& from, CObject* item)
{
	if(!item->getVisible())
		return FALSE;

	BOOL	bOverlaped		= FALSE;
	Fvector dir,to; 
	item->Center			(to);
	float range				= dir.sub(to,from).magnitude();
	if (range>0.25f)
	{
		if (frustum.testSphere_dirty(to,item->Radius()))
		{
			dir.div						(range);
			collide::ray_defs			RD(from, dir, range, CDB::OPT_CULL, collide::rqtBoth);
			VERIFY						(!fis_zero(RD.dir.square_magnitude()));
			RQR.r_clear					();
			Level().ObjectSpace.RayQuery(RQR, RD, info_trace_callback, &bOverlaped, NULL, item);
		}
	}
	return !bOverlaped;
}

void CActor::PickupModeUpdate()
{
	if(!m_bPickupMode)				return; // kUSE key pressed
	if(!IsGameTypeSingle())			return;

	//подбирание объекта
	if(	m_pObjectWeLookingAt									&& 
		m_pObjectWeLookingAt->cast_inventory_item()				&& 
		m_pObjectWeLookingAt->cast_inventory_item()->Useful()	&&
		m_pUsableObject											&& 
		m_pUsableObject->nonscript_usable()						&&
		!Level().m_feel_deny.is_object_denied(m_pObjectWeLookingAt) )
	{
		m_pUsableObject->use(this);
		Game().SendPickUpEvent(ID(), m_pObjectWeLookingAt->ID());
	}

	feel_touch_update	(Position(), m_fPickupInfoRadius);
	
	CFrustum frustum;
	frustum.CreateFromMatrix(Device.mFullTransform, FRUSTUM_P_LRTB|FRUSTUM_P_FAR);

	for(xr_vector<CObject*>::iterator it = feel_touch.begin(); it != feel_touch.end(); it++)
	{
		if (CanPickItem(frustum, Device.vCameraPosition, *it)) 
			PickupInfoDraw(*it);
	}
}

#include "../xrEngine/CameraBase.h"
BOOL	g_b_COD_PickUpMode = TRUE;
void	CActor::PickupModeUpdate_COD	()
{
	if (Level().CurrentViewEntity() != this || !g_b_COD_PickUpMode) return;
		
	if (!g_Alive() || eacFirstEye != cam_active) 
	{
		CurrentGameUI()->UIMainIngameWnd->SetPickUpItem(nullptr);
		return;
	};
	
	CFrustum						frustum;
	frustum.CreateFromMatrix		(Device.mFullTransform, FRUSTUM_P_LRTB|FRUSTUM_P_FAR);

	ISpatialResult.clear_not_free	();
	g_SpatialSpace->q_frustum		(ISpatialResult, 0, STYPE_COLLIDEABLE, frustum);

	float maxlen					= 1000.0f;
	CInventoryItem* pNearestItem	= NULL;

	for (u32 o_it=0; o_it<ISpatialResult.size(); o_it++)
	{
		ISpatial*		spatial	= ISpatialResult[o_it];
		CInventoryItem*	pIItem	= smart_cast<CInventoryItem*> (spatial->dcast_CObject        ());

		if (0 == pIItem)											continue;
		if (pIItem->object().H_Parent() != NULL)					continue;
		if (!pIItem->CanTake())										continue;
		if ( smart_cast<CExplosiveRocket*>( &pIItem->object() ) )	continue;

		CGrenade*	pGrenade	= smart_cast<CGrenade*> (spatial->dcast_CObject        ());
		if (pGrenade && !pGrenade->Useful())						continue;

		CMissile*	pMissile	= smart_cast<CMissile*> (spatial->dcast_CObject        ());
		if (pMissile && !pMissile->Useful())						continue;
		
		Fvector A, B, tmp; 
		pIItem->object().Center			(A);
		if (A.distance_to_sqr(Position())>4)						continue;

		tmp.sub(A, cam_Active()->vPosition);
		B.mad(cam_Active()->vPosition, cam_Active()->vDirection, tmp.dotproduct(cam_Active()->vDirection));
		float len = B.distance_to_sqr(A);
		if (len > 1)												continue;

		if (maxlen>len && !pIItem->object().getDestroy())
		{
			maxlen = len;
			pNearestItem = pIItem;
		};
	}

	if(pNearestItem)
	{
		CFrustum					frustum;
		frustum.CreateFromMatrix	(Device.mFullTransform,FRUSTUM_P_LRTB|FRUSTUM_P_FAR);
		if (!CanPickItem(frustum, Device.vCameraPosition, &pNearestItem->object()))
			pNearestItem = NULL;
	}
	if (pNearestItem && pNearestItem->cast_game_object())
	{
		if (Level().m_feel_deny.is_object_denied(pNearestItem->cast_game_object()))
				pNearestItem = NULL;
	}
	if (pNearestItem && pNearestItem->cast_game_object())
	{
		if(!pNearestItem->cast_game_object()->getVisible())
				pNearestItem = NULL;
	}

	CurrentGameUI()->UIMainIngameWnd->SetPickUpItem(pNearestItem);

	if (pNearestItem && m_bPickupMode && !m_pPersonWeLookingAt)
	{
		CUsableScriptObject*	pUsableObject = smart_cast<CUsableScriptObject*>(pNearestItem);
		if(pUsableObject && (!m_pUsableObject))
			pUsableObject->use(this);

		//подбирание объекта
		Game().SendPickUpEvent(ID(), pNearestItem->object().ID());
	}
};

void	CActor::Check_for_AutoPickUp()
{
	return;
}


void CActor::PickupInfoDraw(CObject* object)
{
	LPCSTR draw_str = NULL;
	
	CInventoryItem* item = smart_cast<CInventoryItem*>(object);
	if(!item)		return;

	Fmatrix			res;
	res.mul			(Device.mFullTransform,object->XFORM());
	Fvector4		v_res;
	Fvector			shift;

	draw_str = item->NameItem();
	shift.set(0,0,0);

	res.transform(v_res,shift);

	if (v_res.z < 0 || v_res.w < 0)	return;
	if (v_res.x < -1.f || v_res.x > 1.f || v_res.y<-1.f || v_res.y>1.f) return;

	float x = (1.f + v_res.x)/2.f * (Device.dwWidth);
	float y = (1.f - v_res.y)/2.f * (Device.dwHeight);

	UI().Font().pFontLetterica16Russian->SetAligment	(CGameFont::alCenter);
	UI().Font().pFontLetterica16Russian->SetColor		(PICKUP_INFO_COLOR);
	UI().Font().pFontLetterica16Russian->Out			(x,y,draw_str);
}

void CActor::feel_sound_new(CObject* who, int type, CSound_UserDataPtr user_data, const Fvector& Position, float power)
{
	if(who == this)
		m_snd_noise = _max(m_snd_noise, power);
}

//Alundaio: Put this behind define so that it can be disabled
#ifdef	ACTOR_FEEL_GRENADE
void CActor::Feel_Grenade_Update( float rad )
{
	// Find all nearest objects
	Fvector pos_actor;
	Center( pos_actor );

	q_nearest.clear_not_free();
	g_pGameLevel->ObjectSpace.GetNearest( q_nearest, pos_actor, rad, NULL );

	xr_vector<CObject*>::iterator	it_b = q_nearest.begin();
	xr_vector<CObject*>::iterator	it_e = q_nearest.end();

	// select only grenade
	for ( ; it_b != it_e; ++it_b )
	{
		if ( (*it_b)->getDestroy() ) continue;					// Don't touch candidates for destroy

		CGrenade* grn = smart_cast<CGrenade*>( *it_b );
		if( !grn || grn->Initiator() == ID() || grn->Useful() )
		{
			continue;
		}
		if ( grn->time_from_begin_throw() < m_fFeelGrenadeTime )
		{
			continue;
		}
		if ( HUD().AddGrenade_ForMark( grn ) )
		{
			//.	Msg("__ __ Add new grenade! id = %d ", grn->ID() );
		}
	}// for it

	HUD().Update_GrenadeView( pos_actor );
}
#endif

