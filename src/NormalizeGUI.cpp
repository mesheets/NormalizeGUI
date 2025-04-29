//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("Main.cpp", Normalize_Main);
USEFORM("About.cpp", AboutBox);
USEFORM("Language.cpp", Language_form);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Normalize GUI";
		Application->CreateForm(__classid(TNormalize_Main), &Normalize_Main);
                 Application->CreateForm(__classid(TAboutBox), &AboutBox);
                 Application->CreateForm(__classid(TLanguage_form), &Language_form);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
