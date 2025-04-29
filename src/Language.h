/*
	Language.h - Language box header source file for Normalize GUI
	(c) 2001, Bruce Heller <bheller@bheller.com>

	This file is part of Normalize GUI.

	Normalize GUI is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Normalize GUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
//---------------------------------------------------------------------------
#ifndef LanguageH
#define LanguageH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Main.h"
//---------------------------------------------------------------------------
class TLanguage_form : public TForm
{
__published:	// Composants gérés par l'EDI
	TComboBox *language_list;
	TLabel *language_lbl;
	TButton *language_ok;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall language_okClick(TObject *Sender);
private:	// Déclarations de l'utilisateur
public:		// Déclarations de l'utilisateur
	__fastcall TLanguage_form(TComponent* Owner);
    void __fastcall Change_language(AnsiString language);
};
//---------------------------------------------------------------------------
extern PACKAGE TLanguage_form *Language_form;
//---------------------------------------------------------------------------
#endif
