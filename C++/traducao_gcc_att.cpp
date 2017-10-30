// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

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

void regex_gcc(string s, smatch &m, ostream &O) {

		//um regex para cada erro:

		regex e_1("(expected )" "(.*)" "( before )" "(.*)");
		regex e_2("(expected )" "(.*)" "( at )""(end )""(of )" "(input)");
		regex e_3("(.*)" "( was not declared in this scope)");
		regex e_4("(redeclaration of )" "(.*)");
		regex e_5("(.*)" "( previously declared here)");
		regex e_6("(lvalue required as left operand of assignment)");
		regex e_7("(.*)" "( does not name a type)");
		regex e_8("(.*)" "( is not captured)");
		regex e_9("(assignment of read-only variable )" "(.*)");
		regex e_10("(invalid operands of types 'float' and 'double.double.' to binary 'operator.')");
		regex e_11("(expected )" "(.*)" "( before )" "(.*)" "( token)");
		//as mensagens são checadas para testar em qual erro se encaixam

		if (regex_search(s, m, e_1)) {//esse comando salva cada parte da mensagem em um indice de 'm' e retorna true se encontrar o que procurado
            if(m[2] != "initializer")
            {
                O << "esperado " << m[2].str() << " antes de " << m[4].str() << '\n';
            }else
            {
                O << "esperado " << "inicializador" << " antes de " << m[4].str() << '\n';
            }

		}
		else if (regex_search(s, m, e_2)) {

			O << "esperado " << m[2].str() << " no final da entrada" << '\n';
		}
		else if (regex_search(s, m, e_3)) {

			O << m[1].str() << " não foi declarada neste escopo" << '\n';
		}
		else if (regex_search(s, m, e_4)) {

			O << "Redeclaração de " << m[2].str() << '\n';
		}
		else if (regex_search(s, m, e_5)) {

			O << m[1].str() << " declarado anteriormente aqui." << '\n';
		}
		else if (regex_search(s, m, e_6)) {

			O << "Variável exigida como operando à esquerda da atribuição" << '\n';
		}
		else if (regex_search(s, m, e_7)) {

			O << m[1].str() << " não nomeia um tipo" << '\n';
		}
		else if (regex_search(s, m, e_8)) {

			O << m[1].str() << " não é capturado" << '\n';
		}
		else if (regex_search(s, m, e_9)) {

			O << "Atribuição da variável " << m[2].str() << " somente para leitura" << '\n';
		}
		else if (regex_search(s, m, e_10)) {

			O << "Operandos inválidos de tipos 'float' e 'double (double)' para operator-' binário" << '\n';;
		}
		else if(regex_search(s, m, e_11)) {

			O << "esperado " << m[2].str() << " antes do " << m[4].str() << " símbolo" << '\n';
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

	caminho = caminho + "log_" + patch::to_string(cont_log) + ".txt";

	setlocale(LC_ALL, "Portuguese");

	ofstream O("log_teste.txt");


    //Parte da tradução em si

    ifstream I(caminho);
    while(getline(I,str))
    {

    //O << str << '\n' << '\n';

    regex_gcc(str, ex, O);

    }

    O.close();

    return 0;
}

