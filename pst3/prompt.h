//---------------------------------------------------------------------------

#ifndef promptH
#define promptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPrompt_Form : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer;
    TLabel *Label_Prompt;

    //void __fastcall TimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TPrompt_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrompt_Form *Prompt_Form;
//---------------------------------------------------------------------------
#endif
