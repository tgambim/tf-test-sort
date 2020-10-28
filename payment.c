/*
 * Rafael Basso
 * Tiago Gambim
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int payment(float value, char status[20]){
	if(value>=0.01 && value<=99999.00){
		if(strcmp(status, "regular")==0 ||
			strcmp(status, "estudante")==0 ||
			strcmp(status, "aposentado")==0 ||
			strcmp(status, "VIP")==0){
			return 0;
		}else{
			return 2;
		}
	}else{
		return 1;
	}
}


