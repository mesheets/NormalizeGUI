/*
	Main.h - header source file for Normalize GUI
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
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <math.h>
#include <ComCtrls.hpp>
#include <stdio.h>
#include <inifiles.hpp>
#include <FileCtrl.hpp>

// Forms of the soft
#include "About.h"
#include "Language.h"
//---------------------------------------------------------------------------
class TNormalize_Main : public TForm
{
__published:	// Composants gérés par l'EDI
	TOpenDialog *OpenDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Open1;
	TMenuItem *Quit1;
	TMenuItem *About1;
	TMenuItem *About2;
	TSaveDialog *SaveDialog1;
	TGroupBox *Method_box;
	TRadioButton *Method_scan;
	TRadioButton *Methode_ratio;
	TRadioButton *Method_level;
	TGroupBox *Options_box;
	TEdit *multiply;
	TScrollBar *multiply_bar;
	TEdit *amplify;
	TScrollBar *amplify_bar;
	TLabel *percent_lbl;
	TEdit *percent;
	TUpDown *percent_up;
	TCheckBox *abort_lbl;
	TEdit *abort;
	TScrollBar *abort_bar;
	TLabel *buffer_lbl;
	TEdit *buffer;
	TScrollBar *buffer_bar;
	TButton *normalize;
	TGroupBox *input_output_box;
	TLabel *InWave_lbl;
	TCheckBox *OutWave_lbl;
	TButton *InWave_bttn;
	TButton *OutWave_bttn;
	TGroupBox *process_box;
	TRadioButton *singlefile;
	TRadioButton *directory;
	TCheckBox *prompt;
	TCheckBox *dont_abort;
	TMenuItem *Language1;
	TMenuItem *Selectlanguage1;
	TEdit *InWave;
	TEdit *OutWave;
	TMenuItem *Opendirectory1;
	void __fastcall InWave_bttnClick(TObject *Sender);
	void __fastcall Quit1Click(TObject *Sender);
	void __fastcall About2Click(TObject *Sender);
	void __fastcall OutWave_bttnClick(TObject *Sender);
	void __fastcall OutWave_lblClick(TObject *Sender);
	void __fastcall multiply_barChange(TObject *Sender);
	void __fastcall Methode_ratioClick(TObject *Sender);
	void __fastcall Method_scanClick(TObject *Sender);
	void __fastcall Method_levelClick(TObject *Sender);
	void __fastcall amplify_barChange(TObject *Sender);
	void __fastcall abort_barChange(TObject *Sender);
	void __fastcall abort_lblClick(TObject *Sender);
	void __fastcall buffer_barChange(TObject *Sender);
	void __fastcall normalizeClick(TObject *Sender);
	void __fastcall singlefileClick(TObject *Sender);
	void __fastcall directoryClick(TObject *Sender);
	void __fastcall promptClick(TObject *Sender);
	void __fastcall Selectlanguage1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Opendirectory1Click(TObject *Sender);
private:	// Déclarations de l'utilisateur
public:		// Déclarations de l'utilisateur
	__fastcall TNormalize_Main(TComponent* Owner);
    AnsiString __fastcall GetShortPath(AnsiString filename);
};
//---------------------------------------------------------------------------
extern PACKAGE TNormalize_Main *Normalize_Main;
//---------------------------------------------------------------------------
#endif
