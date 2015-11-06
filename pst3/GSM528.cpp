//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("Version.cpp", Version_Form);
USEFORM("Security.cpp", Security_Form);
USEFORM("Pri.cpp", PRI_Form);
USEFORM("prompt.cpp", Prompt_Form);
USEFORM("About.cpp", About_Form);
USEFORM("V3_KEY.cpp", Form_V3KEY);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TVersion_Form), &Version_Form);
                 Application->CreateForm(__classid(TSecurity_Form), &Security_Form);
                 Application->CreateForm(__classid(TPRI_Form), &PRI_Form);
                 Application->CreateForm(__classid(TPrompt_Form), &Prompt_Form);
                 Application->CreateForm(__classid(TAbout_Form), &About_Form);
                 Application->CreateForm(__classid(TForm_V3KEY), &Form_V3KEY);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
