FuzzyCall fuzzyObject; // esse é o objeto local
FuzzyCall* pFuzzy = &fuzzyObject; // ponteiro para esse mesmo objeto

( fuzzyObject.*pMethod )(); // [objeto] .* [ponteiro de método]
( fuzzyObject->*pMethod )(); // [ponteiro para objeto] ->* [ponteiro de método]