
/*
	Author: tensaix2j
	Date  : 2017/10/15
	
	C++ library for Binance API.
*/


#ifndef BINACPP_H
#define BINACPP_H


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <exception>

#include <curl/curl.h>
#include <nlohmann/json.hpp>



#define BINANCE_HOST "https://api.binance.com"


class BinaCPP {

	static std::string api_key;
	static std::string secret_key;
	static CURL* curl;

	

	public:

		

		static void curl_api(std::string &url, std::string &result_json );
		static void curl_api_with_header(std::string &url, std::string &result_json , std::vector <std::string> &extra_http_header, std::string &post_data, std::string &action );
		static size_t curl_cb( void *content, size_t size, size_t nmemb, std::string *buffer ) ;
		
		static void init(std::string &api_key, std::string &secret_key);
		static void cleanup();


		// Public API
		static void get_serverTime( nlohmann::json &json_result); 	

		static void get_allPrices( nlohmann::json &json_result );
		static double get_price( const char *symbol );

		static void get_allBookTickers( nlohmann::json &json_result );
		static void get_bookTicker( const char *symbol, nlohmann::json &json_result ) ;

		static void get_depth( const char *symbol, int limit, nlohmann::json &json_result );
		static void get_aggTrades( const char *symbol, int fromId, time_t startTime, time_t endTime, int limit, nlohmann::json &json_result ); 
		static void get_24hr( const char *symbol, nlohmann::json &json_result ); 
		static void get_klines( const char *symbol, const char *interval, int limit, time_t startTime, time_t endTime,  nlohmann::json &json_result );


		// API + Secret keys required
		static void get_account( long recvWindow , nlohmann::json &json_result );
		
		static void get_myTrades( 
			const char *symbol, 
			int limit,
			long fromId,
			long recvWindow, 
			nlohmann::json &json_result 
		);
		
		static void get_openOrders(  
			const char *symbol, 
			long recvWindow,   
			nlohmann::json &json_result 
		) ;
		

		static void get_allOrders(   
			const char *symbol, 
			long orderId,
			int limit,
			long recvWindow,
			nlohmann::json &json_result 
		);


		static void send_order( 
			const char *symbol, 
			const char *side,
			const char *type,
			const char *timeInForce,
			double quantity,
			double price,
			const char *newClientOrderId,
			double stopPrice,
			double icebergQty,
			long recvWindow,
			nlohmann::json &json_result ) ;


		static void get_order( 
			const char *symbol, 
			long orderId,
			const char *origClientOrderId,
			long recvWindow,
			nlohmann::json &json_result ); 


		static void cancel_order( 
			const char *symbol, 
			long orderId,
			const char *origClientOrderId,
			const char *newClientOrderId,
			long recvWindow,
			nlohmann::json &json_result 
		);

		// API key required
		static void start_userDataStream( nlohmann::json &json_result );
		static void keep_userDataStream( const char *listenKey  );
		static void close_userDataStream( const char *listenKey );


		// WAPI
		static void withdraw( 
			const char *asset,
			const char *address,
			const char *addressTag,
			double amount, 
			const char *name,
			long recvWindow,
			nlohmann::json &json_result );

		static void get_depositHistory( 
			const char *asset,
			int  status,
			long startTime,
			long endTime, 
			long recvWindow,
			nlohmann::json &json_result );

		static void get_withdrawHistory( 
			const char *asset,
			int  status,
			long startTime,
			long endTime, 
			long recvWindow,
			nlohmann::json &json_result ); 

		static void get_depositAddress( 
			const char *asset,
			long recvWindow,
			nlohmann::json &json_result );


};


#endif
