#include "lib.h"

char **strD2Path(char *c)
{
        char **strD;
	char *copy;
        char *tok;
        int i = 0, j = 0, k = 0;

        for (; c[j]; j++)
                ;
        copy = malloc(sizeof(char) * (j + 1));

        _strcpy(copy, c);

	copy[j] = '\0';
        if (c)
        {
		int q = qStrtokPath(c);

		strD = malloc(sizeof(char *) * (q + 1));
		if(!strD)
			return (NULL);

		strD[q] = NULL;

                 tok = strtok(copy, ":");
                 if (tok)
                 {
                         while (tok)
                         {
                                 int len = _strlen(tok);

				 strD[k] = malloc(sizeof(char) * (len + 1));
				 if (!strD)
					 return (NULL);

				 _strcpy(strD[k], tok);

                                 tok = strtok(NULL, ":");
				 k++;
				 //free(strD[k]);
                         }
			 strD[k] = '\0';
			 //free(strD);
                 }
        }
	
        free(copy);
        return (strD);
}
