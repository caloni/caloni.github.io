void __fastcall TMain::ListBoxDragDrop(TObject *Sender, TObject *Source, 
	int X, int Y)
{
	if( TListBox* listBox = dynamic_cast<TListBox*>(Sender) )
	{
		TWinControl* winCtrl = static_cast<TWinControl*>(Source);

		if( listBox != winCtrl )
		{
			listBox->Items->Add(winCtrl->Name);
			winCtrl->Visible = false;
		}
	}
}

void __fastcall TMain::FormDragDrop(TObject *Sender, TObject *Source,
	int X, int Y)
{
	if( TForm* form = dynamic_cast<TForm*>(Sender) )
	{
		TControl* ctrl = 0;

		if( TListBox* listBox = dynamic_cast<TListBox*>( Source ) )
		{
			for( int i = 0; i < listBox->Count; ++i )
			{
				if( listBox->Selected[i] )
				{
					ctrl = this->FindChildControl(listBox->Items->Strings[i]);
					listBox->Items->Delete(i);
					break;
				}
			}
		}
		else
			ctrl = dynamic_cast<TControl*>(Source);

		if( ctrl )
		{
			ctrl->Top = Y;
			ctrl->Left = X;
			ctrl->Visible = true;
		}
	}
}