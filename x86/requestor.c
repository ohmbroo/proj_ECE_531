// /home/ohmbroo/buildroot-2019.05/output/host/usr/bin/arm-linux-gcc   -c 
// requestor.c -o requestor.o
// /home/ohmbroo/buildroot-2019.05/output/host/usr/bin/arm-linux-gcc
// --sysroot=/home/ohmbroo/buildroot-2019.05/output/staging  -o test_HTTP_arm
// requestor.o  -lcurl -uClibc -lc
//---------------------------------------------------
// Edward Sadzewicz
// ECE 531 IoT
//
// WK-3 Assignment 
// Summary: curl usage via ARM OS compiled on Host
// 
// File - requestor.c
//
// 
// testing for project
//
// compile methed from makefile output above


#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
//#include <getopt.h>
#include <string.h>

//using namespace std;

#define OK				0
#define INIT_ERR	1
#define REQ_ERR		2

//#define URL				"http://10.0.2.2:8000"

int main(int argc, char *argv[])
{
	int opt;
	int opt_curl;
  int x=1;
	int index;
	int u_flag =0;
	int o_flag =0;
	int g_flag =0;
	int p_flag =0;
	int d_flag =0;
	int h_flag =0;

  char *url;
  char build_str[100];

  opterr = 0;

	CURL			*curl;
	CURLcode	res;
	
	curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
	
	while ((opt = getopt(argc, argv, "u:ogpdh")) != -1)
  {
		switch (opt)
    {
			case 'u':    // -u/  --url
        printf("Option u has arg: %s\n", optarg);
				opt_curl = opt;
				u_flag = 1;
        url = strdup(optarg);
				break;
			case 'o':    // -o/ --post
        printf("Option o was provided\n");
				opt_curl = opt;
				o_flag = 1;
				break;
			case 'g':		// -g/  --get
        printf("Option g was provided\n");
				opt_curl = opt;
				g_flag = 1;
				break;				
			case 'p':		//  -p/  --put
        printf("Option p was provided\n");
				opt_curl = opt;
				p_flag = 1;
				break;				
			case 'd':		//  -d/  --delete
        printf("Option d was provided\n");
				opt_curl = opt;
				d_flag = 1;
				break;				
			case 'h':  //  -h/  -- help
        printf("Option h was provided\n");
				opt_curl = opt;
				h_flag = 1;
				break;
			case '?':
				printf("Unknown option: %c\n", optopt);	
				h_flag = 1;
				break;			
			case ':':
				printf("Missing arg for %c\n", optopt);
				break;
			default:
				printf("Options required %c\n", optopt);
				h_flag = 1;
				break;
		}
	}

	printf("\nu_flag = %d\n o_flag = %d\n g_flag = %d\n p_flag = %d\n d_flag = %d\n  h_flag = %d\n", u_flag, o_flag, g_flag, p_flag, d_flag, h_flag); 

	for (index = optind; index < argc; index++)
  {
		printf("non option data string: %s\n", argv[index]);
    strcat(build_str, argv[index]);		
	}

	printf("Built String: %s\n", build_str);

 	if (curl) 
  {
    if (o_flag) 
    {
			printf("IF for POST to url %s\n", url); 
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
			curl_easy_setopt(curl, CURLOPT_URL, url);
	 		curl_easy_setopt(curl, CURLOPT_POST, 1);			
	 		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, build_str);
	 		res = curl_easy_perform(curl);
			printf("I got here IF for POST\n"); 
	 		if(res != CURLE_OK) 
			{
	  		fprintf(stderr, "curl_easy_perform() failed POST: %s\n",
								curl_easy_strerror(res));
  		}	
	 		curl_easy_cleanup(curl);
		}
		else if (g_flag)
    { 
	  	printf("IF for Get url for: %s\n", url); 
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
			curl_easy_setopt(curl, CURLOPT_URL, url);
	 		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	 		res = curl_easy_perform(curl);
			printf("I got in IF for GET\n"); 
	 		if(res != CURLE_OK) {
	  		fprintf(stderr, "curl_easy_perform() failed GET: %s\n",
								curl_easy_strerror(res));
	   	}	
		 	curl_easy_cleanup(curl);
 	  }
    else if (p_flag) 
    {
			printf("If for PUT to url %s\n", url); 
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, build_str);
			res = curl_easy_perform(curl);
			printf("I got here if PUT\n"); 
			if(res != CURLE_OK) 
			{
	 			fprintf(stderr, "curl_easy_perform() failed PUT: %s\n",
								curl_easy_strerror(res));
  		}	
			curl_easy_cleanup(curl);		 	
 	 	}
    else if (d_flag) 
    {
			printf("Curl for DELETE to url %s\n", url); 
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
 			res = curl_easy_perform(curl);
			printf("I got here in DELETE\n"); 
 			if(res != CURLE_OK) 
			{
	 			fprintf(stderr, "curl_easy_perform() failed DELETE: %s\n",
								curl_easy_strerror(res));
  		}	
	 		curl_easy_cleanup(curl);
		}    
		else if (h_flag) 
    {
    	printf("ELSE IF HELP to URL: \n");
			printf("test usage \n"); 
			printf("options -g GET \n"); 
			printf("options -o POST \n");
			printf("options -p PUT \n");
			printf("options -d DELETE \n");
			printf("options -u URL followed by url \n");
			printf("example test -p -u www.webpage.com\n");
 			curl_easy_cleanup(curl);
		}	
		else
		{
			printf("Last else \n");
		}		
	return INIT_ERR;	 
	} // end if(curl)
} // end main

