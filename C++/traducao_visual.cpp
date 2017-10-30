#include <iostream>
#include <regex>
#include <string>
#include <locale.h>
#include <fstream>
#include <sstream>

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void regex_visual(string s, smatch &m, ostream &O) {

	regex e_1("(expected )" "(a[n]* )" "(.*)");
	regex e_2("'(.*)" "(redefinition)");
	regex e_3("(syntax error: missing )" "(.*)" "( before )" "(.*)");
	regex e_4("(syntax error: identifier )" "(.*)");
	regex e_5("(missing type specifier . int assumed. Note: C.. does not support default.int)");
	regex e_6("(syntax error: )" "(.*)");
	regex e_7("'(.*)" "(: undeclared identifier)");
	regex e_8("(identifier )" "(.*)" "(is undefined)");
	regex e_9("(expression must be a modifiable lvalue)");
	regex e_10("'(.*)" "(: left operand must be l-value)");
	regex e_11("(illegal)" "(.*)" "(without matching )" "(.*)");
	regex e_12("(illegal )""(.*)");
	regex e_13("'(.*)" "( missing function header .old-style formal list..)");
	regex e_14("(unexpected end-of-file found)");
	regex e_15("(cannot determine which instance of overloaded function )" "(.*)" "( is intended)");
	regex e_16("'(.*)" "(: unable to resolve function overload)");
	regex e_17("(mismatch in formal parameter list)");
	regex e_18("(the left brace )" "(.*)" "( was unmatched at the end of the file)");
	regex e_19("(expected )" "(.*)");
	regex e_20("LINK \: fatal error LNK1561\: entry point must be defined");
	regex erro("error");
	regex base("(cpp)(\\([0-9]+\\))");

	if(regex_search(s, m, base) && regex_search(s,erro)){
        O << m[2] << ": ";
	}
	if (regex_search(s, m, e_1)) {//esse comando salva cada parte da mensagem em um indice de 'm' e retorna true se encontrar o que procurado

		O << "erro: ";
		O << "Esperado uma " << m[3].str() << '\n';
	}
	else if (regex_search(s, m, e_2)) {

		O << "erro: ";
		O << "Redefinição de '"<< m[1].str() << '\n';
	}
	else if (regex_search(s, m, e_3)) {

		O << "erro: ";
		O << "Erro de sintaxe: faltando " << m[2].str() << " antes de " << m[4].str() << '\n';
	}
	else if (regex_search(s, m, e_4)) {

		O << "erro: ";
		O << "Erro de sintaxe: Identificador " << m[2].str() << '\n';
	}
	else if (regex_search(s, m, e_5)) {

		O << "erro: ";
		O << "Especificador de tipo ausente - int assumido. Nota: C++ int- não suporta padrão"  << '\n';
	}
	else if (regex_search(s, m, e_6)) {

		O << "erro: ";
		O << "Erro de sintaxe: " << m[2].str() << '\n';
	}
	else if (regex_search(s, m, e_7)) {

		O << "erro: ";
		O << "'" << m[1].str() << " identificador não declarado " << '\n';
	}
	else if (regex_search(s, m, e_8)) {

		O << "erro: ";
		O << "identificador " << m[2].str() <<" é indefinido" << '\n';
	}
	else if (regex_search(s, m, e_9)) {

		O << "erro: ";
		O << "Expressão deve ser uma variável" << '\n';
	}
	else if (regex_search(s, m, e_10)) {

		O << "erro: ";
		O << "'" <<  m[1].str() << " operando á esquerda deve ser uma variável" << '\n';
	}
	else if (regex_search(s, m, e_11)) {

		O << "erro: ";
		O << "ilegal " << m[2].str() << " sem correspondência com  " << m[4].str() << '\n';
	}
	else if (regex_search(s, m, e_12)) {

		O << "erro: ";
		O << m[2].str() << " ilegal" << '\n';
	}
	else if (regex_search(s, m, e_13)) {

		O << "erro: ";
		O << "'" << m[1].str() << " cabeçalho de função ausente (lista formal no estilo antigo?)" << '\n';
	}
	else if (regex_search(s, m, e_14)) {

		O << "erro: ";
		O << "Inesperado fim-de-arquivo encontrado" << '\n';
	}
	else if (regex_search(s, m, e_15)) {

		O << "erro: ";
		O << "Não pode determinar qual instância da função sobrecarregada "<< m[2].str() << " se destina" << '\n';
	}
	else if (regex_search(s, m, e_16)) {

		O << "erro: ";
		O << "'" << m[1].str() << ": incapaz de resolver sobrecarga de função" << '\n';
	}
	else if (regex_search(s, m, e_17)) {

		O << "erro: ";
		O << "incompatibilidade na lista de parâmetros formal" << '\n';
	}
	else if (regex_search(s, m, e_18)) {

		O << "erro: ";
		O << "O símbolo esquerda " << m[2].str() << " foi incomparável no final do arquivo" << '\n';
	}
	else if (regex_search(s, m, e_19)) {

		O << "erro: ";
		O << "Esperado " << m[2].str() << '\n';
	}
	else if(regex_search(s, m, e_20))
        {
            O << "erro: ";
        }
}

int main()
{
    string str,arq;

	smatch ex;

	// Parte para encontrar o caminho dos logs

	//pasta do aluno
	ifstream cont_pasta_prin("..\\contador.txt");
	int cont_pasta = 0;
	cont_pasta_prin >> cont_pasta;

	cont_pasta = cont_pasta -1;

	string caminho = "..\\" + patch::to_string(cont_pasta) + "\\";

	//pasta do programa
	ifstream cont_programa(caminho + "contador.txt");
	int cont_prog = 0;
	cont_programa >> cont_prog;

	caminho = caminho + patch::to_string(cont_prog) + "\\"; // ..\\291\\0

	//pasta do log
	ifstream cont(caminho + "contador.txt");
	int cont_log = 0;
	cont >> cont_log;
	cont_log = cont_log - 1;

	setlocale(LC_ALL, "pt_BR.UTF-8");

	ofstream O(caminho + "log_traducao.txt");

    //Parte da tradução em si

    //contornar o problema de aparecer uma linha de código onde ta o erro

    ifstream I(caminho + "log_" + patch::to_string(cont_log) + ".txt");
    while(getline(I,str))
    {

    //O << str << '\n' << '\n';

        regex_visual(str, ex, O);

    }

    O.close();

    return 0;
}
