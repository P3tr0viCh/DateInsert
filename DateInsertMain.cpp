// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Clipbrd.hpp"

#include "DateInsertMain.h"

#include "UtilsMisc.h"
#include "UtilsStr.h"
#include "UtilsKAndM.h"
#include "AboutFrm.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;

#define HOTKEY_ID 0x0000

// ---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TMain::miCloseClick(TObject *Sender) {
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TMain::miAboutClick(TObject *Sender) {
	miAbout->Enabled = false;
	ShowAbout(14);
	miAbout->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender) {
    Caption = Application->Title;
	TrayIcon->Hint = Caption;
	RegisterHotKey("Ctrl+Shift+D");
}

// ---------------------------------------------------------------------------
void __fastcall TMain::FormDestroy(TObject *Sender) {
	UnregisterHotKey(Handle, HOTKEY_ID);
}

// ---------------------------------------------------------------------------
void TMain::RegisterHotKey(String HotKey) {
	Word Key;
	bool HasWinKey;
	TShiftState Shift;
	UINT Modifyers;

	ShortCutToKey(TextToWinShortCut(HotKey, HasWinKey), Key, Shift);

	Modifyers = HasWinKey ? MOD_WIN : 0;
	if (Shift.Contains(ssShift))
		Modifyers = Modifyers | MOD_SHIFT;
	if (Shift.Contains(ssAlt))
		Modifyers = Modifyers | MOD_ALT;
	if (Shift.Contains(ssCtrl))
		Modifyers = Modifyers | MOD_CONTROL;
	Modifyers = Modifyers | MOD_NOREPEAT;

	bool Result = ::RegisterHotKey(Handle, HOTKEY_ID, Modifyers, Key);
	if (!Result) {
		MsgBoxErr(Format
			("Не удалось зарегистрировать сочетание клавиш '%s'.\n\nВозможно, оно уже используется.",
			ARRAYOFCONST((HotKey))));
	}
}

// ---------------------------------------------------------------------------
MESSAGE void __fastcall TMain::WMHotKey(TWMHotKey &Message) {
	TForm::Dispatch(&Message);
	if (Message.HotKey == HOTKEY_ID) {
		InsertDate();
	}
}

// ---------------------------------------------------------------------------
bool IsModifyersClamped() {
	return IsShift() || IsCtrl() || IsAlt() || IsKey(VK_LWIN) || IsKey(VK_RWIN);
}

// ---------------------------------------------------------------------------
void TMain::InsertDate() {
	while (IsModifyersClamped() && !Application->Terminated) {
		Application->ProcessMessages();
	}

	Clipboard()->AsText = FormatDateTime("yyyy.MM.dd", Now());

	sk.SendKeys(L"^v", false);

}

// ---------------------------------------------------------------------------
