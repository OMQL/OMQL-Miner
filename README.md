# OMQL-Miner
<h1>Installing:</h1>
 <code>git clone https://github.com/OMQL/OMQL-Miner.git</code>
 
 <code>  cd OMQL-Miner</code><br>
 <code> g++ main.cpp -o omql_miner -lcurl</code>
 <h1>
 Usage:</h1>
  <code>./omql_miner Username</code>
 
 
 <h1>Known issues:  </h1>
 nvcc fatal : Unsupported gpu architecture 'compute_20' <br>
 Open <code>ccminer/makefile.am</code> and delete <code>gencode arch=compute_20,code=sm_20</code>. There should be three lines with this code. Then compile ccminer maually using <code>./autogen.sh</code>, <code>./configure</code> and <code>./build.sh</code>

<h1>Notes:</h1>
Building CryptoNight miner might take long time.
