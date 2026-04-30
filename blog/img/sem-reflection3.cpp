typedef map<string, Method> MethodList; // uma variável desse tipo armazena todas as funções

void CommandPrompt::Interact(ostream& os, istream& is)
{
        while( is )
        {
                string func;
                vector<string> args;

                if( ParseLine(is, func, args) )
                {
                        // se a função desejada está em nossa lista,
                        // podemos chamá-la, mesmo sem conhecer qual é
                        if( Method m = m_funcs[func] )
                                m(args);
                }
        }
}
