void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if( !Edit1->Text.IsEmpty() )
	{
		ListBox1->AddItem(Edit1->Text, 0);
		Edit1->Text = "";
	}
}