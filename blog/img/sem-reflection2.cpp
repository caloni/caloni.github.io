typedef void (Method*)(vector<string>& args);

class CommandPrompt
{
public:
        void Add(string name, Method m); // adiciona novo método
        void Interact(ostream& os, istream& is); // começa interação com usuário
};
