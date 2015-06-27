//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef TFDIALOGPANELBASE_H
#define TFDIALOGPANELBASE_H
#ifdef _WIN32
#pragma once
#endif

#include "tf_menupanelbase.h"

class CPanelListPanel;

class CTFDialogPanelBase : public CTFMenuPanelBase
{
	DECLARE_CLASS_SIMPLE(CTFDialogPanelBase, CTFMenuPanelBase);

public:
	CTFDialogPanelBase(vgui::Panel* parent, const char *panelName);
	~CTFDialogPanelBase();
	virtual bool Init();
	virtual void OnResetData();
	virtual void OnApplyChanges();
	virtual void OnCommand(const char *command);
	virtual void OnCreateControls() { CreateControls(); OnResetData(); };
	virtual void OnDestroyControls() { DestroyControls(); };
	virtual void OnThink();
	virtual void Show();
	virtual void Hide();
	virtual void SetEmbedded(bool bState) { bEmbedded = bState; };
protected:
	virtual void ApplySchemeSettings(vgui::IScheme *pScheme);
	virtual void PerformLayout();
	virtual void CreateControls();
	virtual void DestroyControls();
	virtual void AddControl(vgui::Panel* panel, int iType, const char* text = "");


	bool			bEmbedded;
	CPanelListPanel *m_pListPanel;
};



#endif // TFDIALOGPANELBASE_H