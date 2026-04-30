//...
private:
	bool mouseDown; // essa variável guarda o estado do mouse...
//...

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	mouseDown = false; // ... e é importante iniciá-la
}

void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	mouseDown = false;
}

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	Canvas->PenPos = TPoint(X, Y); // mais tarde veremos o porquê disso
	mouseDown = true;
}