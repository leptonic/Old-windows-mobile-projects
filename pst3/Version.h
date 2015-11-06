//---------------------------------------------------------------------------

#ifndef VersionH
#define VersionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//---------------------------------------------------------------------------
class TVersion_Form : public TForm
{
__published:	// IDE-managed Components
    TButton *Button_ReadVersion;
    TButton *Button_Clear;
    TGroupBox *GroupBox1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *Edit_swVersion;
    TEdit *Edit_ffsVersion;
    TEdit *Edit_eepVersion;
    void __fastcall Button_ReadVersionClick(TObject *Sender);
    void __fastcall Button_ClearClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

    //void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TVersion_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVersion_Form *Version_Form;
//---------------------------------------------------------------------------
#endif
