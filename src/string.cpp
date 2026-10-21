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

int String::strcmp(const char *left, const char * right){
	int num = 0;
	for (int i = 0; left[i] != '\0' && left[i] == right[i]; ++i){
		++num;
	}
	int boolean = left[num] - right[num];
	return boolean;
}

int String::strncmp(const char *left, const char * right, int n){
	
	for (int i = 0; i < n; ++i) {
        if (left[i] != right[i]) {
            return static_cast<unsigned char>(left[i]) - static_cast<unsigned char>(right[i]);
        }
        if (left[i] == '\0') {
            return 0;
        }
    }
    return 0;
}


void String::reverse_cpy(char * dest, const char *src){

	int len = strlen(src) -1;
    for (int i = 0; i <= len; ++i){
	dest[i] = src[len-i];
	}

    dest[len+1] = '\0';

}

