
/* 
 * File:   main.cpp
 * Author: omql
 *
 * Created on December 16, 2017, 12:39 PM
 */

#include <cstdlib>
#include <string>
#include <string.h>
#include <curl/curl.h>
#include <iostream>
#include <jansson.h>
#include <stdlib.h> 
#include <unistd.h>
#include <dirent.h>


#define URL "https://whattomine.com/coins.json"

using namespace std;
static char err_buffer[CURL_ERROR_SIZE];
char *buffer;

class coin
{
    public:
        string          tag;
        string          algorithm;
        string          profitability;
};

class miner
{
    public:

        miner(char *username)
        {
            
            CURL *curl = NULL;
            CURLcode curl_res;
            string mineThat;
            const char *output;
            while(true)
            {
                if(!this->init(curl))
                {
                    exit(EXIT_FAILURE);
                }
           
                this->getJSON(curl, curl_res);
                mineThat = createCoins();
              
                cout <<"Most profitable algorithm is: " <<mineThat<<"\n";
                if(mineThat == "NeoScryptFTC")
                {
                    NeoScryptFTC(username);
                   
                }
                if(mineThat == "EthashETH")
                {
                    EthashETH(username);
                }
                if(mineThat == "EquihashBTG")
                {
                    EquihashBTG(username);
                }
                if(mineThat == "EquihashZEN")
                {
                    EquihashZEN(username);
                }
                
            } 
        }

        void NeoScryptFTC(const char *username)
        {
            char *command;
            if(checkDir("./ccminer/ccminer"))
            {
                command = strcpy("./ccminer/ccminer -a neoscrypt -o stratum+tcp://hub.miningpoolhub.com:20510 -u ",  username);
                command = strcpy(command, ".OMQL-Miner -p x");
                system(command);
                usleep(300000000);
            }
            else
            {
                cout<<"ccminer not found. I'll try to download it... \n";
                system("git clone https://github.com/tpruvot/ccminer.git");
                system("chmod -R 777 ccminer");
                system("./installers/ccminer.sh");
            }
        }
        
        void EthashETH(const char *username)
        {
            char *command;
            if(checkDir("./ethminer/ethminer"))
            {
                command = strcpy("./ethminer/ethminer -G -S europe.ethash-hub.miningpoolhub.com:20535 -O ",  username);
                command = strcpy(command, ".OMQL-Miner:x");
                system(command);
                usleep(300000000);
            }
            else
            {
                cout<<"ethminer not found. I'll try to download it... \n";

                system("./installers/ethminer.sh");
            }            
            
        }
        
        void EquihashBTG(const char *username)
        {
            char *command;
            if(checkDir("./silentarmy/silentarmy"))
            {
                command = strcpy("./silentarmy/silentarmy --use 0 -c stratum+tcp://europe.equihash-hub.miningpoolhub.com:20595 -u ",  username);
                command = strcpy(command, ".OMQL-Miner -p x");
                system(command);
                usleep(300000000);
            }
            else
            {
                cout<<"Silentarmy not found. I'll try to download it... \n";
                system("./installers/silentarmy.sh");
            }

        }
        
        void EquihashZEN(const char *username)
        {  
            char *command;
            if(checkDir("./silentarmy/silentarmy"))
            {
                command = strcpy("./silentarmy/silentarmy --use 0 -c stratum+tcp://europe.equihash-hub.miningpoolhub.com:20594 -u ",  username);
                command = strcpy(command, ".OMQL-Miner -p x");
                system(command);
                usleep(300000000);
            }
            else
            {
                cout<<"Silentarmy not found. I'll try to download it... \n";
                system("./installers/silentarmy.sh");
            }              
        }

        bool checkDir(const char* path)
        {
            if(path == NULL) return false;
            DIR *dir;
            dir = opendir(path);
            if(dir != NULL)
            {
                closedir(dir);
                return true;
            }
            return false;
        }
        bool init(CURL *&curl)
        {

            CURLcode res;
            curl = curl_easy_init();
            if(curl == NULL)
            {
                printf("Error 1");
                return false;
            }
            res = curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buffer);
            if(res != CURLE_OK)
            {
                printf("Error 2");
                return false;
            }
            res = curl_easy_setopt(curl, CURLOPT_URL, URL);
            if(res != CURLE_OK)
            {
                printf("Error 3");
                return false;
            }     
            res = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            if(res != CURLE_OK)
            {
                printf("Error 4");
                return false;
            }  
            res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
            if(res != CURLE_OK)
            {
                printf("Error 5");
                return false;
            }  
            res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            if(res != CURLE_OK)
            {
                printf("Error 6");
                return false;
            }  
            return true;
        }
        
        static int writer(char *data, size_t size, size_t nmemb, string *writerData)
        {
            if(writerData == NULL)
            {
                return 0;
            }
            writerData->append(data, size*nmemb);
            return size * nmemb;
        }
        
        char getJSON(CURL *&curl, CURLcode res)
        {
            printf("Retrieving data... ");
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if(res != CURLE_OK)
            {
                printf("Error 7");
                exit(EXIT_FAILURE);
            }
            else
            {
                printf("OK\n");
                return *buffer;
            }
            printf("Error 8");
                    
        }
        string createCoins()
        {
            string data;
            coin coins[37];
            int pointer = 0;
            int coin_nr = 0;
            data = buffer;
            while(coin_nr < 37)
            {
                pointer = 0;
                pointer = data.find("tag", pointer) + 6;
                while(data[pointer] != '\"')
                {
                    coins[coin_nr].tag = coins[coin_nr].tag + data[pointer];
                    pointer++;
                }
                //cout<< coins[coin_nr].tag<<" ";
                pointer = data.find("algorithm", pointer) + 12;
                while(data[pointer] != '\"')
                {
                    coins[coin_nr].algorithm = coins[coin_nr].algorithm + data[pointer];
                    pointer++;
                }
                //cout<< coins[coin_nr].algorithm<<" ";
                pointer = data.find("profitability", pointer) + 15;
                while(data[pointer] != ',')
                {
                    coins[coin_nr].profitability = coins[coin_nr].profitability + data[pointer];
                    pointer++;
                }    
                //cout<< coins[coin_nr].profitability<<"\n";
                data.erase(data.begin(), data.begin()+pointer);
                coin_nr++;
            }
            int highest = 0;
            string mine;
            string what;
            for(int x = 0; x < 37; x++)
            {
                what = coins[x].algorithm + coins[x].tag;
                if(atoi(coins[x].profitability.c_str()) > highest
                        && what != "EthashPIRL"
                        && what != "EthashETP" 
                        && what != "NeoScryptVIVO"
                        && what != "EthashUBQ"
                        && what != "NeoScryptTZC"
                        && what != "CryptoNightBCN"
                        && what != "X11GostSIB"
                        && what != "CryptoNightKRB"
                        && what != "CryptoNightSUMO"
                        && what != "EquihashKMD"
                        && what != "PascalPASC"
                        && what != "EquihashHUSH"
                        && what != "SkunkhashALTCOM"
                        && what != "EthashSOIL"
                        && what != "Blake (14r)DCR"
                        && what != "NeoScryptORB"
                        && what != "Blake (2b)SC"
                        && what != "Myriad-GroestlDGB"
                        && what != "CryptoNightXDN"                       
                        ) 
                {
                    highest = atoi(coins[x].profitability.c_str());
                    mine = coins[x].algorithm + coins[x].tag;
                }
            }
            return mine;
        }
};

int main(int argc, char** argv) {
    miner* miner1 = new miner(argv[0]);
    return 0;
}

