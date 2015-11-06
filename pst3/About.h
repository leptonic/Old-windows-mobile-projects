//---------------------------------------------------------------------------

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TAbout_Form : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label3;
    TLabel *Label5;
    TLabel *Label2;
    TImage *Image1;
   
private:	// User declarations
public:		// User declarations
    __fastcall TAbout_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbout_Form *About_Form;
//---------------------------------------------------------------------------
#endif
