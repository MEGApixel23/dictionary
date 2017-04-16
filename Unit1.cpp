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
//---------------------------------------------------------------------------

Dictionary *dict = new Dictionary;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Memo2->Clear();
	AnsiString userInput = Edit1->Text;

	Memo2->Lines->Append(
		dict->translate(userInput)
	);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
	exit(1);
}
//---------------------------------------------------------------------------

