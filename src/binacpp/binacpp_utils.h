

#ifndef BINACPP_UTILS
#define BINACPP_UTILS

#include <io.h>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>
#include <chrono>
#include <openssl/hmac.h>
#include <openssl/sha.h>
#include <iostream>

void split_string( std::string &s, char delim, std::vector <std::string> &result);
bool replace_string(std::string& str, const char *from, const char *to);
int replace_string_once(std::string& str, const char *from, const char *to , int offset);


std::string b2a_hex( char *byte_arr, int n );
int64_t get_current_epoch();
uint64_t get_current_ms_epoch();


//--------------------
inline bool file_exists (const std::string& name) {
	return ( _access_s( name.c_str(), 0x00 ) == 0 );
}

std::string hmac_sha256( const char *key, const char *data);
std::string sha256( const char *data );
void string_toupper(std::string &src);
std::string string_toupper( const char *cstr );

#endif
