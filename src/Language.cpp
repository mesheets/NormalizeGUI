/*
	Language.cpp - Language box source file for Normalize GUI - v0.2
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
#include <vcl.h>
#pragma hdrstop

#include "Language.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLanguage_form *Language_form;
//---------------------------------------------------------------------------
__fastcall TLanguage_form::TLanguage_form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLanguage_form::FormCreate(TObject *Sender)
{
	AnsiString inifile=ExtractFilePath(Application->ExeName);
  inifile+="NormalizeGUI.ini";

	TIniFile *Ini = new TIniFile(inifile);

  Ini->ReadSections(language_list->Items);
  language_list->Items->Delete(0);
  language_list->ItemIndex=language_list->Items->IndexOf(Ini->ReadString("Settings","Language","English"));

  delete Ini;

  Change_language(language_list->Items->Strings[language_list->ItemIndex]);
}
//---------------------------------------------------------------------------
void __fastcall TLanguage_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
	Normalize_Main->Enabled=true;	
}
//---------------------------------------------------------------------------


void __fastcall TLanguage_form::Change_language(AnsiString language)
{
	AnsiString inifile=ExtractFilePath(Application->ExeName);
  inifile+="NormalizeGUI.ini";

	TIniFile *Ini = new TIniFile(inifile);
  Normalize_Main->File1->Caption=Ini->ReadString(language,"File1","");
  Normalize_Main->Open1->Caption=Ini->ReadString(language,"Open1","");
  Normalize_Main->Opendirectory1->Caption=Ini->ReadString(language,"Opendirectory1","");
  Normalize_Main->Quit1->Caption=Ini->ReadString(language,"Quit1","");
  Normalize_Main->Language1->Caption=Ini->ReadString(language,"Language1","");
  Normalize_Main->Selectlanguage1->Caption=Ini->ReadString(language,"SelectLanguage1","");
  Normalize_Main->About1->Caption=Ini->ReadString(language,"About1","");
  Normalize_Main->About2->Caption=Ini->ReadString(language,"About2","");
  Normalize_Main->process_box->Caption=Ini->ReadString(language,"process_box","");
  Normalize_Main->singlefile->Caption=Ini->ReadString(language,"singlefile","");
  Normalize_Main->singlefile->Hint=Ini->ReadString(language,"singlefile_hint","");
  Normalize_Main->directory->Caption=Ini->ReadString(language,"directory","");
  Normalize_Main->directory->Hint=Ini->ReadString(language,"directory_hint","");
  Normalize_Main->input_output_box->Caption=Ini->ReadString(language,"input_output_box","");
  if(Normalize_Main->singlefile->Checked)
  {
  	Normalize_Main->InWave_lbl->Caption=Ini->ReadString(language,"InWave_lbl","");
  	Normalize_Main->InWave_lbl->Hint=Ini->ReadString(language,"InWave_lbl_hint","");
    Normalize_Main->InWave->Hint=Ini->ReadString(language,"InWave_lbl_hint","");
    Normalize_Main->InWave_bttn->Hint=Ini->ReadString(language,"InWave_lbl_hint","");
  }
  else
  {
  	Normalize_Main->InWave_lbl->Caption=Ini->ReadString(language,"InWave_lbl2","");
    Normalize_Main->InWave_lbl->Hint=Ini->ReadString(language,"InWave_lbl2_hint","");
    Normalize_Main->InWave->Hint=Ini->ReadString(language,"InWave_lbl2_hint","");
    Normalize_Main->InWave_bttn->Hint=Ini->ReadString(language,"InWave_lbl2_hint","");
  }
  Normalize_Main->OutWave_lbl->Caption=Ini->ReadString(language,"OutWave_lbl","");
  Normalize_Main->OutWave_lbl->Hint=Ini->ReadString(language,"OutWave_lbl_hint","");
  Normalize_Main->OutWave->Hint=Ini->ReadString(language,"OutWave_lbl_hint","");
  Normalize_Main->OutWave_bttn->Hint=Ini->ReadString(language,"OutWave_lbl_hint","");
  Normalize_Main->Method_box->Caption=Ini->ReadString(language,"Method_box","");
  Normalize_Main->Method_scan->Caption=Ini->ReadString(language,"Method_scan","");
  Normalize_Main->Methode_ratio->Caption=Ini->ReadString(language,"Methode_ratio","");
  Normalize_Main->Method_level->Caption=Ini->ReadString(language,"Method_level","");
  Normalize_Main->Options_box->Caption=Ini->ReadString(language,"Options_box","");
  Normalize_Main->percent_lbl->Caption=Ini->ReadString(language,"percent_lbl","");
  Normalize_Main->abort_lbl->Caption=Ini->ReadString(language,"abort_lbl","");
  Normalize_Main->buffer_lbl->Caption=Ini->ReadString(language,"buffer_lbl","");
  Normalize_Main->prompt->Caption=Ini->ReadString(language,"prompt","");
  Normalize_Main->dont_abort->Caption=Ini->ReadString(language,"dont_abort","");
  Normalize_Main->normalize->Caption=Ini->ReadString(language,"normalize","");
  Language_form->Caption=Ini->ReadString(language,"Language_form","");
  language_lbl->Caption=Ini->ReadString(language,"language_lbl","");
  language_ok->Caption=Ini->ReadString(language,"language_ok","");
  AboutBox->Caption=Ini->ReadString(language,"AboutBox","");
  AboutBox->Label3->Caption=Ini->ReadString(language,"Label3","");
  AboutBox->Label4->Caption=Ini->ReadString(language,"Label4","");
  AboutBox->OKButton->Caption=Ini->ReadString(language,"OKButton","");

  delete Ini;
}
void __fastcall TLanguage_form::language_okClick(TObject *Sender)
{
	Change_language(language_list->Items->Strings[language_list->ItemIndex]);

  AnsiString inifile=ExtractFilePath(Application->ExeName);
  inifile+="NormalizeGUI.ini";

	TIniFile *Ini = new TIniFile(inifile);

  Ini->WriteString("Settings","Language",language_list->Items->Strings[language_list->ItemIndex]);

  delete Ini;

  Close();
}
//---------------------------------------------------------------------------
