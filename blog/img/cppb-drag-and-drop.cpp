void __fastcall TMain::FormDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
	Accept = true;
}

void __fastcall TMain::ListBoxDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
	Accept = dynamic_cast<TWinControl*>( Source ) ? true : false;
}