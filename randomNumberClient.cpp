#include <iostream>
#include <string>
#include <curl/curl.h>

size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* s) {
	size_t total = size * nmemb;

	s->append((char*)contents, total);
	return total;

}


int main(){
	CURL* curl = curl_easy_init();
	if(!curl) return 1;


	std::string response;



	curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8081");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

	while(1){

	CURLcode res = curl_easy_perform(curl);


	if (res == CURLE_OK) {

		std::cout << "Server response: " << response << "\n";
	} else {
		std::cerr << "Error: " <<curl_easy_strerror(res) << "\n";
	}

}
	curl_easy_cleanup(curl);
	return 0;


}
