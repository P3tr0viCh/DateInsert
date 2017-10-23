// ---------------------------------------------------------------------------

#ifndef DateInsertMainH
#define DateInsertMainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>

#include "SendKeys.h"

// ---------------------------------------------------------------------------
class TMain : public TForm {
__published: // IDE-managed Components

	TTrayIcon *TrayIcon;
	TPopupMenu *PopupMenu;
	TMenuItem *miAbout;
	TMenuItem *miSeparator;
	TMenuItem *miClose;

	void __fastcall miCloseClick(TObject *Sender);
	void __fastcall miAboutClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private: // User declarations

	CSendKeys sk;

	MESSAGE void __fastcall WMHotKey(TWMHotKey &Message);

	void RegisterHotKey(String HotKey);

	void InsertDate();

public: // User declarations
	BEGIN_MESSAGE_MAP VCL_MESSAGE_HANDLER(WM_HOTKEY, TWMHotKey, WMHotKey)
		END_MESSAGE_MAP(TForm)

		__fastcall TMain(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
// ---------------------------------------------------------------------------
#endif
