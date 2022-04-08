#include "Header.h"

/// 
/// 
/// 
/// 
/// 
///  NE MARCHE PAS
/// 
/// 
/// 
/// 
/// 
bool isNumber(char* s) {

	///
	/// Premier et denrier char valide
	/// 
	int len = strlen(s);
	if (len == 1) {
		if (isdigit(s[0]))
			return true;
		return false;
	}

	// Remove blank space
	int index = 0;
	while (s[index] == ' ')
	{
		index++;
	}


	if (s[index] != '+' && s[index] != '-' && !isdigit(s[index]) && s[index] != '.')
		return false;

	if (s[index] == '+' || s[index] == '-')
		index++;

	
	while (s[index] != 'e' && s[index] != '.' && s[index] != '\0' && s[index] != ' ')
	{
		if (!isdigit(s[index]))
			return false;
		index++;
	}



	if (s[index] == '\0')
		return true;
	else if (s[index] == '.') {
		index++;
		while (s[index] != 'e' && s[index] != '\0' && s[index] != ' ')
		{
			if (!isdigit(s[index]))
				return false;
			index++;
		}
	}

	if (s[index] == 'e') {
		index++;

		if (s[index] == '-')
			index++;
		else if (!isdigit(s[index]))
			return false;

		while (s[index] != '\0' && s[index] != ' ')
		{
			if (!isdigit(s[index]))
				return false;
			index++;
		}
	}

	if ((s[index-1] == '.' && index-2 > 0 &&!isdigit(s[index-2])) || s[index-1] == '.' && index-1 )
		return false;

	if (s[index] == ' ') {
		while (s[index] != '\0')
		{
			if (s[index] != ' ')
				return false;
			index++;
		}
	}

	return true;


}



//void main() {
//
//	bool rr = isNumber(". ");
//	bool rr1 = isNumber(".3");
//	bool rrrr = isNumber("3.");
//
//	bool r1 = isNumber("0"			);// = > true
//	bool r2 = isNumber(" 0.1 "		);//	 = > true
//	bool r3 = isNumber("abc"		)	;//	= > false
//	bool r4 = isNumber("1 a"		)	;//	= > false
//	bool r5 = isNumber("2e10"		);//	 = > true
//	bool r11 =isNumber( " -90e3   "	);//		 = > true
//	bool r12 =isNumber( " 1e"		);//	= > false
//	bool r13 =isNumber( "e3"		)	;//	= > false
//	bool r14 =isNumber( " 6e-1"		);//	 = > true
//	bool r15 =isNumber( " 99e2.5 "	);//		= > false
//	bool r21 =isNumber( "53.5e93"	);//		= > true
//	bool r23 =isNumber( " --6 "		);//	= > false
//	bool r234 = isNumber("-+3"		);//	 = > false
//	bool r333 = isNumber("95a54e53"	);//		= > false
//}