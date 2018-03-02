
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
#include <fstream>
#include <sys/stat.h>
#include <sstream>


#define URL "https://whattomine.com/coins.json"

using namespace std;
static char err_buffer[CURL_ERROR_SIZE];
char *buffer;
#define  sleep 600000000
#define fee    180000000

template<typename T>
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

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
        miner()
        {
            buffer = 0;
            CURL *curl = NULL;
            CURLcode curl_res;
            string mineThat;
            string username;
            string pool;

            while(true)
            {
                if(!this->init(curl))
                {
                    exit(EXIT_FAILURE);
                }
		this->getJSON(curl, curl_res);
		mineThat = this->createCoins();

		cout <<"Most profitable coin is: " <<mineThat<<"\n";
		if(mineThat == "FTC")
		{
		    this->mineFTC();   
		}
		if(mineThat == "ETH")
		{
		    this->mineETH();
		}
		if(mineThat == "BTG")
		{
		    this->mineBTG();
		}
		if(mineThat == "ZEN")
		{
		    this->mineZEN();
		}
		if(mineThat == "ZCL")
		{
		    this->mineZCL();
		}
		if(mineThat == "ZEC")
		{
		    this->mineZEC();
		}
		if(mineThat == "ETN")
		{
		    this->mineETN();
		}
		if(mineThat == "MONA")
		{
		    this->mineMONA();
		}
		if(mineThat == "EXP")
		{
		    this->mineEXP();
		}
		if(mineThat == "ETC")
		{
		    this->mineETC();
		}
		if(mineThat == "MUSIC")
		{
		    this->mineMUSIC();
		}
		if(mineThat == "XMR")
		{
		    this->mineXMR();
		}
	    }
        }
        

        void mineXMR()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ccminer"))
            {
                command_fee = " gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m ./ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20580 -u Fokmen.OMQL-Miner -p x\"";
		const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ccminer -a cryptonight -o stratum+tcp://"+getPool("XMR")+" -u "+getUsername("XMR")+".OMQL-Miner -p x\"";
		const char* comm = command.c_str();
                system(comm);
                usleep(sleep);   
            }
            else
            {
                system("./firstrun.sh");
            }
        }
        
        void mineMUSIC()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ethdcrminer64"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./ethdcrminer64 -epool europe.ethash-hub.miningpoolhub.com:20585 -ewal Fokmen.OMQL_Miner -eworker Fokmen.OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://dcr.coinmine.pl:2222 -dwal DscozcMjuWLRSBDaiKV8pzpvvrj3kgzviog.OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ethdcrminer64 -epool "+getPool("MUSIC")+" -ewal "+getUsername("MUSIC")+".OMQL_Miner -eworker "+getUsername("MUSIC")+".OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://"+getPool("DCR")+" -dwal "+getUsername("DCR")+".OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }            
        }
        
        void mineETC()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ethdcrminer64"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./ethdcrminer64 -epool europe.ethash-hub.miningpoolhub.com:20555 -ewal Fokmen.OMQL_Miner -eworker Fokmen.OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://dcr.coinmine.pl:2222 -dwal DscozcMjuWLRSBDaiKV8pzpvvrj3kgzviog.OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
		command = "gnome-terminal -e \"timeout -k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ethdcrminer64 -epool "+getPool("ETC")+" -ewal "+getUsername("ETC")+".OMQL_Miner -eworker "+getUsername("ETC")+".OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://"+getPool("DCR")+" -dwal "+getUsername("DCR")+".OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }    
        }
        
        void mineEXP()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ethdcrminer64"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./ethdcrminer64 -epool europe.ethash-hub.miningpoolhub.com:20565 -ewal Fokmen.OMQL_Miner -eworker Fokmen.OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://dcr.coinmine.pl:2222 -dwal DscozcMjuWLRSBDaiKV8pzpvvrj3kgzviog.OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ethdcrminer64 -epool "+getPool("EXP")+" -ewal "+getUsername("EXP")+".OMQL_Miner -eworker "+getUsername("EXP")+".OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://"+getPool("DCR")+" -dwal "+getUsername("DCR")+".OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            } 
        }
            
        void mineMONA()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ccminer"))
            {
                command_fee = " gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m ./ccminer -a Lyra2REv2 -o stratum+tcp://hub.miningpoolhub.com:205930 -u Fokmen.OMQL-Miner -p x\"";
		const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout --k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ccminer -a Lyra2REv2 -o stratum+tcp://"+getPool("MONA")+" -u "+getUsername("MONA")+".OMQL-Miner -p x\"";
		const char* comm = command.c_str();
                system(comm);
                usleep(sleep); 
            }
            else
            {
                system("./firstrun.sh");
            }
        }
        void mineETN()
         {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ccminer"))
            {
                command_fee = " gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m ./ccminer -a cryptonight -o stratum+tcp://europe.cryptonight-hub.miningpoolhub.com:20596 -u Fokmen.OMQL-Miner -p x\"";
		const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout --k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ccminer -a cryptonight -o stratum+tcp://"+getPool("ETN")+" -u "+getUsername("ETN")+".OMQL-Miner -p x\"";
		const char* comm = command.c_str();
                system(comm);
                usleep(sleep); 
            }
            else
            {
                system("./firstrun.sh");
            }
        }
        void mineFTC()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ccminer"))
            {
                command_fee = " gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m ./ccminer -a neoscrypt -o stratum+tcp://hub.miningpoolhub.com:20510 -u Fokmen.OMQL-Miner -p x\"";
		const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout --k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ccminer -a neoscrypt -o stratum+tcp://"+getPool("FTC")+" -u "+getUsername("FTC")+".OMQL-Miner -p x\"";
		const char* comm = command.c_str();
                system(comm);
                usleep(sleep); 
            }
            else
            {
                system("./firstrun.sh");
            }
        }
        void mineETH()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./ethdcrminer64"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./ethdcrminer64 -epool europe.ethash-hub.miningpoolhub.com:17020 -ewal Fokmen.OMQL_Miner -eworker Fokmen.OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://dcr.coinmine.pl:2222 -dwal DscozcMjuWLRSBDaiKV8pzpvvrj3kgzviog.OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout+2)+"m "+to_string(timeout)+"m  ./ethdcrminer64 -epool "+getPool("ETH")+" -ewal "+getUsername("ETH")+".OMQL_Miner -eworker "+getUsername("ETH")+".OMQL_Miner -esm 2 -epsw x -allcoins 1 -dpool stratum+tcp://"+getPool("DCR")+" -dwal "+getUsername("DCR")+".OMQL_Miner -dpsw x -dcoin dcr\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);

            }
            else
            {
                system("./firstrun.sh");
            }   
        } 
        void mineBTG()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./bminer"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://Fokmen.OMQL-Miner@us-east.equihash-hub.miningpoolhub.com:20595\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://"+getUsername("BTG")+".OMQL-Miner@"+getPool("BTG")+"\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }   
        }
        void mineZEN()
        {      
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./bminer"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://Fokmen.OMQL-Miner@us-east.equihash-hub.miningpoolhub.com:20594\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://"+getUsername("ZEN")+".OMQL-Miner@"+getPool("ZEN")+"\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }   
        }
        void mineZCL()
        {  
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./bminer"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://Fokmen.OMQL-Miner@us-east.equihash-hub.miningpoolhub.com:20575\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://"+getUsername("ZCL")+".OMQL-Miner@"+getPool("ZCL")+"\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }   
        }
        void mineZEC()
        {
            string command;
            string command_fee;
            double timeout_fee = fee / 60000000;
            double timeout = sleep / 60000000;
            if(checkDir("./bminer"))
            {
                command_fee = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://Fokmen.OMQL-Miner@us-east.equihash-hub.miningpoolhub.com:20570\" && exit";
                const char* comm_fee = command_fee.c_str();
                system(comm_fee);
                usleep(fee);
                command = "gnome-terminal -e \"timeout -k "+to_string(timeout_fee+2)+"m "+to_string(timeout_fee)+"m  ./bminer -uri stratum+ssl://"+getUsername("ZEC")+".OMQL-Miner@"+getPool("ZEC")+"\" && exit";
                const char* comm = command.c_str();
                system(comm);
                usleep(sleep);
            }
            else
            {
                system("./firstrun.sh");
            }   
        }
        bool checkDir(const string path)
        {
            struct stat buffer;
            return (stat(path.c_str(), &buffer) == 0);
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
			            && what != "CryptoNightDCY"   
                        && what != "EthashELLA"          
                        ) 
                {
                    highest = atoi(coins[x].profitability.c_str());
                    mine =  coins[x].tag;
                }
            }
            return mine;
        }
        string getUsername(string algo)
        {
            ifstream names;
            string user;
            names.open("users.txt");
            while(getline(names, user))
            {
                if(user.find(algo, 0))
                {
                    user.erase(0, 5);
                    names.close();
                    return user;
		}
            }
	}
        string getPool(string algo)
        {
            ifstream pools;
            string pool;
            pools.open("pools.txt");
            while(getline(pools, pool))
            {
                if(pool.find(algo) != -1)
                {

                    pool.erase(0, 6);
                    pools.close();
                    return pool;
		}
            }
        }
};

int main(int argc, char** argv) {
    miner* miner1 = new miner();
    return 0;
}
