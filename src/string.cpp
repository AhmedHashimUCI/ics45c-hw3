#include "string.hpp"
#include <iosfwd>
#include <iostream>


String::String(const char *s){

	if(s == nullptr){
		s = "";
	}
	strncpy(buf, s, MAXLEN-1);

}

String::String(const String &s){
	strcpy(buf, s.buf);

}

String &String::operator=(const String &s){

	if(this !=&s){

		strcpy(buf, s.buf);
		
	}

	return *this;
}



char &String::operator[](int index){

	if(in_bounds(index)){

		return buf[index];
	}else if(!in_bounds(index)){
	std::cerr << "ERROR: Index Out Of Bounds" << std::endl;	
	return buf[0];

	}
	return buf[index];
}

int String::size() const{
	
	return strlen(buf);

}







void String::print(std::ostream & out) const{
	
	out << buf;

}

void String::read(std::istream &in){
	int index = 0;
	char c;
	in >> std::ws;

	for (int i =0; in.get(c); ++i){
	
	 if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f') {
        in.unget();
        break;
    }

	if (i < MAXLEN -1){
	
		buf[index++] = c;

	}

}

buf[index] = '\0';

}

String String::reverse() const{
	String result;
	reverse_cpy(result.buf, buf);
	return result;
}


int String::indexOf(char c) const{


	const char *cha = strchr(buf, c);
	if (cha != nullptr){
		return cha - buf;
	}else{
	std:: cerr << "Error: Character is not found or out of bound" << std::endl;
	return -1;
		}
	}
		
int String::indexOf(const String &s) const{

	const char *cha = strstr(buf, s.buf);

	if (cha != nullptr){
		return cha - buf;
	}else{
	std::cerr << "Error, Index out of bound" << std::endl;
	return -1;
	}
}		
	

String &String::operator +=(const String &s){
	
	if (this == &s){
	if(size()/2 >512){
		std::cerr << "ERROR: String Capacity Exceeded"<< std::endl;
		return *this;
	}
	String copy(s);
	return *this +=copy;
	}
	
	const int first = size();
	const int incoming = s.size();

	if (incoming > (MAXLEN - 1) - first){
        std::cerr << "ERROR: String Capacity Exceeded" << std::endl;
		return *this;
		}
    strncat(buf, s.buf, (MAXLEN - 1) - first);
    return *this;

}


String String::operator+(const String &s) const{
	String orignal(*this);
	orignal += s;
	return orignal;
}


bool String::operator ==(const String &s) const{

	return strcmp(buf, s.buf) == 0;

}

bool String::operator !=(const String &s) const{

	return strcmp(buf, s.buf) != 0;
}

bool String::operator >(const String &s) const {

	return strcmp(buf, s.buf) > 0;
}

bool String::operator <(const String &s) const{

	return strcmp(buf, s.buf) < 0;

}

bool String::operator <=(const String &s) const{

	return strcmp(buf, s.buf) <= 0;
}

bool String::operator >=(const String &s) const{

	return strcmp(buf, s.buf) >= 0;
}



String::~String(){}


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

	int len = 0;
	while(dest[len] != '\0'){
		++len;
	}
	
	int add = 0;
	for (int i = 0; src[i] != '\0'; ++i){

		dest[len + i] = src[i];
		add = i;
	}

	dest[len + add+1] = '\0';
	return dest;

}

char * String::strncat(char *dest, const char * src, int n){
	
	int len = 0;
	for (int i =0; dest[i] != '\0'; ++i){
	++len;
	}
	
	int add = 0;
	for (int i = 0; i < n && src[i] != '\0'; ++i){

		dest[len + i] = src[i];
		add = i;
	}

	dest[len + add+1] = '\0';
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
            return left[i] - right[i];
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

const char * String::strchr(const char *str, char c){
	

	for (int i = 0; ; ++i){

		if (str[i] == c){
			return &str[i];

		}

		if(str[i] == '\0'){
			break;
		}

	}
	return nullptr;
}


const char* String::strstr(const char *haystack, const char *needle){

	if(needle[0] == '\0'){

		return haystack;
	}

	for(int i =0; haystack[i] != '\0'; ++i){
		if (strncmp(&haystack[i], needle, strlen(needle)) ==0){
			return &haystack[i];
		}
	
	}
	return nullptr;

}

std::ostream &operator<<(std::ostream &out, const String &s){

	s.print(out);
	return out;

}

std::istream &operator>>(std::istream &in, String &s){
	s.read(in);
	return in;

}
