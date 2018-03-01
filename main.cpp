
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
#include <stdlib.h> 
#include <unistd.h>
#include <dirent.h>


#define URL "https://whattomine.com/coins.json"

using namespace std;
static char err_buffer[CURL_ERROR_SIZE];
char *buffer;
#define  sleep 600000000
#define fee  120000000
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
            buffer = 0;
            CURL *curl = NULL;
            CURLcode curl_res;
            string mineThat;
            
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
                if(mineThat == "EquihashZCL")
                {
                    EquihashZCL(username);
                }
                if(mineThat == "EquihashZEC")
                {
                    EquihashZEC(username);
                }
                if(mineThat == "CryptoNightETN")
                {
                    CryptoNightETN(username);
                }
                if(mineThat == "Lyra2REv2MONA")
                {
                    Lyra2REv2MONA(username);
                }
                if(mineThat == "EthashEXP")
                {
                    EthashEXP(username);
                }
                if(mineThat == "EthashETC")
                {
                    EthashETC(username);
                }
                if(mineThat == "EthashMUSIC")
                {
                    EthashMUSIC(username);
                }
                if(mineThat == "CryptoNightXMR")
                {
                    CryptoNightXMR(username);
                }
                

            } 
        }
        void CryptoNightXMR(const char *username)
        {
            char *command;
            if(checkDir("./ccminer/"))
            {
                system(" gnome-terminal -e \"timeout -k 3m 2m ./ccminer/ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20580 -u Fokmen.OMQL-Miner -p x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./ccminer/ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20580 -u czupryn888.OMQL-Miner -p x\"");
                usleep(sleep);   
            }
            else
            {
                cout<<"ccminer miner not found. I'll try to download it... \n";
                system("./installers/ccminer.sh");
            }
        }
        
        void EthashMUSIC(const char *username)
        {
            char *command;
            if(checkDir("./ethminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20585 -O Fokmen.OMQL-Miner:x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20585 -O czupryn888.OMQL-Miner:x\"");
                usleep(sleep);
    
            }
            else
            {
                cout<<"ethminer not found. I'll try to download it... \n";
                system("./installers/ethminer.sh");
            }            
        }
        
        void EthashETC(const char *username)
        {
            char *command;
            if(checkDir("./ethminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20555 -O Fokmen.OMQL-Miner:x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20555 -O czupryn888.OMQL-Miner:x\"");
                usleep(sleep);
            }
            else
            {
                cout<<"ethminer not found. I'll try to download it... \n";
                system("./installers/ethminer.sh");
            }    
        }
        
        void EthashEXP(const char *username)
        {
            char *command;
            if(checkDir("./ethminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20565 -O Fokmen.OMQL-Miner:x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20565 -O czupryn888.OMQL-Miner:x\"");
                usleep(sleep);
            }
            else
            {
                cout<<"ethminer not found. I'll try to download it... \n";
                system("./installers/ethminer.sh");
            } 
        }
            
        void Lyra2REv2MONA(const char *username)
        {
            char *command;
            if(checkDir("./ccminer-lyra/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./ccminer-lyra/ccminer -a cryptonight -o stratum+tcp://hub.miningpoolhub.com:20593 -u Fokmen.OMQL-Miner -p x -i 20\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./ccminer-lyra/ccminer -a cryptonight -o stratum+tcp://hub.miningpoolhub.com:20593 -u czupryn888.OMQL-Miner -p x -i 20\"");
                usleep(sleep);
            }
            else
            {
                cout<<"ccminer-lyra miner not found. I'll try to download it... \n";
                system("./installers/lyra.sh");
            }
        }
        void CryptoNightETN(const char *username)
        {
            char *command;
            if(checkDir("./ccminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./ccminer/ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20596 -u Fokmen.OMQL-Miner -p x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./ccminer/ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20596 -u czupryn888.OMQL-Miner -p x\"");
                usleep(sleep);
            }
            else
            {
                cout<<"ccminer miner not found. I'll try to download it... \n";
                system("./installers/ccminer.sh");
            }
        }
        void NeoScryptFTC(const char *username)
        {
            char *command;
            if(checkDir("./ccminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./ccminer/ccminer -a neoscrypt -o stratum+tcp://hub.miningpoolhub.com:20510 -u Fokmen.OMQL-Miner -p x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./ccminer/ccminer -a neoscrypt -o stratum+tcp://hub.miningpoolhub.com:20510 -u czupryn888.OMQL-Miner -p x\"");
                usleep(sleep);
            }
            else
            {
                cout<<"ccminer not found. I'll try to download it... \n";
                system("./installers/ccminer.sh");
            }
        }
        
        void EthashETH(const char *username)
        {
            char *command;
            if(checkDir("./ethminer/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20535 -O Fokmen.OMQL-Miner:x\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ethminer -G -S europe.ethash-hub.miningpoolhub.com:20535 -O czupryn888.OMQL-Miner:x\"");
                usleep(sleep);
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
            if(checkDir("./equihash/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user Fokmen.OMQL-Miner --pass z --port 20595\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user czupryn888.OMQL-Miner --pass z --port 20595\"");
                usleep(sleep);
            }
            else
            {
                cout<<"Equihash miner not found. I'll try to download it... \n";
                system("./installers/equihash.sh");
            }
        }
        
        void EquihashZEN(const char *username)
        {  
            char *command;
            if(checkDir("./equihash/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user Fokmen.OMQL-Miner --pass z --port 20594\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user czupryn888.OMQL-Miner --pass z --port 20594\"");
                usleep(sleep);
            }
            else
            {
                 cout<<"Equihash miner not found. I'll try to download it... \n";
                system("./installers/equihash.sh");
            }              
        }
         void EquihashZCL(const char *username)
        {  
            char *command;
            if(checkDir("./equihash/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user Fokmen.OMQL-Miner --pass z --port 20575\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user czupryn888.OMQL-Miner --pass z --port 20575\"");
                usleep(sleep);
            }
            else
            {
                cout<<"Equihash miner not found. I'll try to download it... \n";
                system("./installers/equihash.sh");
            }              
        } 
        void EquihashZEC(const char *username)
        {
            char *command;
            if(checkDir("./equihash/"))
            {
                system("gnome-terminal -e \"timeout -k 3m 2m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user Fokmen.OMQL-Miner --pass z --port 2070\"");
                usleep(fee);
                system("gnome-terminal -e \"timeout -k 15m 10m ./equihash/miner --server europe.equihash-hub.miningpoolhub.com --user czupryn888.OMQL-Miner --pass z --port 2070\"");
                usleep(sleep);
            }
            else
            {
                 cout<<"Equihash miner not found. I'll try to download it... \n";
                system("./installers/equihash.sh");
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
        
        void getJSON(CURL *&curl, CURLcode res)
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
                
            }
            
                    
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
                        && what != "CryptoNightETN"              
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
