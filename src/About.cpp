/*
	About.cpp - About box source file for Normalize GUI - v0.2
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
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include <shellapi.h>
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::Label2Click(TObject *Sender)
{
	ShellExecute(Application->Handle,"open","http://www.bheller.com",NULL,NULL,SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::Label5Click(TObject *Sender)
{
	ShellExecute(Application->Handle,"open","http://www.neon1.net",NULL,NULL,SW_SHOWDEFAULT);	
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::OKButtonClick(TObject *Sender)
{
	AboutBox->Close();	
}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormClose(TObject *Sender, TCloseAction &Action)
{
	Normalize_Main->Enabled=true;	
}
//---------------------------------------------------------------------------

