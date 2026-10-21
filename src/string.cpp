#include "string.hpp"
#include <iosfwd>


String::String(const char *s){

	if(s == nullptr){
		s = "";
	}
	strncpy(buf, s, MAXLEN-1);

}

String::String(const String &s){
	strcpy(buf, s.buf);

}


//HELPERS

int String::strlen(const char *s){
	
	int len = 0;
	for(int i = 0; s[i] != '\0'; ++i){
		++len;
	}

	return len;
}


char * String::strcpy(char *dest, const char *src){
	
	int l = 0;
	for(int i = 0; src[i] != '\0'; ++i){
		
		dest[i] = src[i];
		++l;
	}
	dest[l] = '\0';
	return dest;

}

char * String::strncpy(char * dest, const char* src, int n){
	int i = 0;
	for(;i<n && src[i] !='\0'; ++i ){
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return dest;

}

char * String::strcat(char * dest,const char* src){

	strcpy(dest + strlen(dest), src);
	return dest;

}

char * String::strncat(char *dest, const char * src, int n){

	strncpy(dest + strlen(dest), src, n);
	return dest;

}


