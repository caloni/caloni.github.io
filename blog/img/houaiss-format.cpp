void format(string& str)
{
	string::size_type pos1 = 0;
	string::size_type pos2 = 0;

	while( (pos1 = str.find('<')) != string::npos )
		str.replace(pos1, 1, "<");

	while( (pos1 = str.find('>')) != string::npos )
		str.replace(pos1, 1, ">");

	while( (pos1 = str.find('{')) != string::npos )
	{
		if( pos1 && str[pos1 - 1] == '\\' ) // caractere de escape
			str.replace(pos1 - 1, 2, "{");
		else
		{
			string subStr;

			pos2 = str.find('}', pos1);

			if( pos2 != string::npos )
				subStr = str.substr(pos1 + 1, pos2 - pos1 - 1);
			else
				subStr = str.substr(pos1 + 1);

			istringstream is(subStr);

			string fmt;
			string word;
			is >> fmt;
			getline(is, word);
			if( word[0] == ' ' )
			word.erase(0, 1);

			if( fmt.find("\\i") != string::npos )
				word = "<i>" + word + "</i>";

			if( fmt.find("\\b") != string::npos )
				word = "<b>" + word + "</b>";

			if( fmt.find("\\f20") != string::npos )
				word = "<font style=\"text-transform: uppercase;\">" + word + "</font>";

			if( fmt.find("\\super") != string::npos )
				word = "<font style=\"vertical-align: super;\">" + word + "</font>";

			if( pos2 != string::npos )
				str.replace(pos1, pos2 - pos1 + 1, word);
			else
				str.replace(pos1, pos2, word);
		}
	}
}

