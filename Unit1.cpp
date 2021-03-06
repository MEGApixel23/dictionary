//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "src/Dictionary.cpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
{
  
}

Dictionary *dict = new Dictionary;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString userInput = Edit1->Text;
	AnsiString sourceLang;
	
	switch (ComboBox1->ItemIndex)
	{
		case 0:
			sourceLang = "en";
			break;
		case 1:
			sourceLang = "ua";
			break;
		default:
			sourceLang = "en";
	}

	Memo2->Clear();
    Memo2->Lines->Append( 
		dict->translate(userInput, sourceLang)
	);
}

void __fastcall TForm1::changeLanguage(TObject *Sender)
{
	switch (ComboBox1->ItemIndex)
	{
		case 0:
			Button1->Caption = "Translate";
			break;
		case 1:
			Button1->Caption = "Перекласти";
			break;
	}
}
