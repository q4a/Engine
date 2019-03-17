//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef C_ENVPROJECTED_TEXTURE_H
#define C_ENVPROJECTED_TEXTURE_H
#ifdef _WIN32
#pragma once
#endif

#include "c_baseentity.h"
#include "basetypes.h"

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
class C_EnvProjectedTexture : public C_BaseEntity
{
	DECLARE_CLASS( C_EnvProjectedTexture, C_BaseEntity );
public:
	DECLARE_CLIENTCLASS();

	virtual void OnDataChanged( DataUpdateType_t updateType );
	void	ShutDownLightHandle( void );

	virtual void Simulate();

	void	UpdateLight( void );

	C_EnvProjectedTexture();
	~C_EnvProjectedTexture();

private:

	ClientShadowHandle_t m_LightHandle;
	bool m_bForceUpdate;

	EHANDLE	m_hTargetEntity;

	bool		m_bState;
	bool		m_bAlwaysUpdate;
	float		m_flLightFOV;
	bool		m_bEnableShadows;
	bool		m_bLightOnlyTarget;
	bool		m_bLightWorld;
	bool		m_bCameraSpace;

	Vector		m_LinearFloatLightColor;
	int			m_nLinear;
	int			m_nQuadratic;
	int			m_nConstant;

	float		m_flAmbient;
	float		m_flNearZ;
	float		m_flFarZ;
	char		m_SpotlightTextureName[ MAX_PATH ];
	//CTextureReference	m_SpotlightTexture;
	int			m_nSpotlightTextureFrame;
	int			m_nShadowQuality;
};
#endif // C_ENV_PROJECTED_TEXTURE_H