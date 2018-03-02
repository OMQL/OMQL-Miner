# OMQL-Miner
<h1>Multi pool miner for Linux x64 & NVIDIA</h1>
<h1>Features:</h1>

- Algorithm switching based on highest profitability on whattomine.com;

- Supported altcoins: ETH, ETC, FTC, BTG, ZEN, ZCL, ZEC, ETN, MONA, EXP, MUSIC;

- 100% open source;

- 5% dev fee;

- Tested on Ubuntu 16.04 LTS;

<h1>Installing:</h1>
 <code>git clone https://github.com/OMQL/OMQL-Miner.git</code>
 
 <code>  cd OMQL-Miner</code><br>
 <code> g++ main.cpp -o omql_miner -lcurl</code>
  <h1>
 Config:</h1>
 OMQL Miner has two configuration files: users.txt and pools.txt<br>
 In users.txt you must specify your wallet addresses or username. Example:

ETH:  Fokmen<br>
ETC:  Fokmen<br>
FTC:  Fokmen<br>
BTG:  Fokmen<br>
ZEN:  Fokmen<br>
ZCL:  Fokmen<br>
ZEC:  Fokmen<br>
ETN:  Fokmen<br>
MONA: Fokmen<br>
EXP:  Fokmen<br>
MUSIC:Fokmen<br>
DCR: DscozcMjuWLRSBDaiKV8pzpvvrj3kgzviog<br>

 <br>
 Remember: there must always be six characters before the username or wallet address (including spaces and ":")<br><br>
 In pools.txt you must specify pools for mining, as example:

 
ETH:  europe.ethash-hub.miningpoolhub.com:17020<br>
DCR:  dcr.coinmine.pl:2222<br>
XMR:  europe.cryptonight-hub.miningpoolhub.com:20580<br>
MUSIC:europe.ethash-hub.miningpoolhub.com:20585<br>
ETC:  europe.ethash-hub.miningpoolhub.com:20555<br>
EXP:  europe.ethash-hub.miningpoolhub.com:20565<br>
MONA: hub.miningpoolhub.com:20593<br>
ETN:  europe.cryptonight-hub.miningpoolhub.com:20596<br>
FTC:  hub.miningpoolhub.com:20510<br>
BTG:  us-east.equihash-hub.miningpoolhub.com:20595<br>
ZEN:  us-east.equihash-hub.miningpoolhub.com:20594<br>
ZCL:  us-east.equihash-hub.miningpoolhub.com:20575<br>
ZEC:  us-east.equihash-hub.miningpoolhub.com:20570<br>
<br>
Same here - always six characters before pool address.
 <h1>
 Usage:</h1>
  <code>./omql_miner</code>
 
 
 <h1>Known issues:  </h1>
 When building ccminer:
 nvcc fatal : Unsupported gpu architecture 'compute_20' <br>
 Open <code>ccminer/makefile.am</code> and delete <code>gencode arch=compute_20,code=sm_20</code>. There should be three lines with this code. Then compile ccminer maually using <code>./autogen.sh</code>, <code>./configure</code> and <code>./build.sh</code>
