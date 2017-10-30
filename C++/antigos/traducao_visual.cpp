
#include <iostream>
#include <regex>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

void regex_visual(string s, smatch &m, ostream &O) {

	regex e_1("(expected )" "(a[n]* )" "(.*)");
	regex e_2("(.*)" "(redefinition)");
	regex e_3("(syntax error: missing )" "(.*)" "( before )" "(.*)");
	regex e_4("(syntax error: identifier )" "(.*)");
	regex e_5("(missing type specifier . int assumed. Note: C.. does not support default.int)");
	regex e_6("(syntax error: )" "(.*)");
	regex e_7("(.*)" "(: undeclared identifier)");
	regex e_8("(identifier )" "(.*)" "(is undefined)");
	regex e_9("(expression must be a modifiable lvalue)");
	regex e_10("(.*)" "(: left operand must be l-value)");
	regex e_11("(illegal)" "(.*)" "(without matching )" "(.*)");
	regex e_12("(illegal )""(.*)");
	regex e_13("(.*)" "( missing function header .old-style formal list..)");
	regex e_14("(unexpected end-of-file found)");
	regex e_15("(cannot determine which instance of overloaded function )" "(.*)" "( is intended)");
	regex e_16("(.*)" "(: unable to resolve function overload)");
	regex e_17("(mismatch in formal parameter list)");
	regex e_18("(the left brace )" "(.*)" "( was unmatched at the end of the file)");
	regex e_19("(expected )" "(.*)");

	if (regex_search(s, m, e_1)) {//esse comando salva cada parte da mensagem em um indice de 'm' e retorna true se encontrar o que procurado

		O << "Esperado uma " << m[3].str() << '\n';
	}
	else if (regex_search(s, m, e_2)) {

		O << "Redefinição de "<< m[1].str() << '\n';
	}
	else if (regex_search(s, m, e_3)) {

		O << "Erro de sintaxe: faltando " << m[2].str() << " antes de " << m[4].str() << '\n';
	}
	else if (regex_search(s, m, e_4)) {

		O << "Erro de sintaxe: Identificador " << m[2].str() << '\n';
	}
	else if (regex_search(s, m, e_5)) {

		O << "Especificador de tipo ausente - int assumido. Nota: C++ int- não suporta padrão"  << '\n';
	}
	else if (regex_search(s, m, e_6)) {

		O << "Erro de sintaxe: " << m[2].str() << '\n';
	}
	else if (regex_search(s, m, e_7)) {

		O << m[1].str() << " identificador não declarado " << '\n';
	}
	else if (regex_search(s, m, e_8)) {

		O << "identificador " << m[2].str() <<" é indefinido" << '\n';
	}
	else if (regex_search(s, m, e_9)) {

		O << "Expressão deve ser uma variável" << '\n';
	}
	else if (regex_search(s, m, e_10)) {

		O <<  m[1].str() << " operando á esquerda deve ser uma variável" << '\n';
	}
	else if (regex_search(s, m, e_11)) {

		O << "ilegal " << m[2].str() << " sem correspondência com  " << m[4].str() << '\n';
	}
	else if (regex_search(s, m, e_12)) {

		O << m[2].str() << " ilegal" << '\n';
	}
	else if (regex_search(s, m, e_13)) {

		O << m[1].str() << " cabeçalho de função ausente (lista formal no estilo antigo?)" << '\n';
	}
	else if (regex_search(s, m, e_14)) {

		O << "Inesperado fim-de-arquivo encontrado" << '\n';
	}
	else if (regex_search(s, m, e_15)) {

		O << "Não pode determinar qual instância da função sobrecarregada "<< m[2].str() << " se destina" << '\n';
	}
	else if (regex_search(s, m, e_16)) {

		O << m[1].str() << ": incapaz de resolver sobrecarga de função" << '\n';
	}
	else if (regex_search(s, m, e_17)) {

		O << "incompatibilidade na lista de parâmetros formal" << '\n';
	}
	else if (regex_search(s, m, e_18)) {

		O << "O símbolo esquerda " << m[2].str() << " foi incomparável no final do arquivo" << '\n';
	}
	else if (regex_search(s, m, e_19)) {

		O << "Esperado " << m[2].str() << '\n';
	}
}

int main()
{

	string str,arq;

	smatch ex;

	setlocale(LC_ALL, "Portuguese");
	ofstream O("log_teste.txt");
    getline(cin, arq);

    ifstream I(arq);
    while(getline(I,str))
    {

    O << str << '\n' << '\n';

    regex_visual(str, ex, O);
    O << '\n';
    }
    O.close();

    return 0;
}
