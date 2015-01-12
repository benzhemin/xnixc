#include <stdio.h>
#include <curl/curl.h>

int main(void){
    CURL *curl;
    CURLcode res;

    cur = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "www.baidu.com");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK){

        }
    }
}
