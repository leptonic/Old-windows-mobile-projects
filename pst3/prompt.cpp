//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "prompt.h"

extern bool g_bSetBanner;
extern bool g_bSmsTemplateWrite;
extern bool g_bSmsTemplateRead;
extern bool g_bOpenPort;
extern bool g_bAllWrited;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPrompt_Form *Prompt_Form;
//---------------------------------------------------------------------------
__fastcall TPrompt_Form::TPrompt_Form(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

//void __fastcall TPrompt_Form::TimerTimer(TObject *Sender)
//{
    /*if(g_bAllWrited)
    {
        //Prompt_Form->Hide();
        g_bSetBanner = true;
        g_bSmsTemplateWrite = true;
        g_bSmsTemplateRead = true;
        if(g_bSetBanner)
        {
            Prompt_Form->Hide();
            g_bSetBanner = false;
        }

	    if(g_bSmsTemplateWrite)
	    {
	        Prompt_Form->Hide();
	        g_bSmsTemplateWrite = false;
	    }

	    if(g_bSmsTemplateRead)
	    {
	        Prompt_Form->Hide();
	        g_bSmsTemplateRead = false;
	    }

    }
	else
	{ */
	   /* if(g_bSetBanner)
	    {
	        Prompt_Form->Hide();
	        g_bSetBanner = false;
	    }

	    if(g_bSmsTemplateWrite)
	    {
	        Prompt_Form->Hide();
	        g_bSmsTemplateWrite = false;
	    }

	    if(g_bSmsTemplateRead)
	    {
	        Prompt_Form->Hide();
	        g_bSmsTemplateRead = false;
	    } */
	//}
    /*if(g_bOpenPort)
    {
        Prompt_Form->Hide();
    } */

//}
//---------------------------------------------------------------------------
