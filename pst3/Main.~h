//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>


//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TComboBox *ComboBox_Port;
    TButton *Button_OpenPort;
    TButton *Button_ClosePort;
    TButton *Button_Version;
    TButton *Button_Security;
    TButton *Button_PRI;
    TStatusBar *StatusBar1;
    TMainMenu *MainMenu;
    TMenuItem *FileF1;
    TMenuItem *OpenFile;
    TMenuItem *SaveFile;
    TMenuItem *Exit1;
    TOpenDialog *OpenDialog_File;
    TSaveDialog *SaveDialog;
    TMenuItem *Help1;
    TMenuItem *About1;
    TMenuItem *WriteAll;
    TButton *Button_V3KEY;


    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button_OpenPortClick(TObject *Sender);
    void __fastcall Button_ClosePortClick(TObject *Sender);
    void __fastcall Button_VersionClick(TObject *Sender);
    void __fastcall Button_SecurityClick(TObject *Sender);
    void __fastcall Button_PRIClick(TObject *Sender);
    void __fastcall OpenFileClick(TObject *Sender);
    void __fastcall SaveFileClick(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall WriteAllClick(TObject *Sender);
    void __fastcall Button_V3KEYClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
