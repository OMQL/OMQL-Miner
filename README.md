# OMQL-Miner
<h1>Multi pool miner for Linux x64 & NVIDIA</h1>
<h1>Features:</h1>

- Algorithm switching based on highest profitability on whattomine.com;

- Supported altcoins: ETH, ETC, FTC, BTG, ZEN, ZCL, ZEC, ETN, MONA, EXP, MUSIC;

- Compiling miners from sources for the best performance (if possible);

- 100% open source;

- 2,5% dev fee;

- Tested on Ubuntu 16.04 LTS;

<h1>Installing:</h1>
 <code>git clone https://github.com/OMQL/OMQL-Miner.git</code>
 
 <code>  cd OMQL-Miner</code><br>
 <code> g++ main.cpp -o omql_miner -lcurl</code>
 <h1>
 Usage:</h1>
  <code>./omql_miner Username</code>
 
 
 <h1>Known issues:  </h1>
 When building ccminer:
 nvcc fatal : Unsupported gpu architecture 'compute_20' <br>
 Open <code>ccminer/makefile.am</code> and delete <code>gencode arch=compute_20,code=sm_20</code>. There should be three lines with this code. Then compile ccminer maually using <code>./autogen.sh</code>, <code>./configure</code> and <code>./build.sh</code>
 Same with ccminer-lyra2v2, but there is one line to change.

<h1>Notes:</h1>
Building CryptoNight miner might take long time. Seems to stuck on ~70% but its normal.
