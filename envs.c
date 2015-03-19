#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "envs.h"
#include "log.h"

int get_sys_envs(const char *envs, const char *delim_env, const char *delim_key, char *params_key[], char *env_name[], char * env_value[]) {
    char    *tk;
    int     cnt = 0;
	char    *temp_envs;
	
	temp_envs = (char *)malloc( strlen(envs) + 20 );

	strcpy( temp_envs, envs);

    tk = strtok( temp_envs, delim_env );
    while( tk != NULL && cnt < MAXPARAMSNUM ) {
        params_key[cnt++] = tk;
        tk = strtok( NULL, delim_env );
    }

	int cnt_temp = 0;
	
	while( params_key[cnt_temp] != NULL && cnt_temp < cnt ){
		tk = strtok( params_key[cnt_temp], delim_key );
		env_name[cnt_temp] = strtok( NULL, delim_key );
		params_key[cnt_temp] = tk;
		env_value[cnt_temp] = getenv(env_name[cnt_temp]) == NULL ? "NULL" : getenv(env_name[cnt_temp]);
		cnt_temp ++;
	}
	
    return cnt;
}

