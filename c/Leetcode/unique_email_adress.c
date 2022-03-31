#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int numUniqueEmails(char** emails, int emailsSize) {

	// i					-> variable de travail
	// i_emails				-> index de déplacement in emails
	// dim_emails_corr		-> Dimension du tableau email_corr
	int email_corr = 0, num_email, x, dim_emails_corr = 0, str_pos_valid_mail, nb_good_mail = 0;
	bool ignore;

	// Un seul mot pour commencer
	char** valid_email = (char**)malloc(sizeof(char*) * emailsSize);
	for (num_email = 0; num_email < emailsSize; num_email++)
		valid_email[num_email] = (char*)malloc(101 * sizeof(char));

	for (num_email = 0; num_email < emailsSize; num_email++) {

		x = 0;
		str_pos_valid_mail = 0;
		ignore = false;
		while (emails[num_email][x] != '@')
		{
			// Si ces n'est pas un point on copie
			if (!ignore) 
			{
				if (emails[num_email][x] == '+')
					ignore = true;
				else if (emails[num_email][x] != '.') {
					valid_email[email_corr][str_pos_valid_mail] = emails[num_email][x];
					str_pos_valid_mail++;
				}
				

			}
			x++;
		}
		

		// After the @ copy all the rest until \0
		while (emails[num_email][x] != '\0')
		{
			valid_email[email_corr][str_pos_valid_mail] = emails[num_email][x];
			str_pos_valid_mail++;
			x++;
		}
		valid_email[num_email][str_pos_valid_mail] = '\0';

		// When end, we check if already exist in email_corr
		// Ignore -> true = present inside
		// ignore -> false = not inside
		//printf("\nMail trouve -> %s", valid_email[email_corr]);
		for (x = 0; x < dim_emails_corr+1; x++) {
			if (x != email_corr && !strcmp(valid_email[email_corr], valid_email[x])) 
				x = 1000;
				// For stop the for
			
		}
		email_corr++;

		if (x != 1001)
			nb_good_mail++;
		dim_emails_corr++;

		
	}

	return nb_good_mail;

}



