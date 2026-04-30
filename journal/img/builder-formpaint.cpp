void __fastcall TForm1::FormPaint(TObject *Sender)
{
	for( size_t i = 0; i < mouseHistory.size(); ++i )
	{
		// primeiro colocamos o objeto pen no lugar origem...
		Canvas->PenPos = TPoint(mouseHistory[i].Left, mouseHistory[i].Top);

		// ... e depois reproduzimos nossa pincelada passada
		Canvas->LineTo(mouseHistory[i].Right, mouseHistory[i].Bottom);
	}
}