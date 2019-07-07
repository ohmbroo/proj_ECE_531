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
#include <getopt.h>
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
  int opt_test;
  int x=1;

  char *url;

  opterr = 0;

	CURL			*curl;
	CURLcode	res;
	
	curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
	
	while ((opt = getopt(argc, argv, "-u:ogpdh")) != -1)
  {
		switch (opt)
    {
			case 'u':    // -u/  --url
        printf("Option u has arg: %s\n", optarg);
				opt_curl = opt;
        url = strdup(optarg);
				break;
			case 'o':    // -o/ --post
        printf("Option o was provided\n");
				opt_curl = opt;
				break;
			case 'g':		// -g/  --get
        printf("Option g was provided\n");
				opt_curl = opt;
				break;				
			case 'p':		//  -p/  --put
        printf("Option p was provided\n");
				opt_curl = opt;
				break;				
			case 'd':		//  -d/  --delete
        printf("Option d was provided\n");
				opt_curl = opt;
				break;				
			case 'h':  //  -h/  -- help
        printf("Option h was provided\n");
				opt_curl = opt;
				break;
			case '?':
				printf("Unknown option: %c\n", optopt);	
				break;			
			case ':':
				printf("Missing arg for %c\n", optopt);
				break;
			default:
				printf("Options required %c\n", optopt);
				break;
		}
	if(x == 1){
 //   printf("in if statement\n");
	  opt_test = opt;
  }
//	printf("x before increment = %d\n", x);
  x = x + 1;
//  printf("x after increment = %d\n", x);
//  printf("opt_test in while loop %d\n", opt_test);
	}
 //    	printf("left while loop: \n");

	switch (opt_test)
  {
    case 'g':
    	printf("CASE GET URL: \n");
  		if (curl) {
		  	printf("Curl for Get url for: %s\n", url); 
				curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
				curl_easy_setopt(curl, CURLOPT_URL, url);
	 			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	 			res = curl_easy_perform(curl);
				printf("I got here in GET\n"); 
	 			if(res != CURLE_OK) {
	  			fprintf(stderr, "curl_easy_perform() failed GET: %s\n",
									curl_easy_strerror(res));
	   		}	
		 		curl_easy_cleanup(curl);
 	   } else {
		 return INIT_ERR;
 	 	 } 
	   return OK;
		 break;

  	case 'o':
    	printf("CASE POST to URL: \n");
  		if (curl) {
				printf("Curl for POST to url %s\n", url); 
				curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
				curl_easy_setopt(curl, CURLOPT_URL, url);
	 			curl_easy_setopt(curl, CURLOPT_POST, 1);			
	 			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "This POST is 26 characters");
	 			res = curl_easy_perform(curl);
				printf("I got here in POST\n"); 
	 			if(res != CURLE_OK) {
	  			fprintf(stderr, "curl_easy_perform() failed POST: %s\n",
									curl_easy_strerror(res));
  			}	
	 			curl_easy_cleanup(curl);
   		} else {
			return INIT_ERR;
 	 		} 
	  	return OK; 
		  break;

  	case 'p':
    	printf("CASE PUT to URL: \n");
	 		if (curl) {
				printf("Curl for PUT to url %s\n", url); 
				curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
				curl_easy_setopt(curl, CURLOPT_URL, url);
				curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
	 			res = curl_easy_perform(curl);
				printf("I got here in PUT\n"); 
	 			if(res != CURLE_OK) {
	  			fprintf(stderr, "curl_easy_perform() failed PUT: %s\n",
									curl_easy_strerror(res));
  			}	
	 			curl_easy_cleanup(curl);
   		} else {
			return INIT_ERR;
 	 		} 
	  	return OK; 
		  break;

  	case 'd':
    	printf("CASE DELETE to URL: \n");
	 		if (curl) {
				printf("Curl for DELETE to url %s\n", url); 
				curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
				curl_easy_setopt(curl, CURLOPT_URL, url);
				curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
	 			res = curl_easy_perform(curl);
				printf("I got here in DELETE\n"); 
	 			if(res != CURLE_OK) {
	  			fprintf(stderr, "curl_easy_perform() failed DELETE: %s\n",
									curl_easy_strerror(res));
  			}	
	 			curl_easy_cleanup(curl);
   		} else {
			return INIT_ERR;
 	 		} 
	  	return OK; 
		  break;

  	case 'h':
    	printf("CASE HELP to URL: \n");
	 		if (curl) {
				printf("test usage \n"); 
				printf("options -g GET \n"); 
				printf("options -o POST \n");
				printf("options -p PUT \n");
				printf("options -d DELETE \n");
 				printf("options -u URL followed by url \n");
				printf("example test -p -u www.webpage.com\n");
	 			curl_easy_cleanup(curl);
   		} else {
			return INIT_ERR;
 	 		} 
	  	return OK; 
		  break;
	}
}		

