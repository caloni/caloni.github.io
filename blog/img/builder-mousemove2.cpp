//...
private:
	bool mouseDown; // essa variavel guarda o estado do mouse
	std::vector<TRect> mouseHistory; // um TRect guarda duas posicoes XY
//...

// ...
{
	if( mouseDown )
	{
		// guardando a pincelada para reproduzi-la depois
		mouseHistory.push_back( TRect(Canvas->PenPos, TPoint(X, Y)) );
		Canvas->LineTo(X, Y);
	}
}
//...