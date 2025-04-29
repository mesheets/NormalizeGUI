/*
	Main.cpp - main source file for Normalize GUI - v0.2
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

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNormalize_Main *Normalize_Main;
//---------------------------------------------------------------------------
__fastcall TNormalize_Main::TNormalize_Main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNormalize_Main::InWave_bttnClick(TObject *Sender)
{
  if(singlefile->Checked)
  {
		OpenDialog1->Execute();
  	InWave->Text=OpenDialog1->FileName;

  	if(!InWave->Text.IsEmpty())
    {
  		normalize->Enabled=true;
    }
  }
  else
  {
    AnsiString directory,inifile=ExtractFilePath(Application->ExeName);
  	inifile+="NormalizeGUI.ini";

		TIniFile *Ini = new TIniFile(inifile);

  	SelectDirectory(Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"selectdirectory",""),"",directory);

    delete Ini;

    if(!directory.IsEmpty())
    {
      if(directory.SubString(directory.Length(),1)!="\\")
      {
      	directory+="\\";
      }
    	InWave->Text=directory;
      normalize->Enabled=true;
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TNormalize_Main::Quit1Click(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::About2Click(TObject *Sender)
{
  Normalize_Main->Enabled=false;
	AboutBox->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::OutWave_bttnClick(TObject *Sender)
{
	SaveDialog1->Execute();
  OutWave->Text=SaveDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::OutWave_lblClick(TObject *Sender)
{
	if(OutWave_lbl->Checked)
  {
  	OutWave->Enabled=true;
    OutWave_bttn->Enabled=true;
  }
  else
  {
  	OutWave->Enabled=false;
    OutWave_bttn->Enabled=false;
  }
}
//---------------------------------------------------------------------------


void __fastcall TNormalize_Main::multiply_barChange(TObject *Sender)
{
  multiply->Text=((float)multiply_bar->Position)/100;
	if(Methode_ratio->Checked)
  {
    float f1,f2;
    f1=((float)multiply_bar->Position)/100;
    f2=20*log10(f1);
    amplify_bar->Enabled=true;
    amplify_bar->Position=f2*100;
    amplify_bar->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::Methode_ratioClick(TObject *Sender)
{
 	multiply->Enabled=true;
  amplify->Enabled=false;
  multiply_bar->Enabled=true;
  amplify_bar->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::Method_scanClick(TObject *Sender)
{
	multiply->Enabled=false;
  amplify->Enabled=false;
  multiply_bar->Enabled=false;
  amplify_bar->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::Method_levelClick(TObject *Sender)
{
	multiply->Enabled=false;
  amplify->Enabled=true;
  multiply_bar->Enabled=false;
  amplify_bar->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::amplify_barChange(TObject *Sender)
{
  amplify->Text=((float)amplify_bar->Position)/100;
  if(Method_level->Checked)
  {
		float f1,f2;
  	f1=((float)amplify_bar->Position)/100;
  	f2=exp((f1*log(10))/20);
    multiply_bar->Enabled=true;
  	multiply_bar->Position=f2*100;
    multiply_bar->Enabled=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::abort_barChange(TObject *Sender)
{
	abort->Text=((float)abort_bar->Position)/100;	
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::abort_lblClick(TObject *Sender)
{
	if(abort_lbl->Checked)
  {
  	abort->Enabled=true;
    abort_bar->Enabled=true;
  }
  else
  {
  	abort->Enabled=false;
    abort_bar->Enabled=false;
  }
}
//---------------------------------------------------------------------------


void __fastcall TNormalize_Main::buffer_barChange(TObject *Sender)
{
	buffer->Text=buffer_bar->Position;	
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::normalizeClick(TObject *Sender)
{
  FILE *batch;
  AnsiString normalize,filepos;
  filepos=ExtractFilePath(Application->ExeName);
  normalize=GetShortPath(filepos+"normalize.exe");
  filepos=GetShortPath(filepos)+"normalize.bat";

  if(!normalize.IsEmpty() && FileExists(normalize))
  {

    if((batch=fopen(filepos.c_str(),"w"))!=NULL)
	  {
    	fprintf(batch,"@echo off\n");
      fprintf(batch,"\"%s\" ",normalize.c_str());
      if(Methode_ratio->Checked)
      {
      	fprintf(batch,"-l %s ",multiply->Text.c_str());
      }
      if(Method_level->Checked)
      {
      	fprintf(batch,"-a %s ",amplify->Text.c_str());
      }
      fprintf(batch,"-m %s ",percent->Text.c_str());
      if(abort_lbl->Checked)
      {
      	fprintf(batch,"-x %s ",abort->Text.c_str());
      }
      fprintf(batch,"-b %s ",buffer->Text.c_str());
      if(prompt->Checked)
      {
      	fprintf(batch,"-p ");
      }
      if(dont_abort->Checked)
      {
      	fprintf(batch,"-d ");
      }
      if(OutWave_lbl->Checked)
      {
      	fprintf(batch,"-o \"%s\" ",OutWave->Text.c_str());
      }
      if(singlefile->Checked)
      {
      	fprintf(batch,"\"%s\"",GetShortPath(InWave->Text).c_str());
      }
      else
      {
      	fprintf(batch,"\"%s*.wav\"",GetShortPath(InWave->Text).c_str());
      }
      fprintf(batch,"\ndel \"%s\"",filepos.c_str());
	  	fclose(batch);

	  	system(filepos.c_str());
	  }
  }
}
//---------------------------------------------------------------------------


AnsiString __fastcall TNormalize_Main::GetShortPath(AnsiString filename)
{
	AnsiString returnname;
  char shortname[MAX_PATH]="";
  strcpy(shortname,filename.c_str());
  GetShortPathName(shortname,shortname,MAX_PATH);
  returnname=shortname;
  return returnname;
}


void __fastcall TNormalize_Main::singlefileClick(TObject *Sender)
{
	prompt->Checked=false;
  dont_abort->Checked=false;
	prompt->Enabled=false;
  dont_abort->Enabled=false;
  OutWave_lbl->Enabled=true;
  InWave->Text="";

  AnsiString inifile=ExtractFilePath(Application->ExeName);
  inifile+="NormalizeGUI.ini";

	TIniFile *Ini = new TIniFile(inifile);

  InWave_lbl->Caption=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl","");
  InWave_lbl->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl_hint","");
  InWave->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl_hint","");
  InWave_bttn->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl_hint","");

  delete Ini;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::directoryClick(TObject *Sender)
{
	prompt->Enabled=true;
  OutWave_lbl->Checked=false;
  OutWave_lbl->Enabled=false;
  InWave->Text="";

  AnsiString inifile=ExtractFilePath(Application->ExeName);
  inifile+="NormalizeGUI.ini";

	TIniFile *Ini = new TIniFile(inifile);

  InWave_lbl->Caption=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl2","");
  InWave_lbl->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl2_hint","");
  InWave->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl2_hint","");
  InWave_bttn->Hint=Ini->ReadString(Language_form->language_list->Items->Strings[Language_form->language_list->ItemIndex],"InWave_lbl2_hint","");

  delete Ini;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::promptClick(TObject *Sender)
{
  if(prompt->Checked)
  {
  	dont_abort->Enabled=true;
  }
  else
  {
    dont_abort->Checked=false;
  	dont_abort->Enabled=false;
  }
}
//---------------------------------------------------------------------------




void __fastcall TNormalize_Main::Selectlanguage1Click(TObject *Sender)
{
	Normalize_Main->Enabled=false;
	Language_form->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::Open1Click(TObject *Sender)
{
	singlefile->Checked=true;
  InWave_bttnClick(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TNormalize_Main::Opendirectory1Click(TObject *Sender)
{
	directory->Checked=true;
  InWave_bttnClick(NULL);
}
//---------------------------------------------------------------------------

