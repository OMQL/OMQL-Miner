wget https://github.com/nanopool/Claymore-Dual-Miner/releases/download/v7.3/Claymore.s.Dual.Ethereum.Decred_Siacoin_Lbry.AMD.NVIDIA.GPU.Miner.v7.3.-.LINUX.tar.gz
chmod 777 Claymore.s.Dual.Ethereum.Decred_Siacoin_Lbry.AMD.NVIDIA.GPU.Miner.v7.3.-.LINUX.tar.gz
tar -xvzf Claymore.s.Dual.Ethereum.Decred_Siacoin_Lbry.AMD.NVIDIA.GPU.Miner.v7.3.-.LINUX.tar.gz
rm Claymore.s.Dual.Ethereum.Decred_Siacoin_Lbry.AMD.NVIDIA.GPU.Miner.v7.3.-.LINUX.tar.gz
wget https://www.bminercontent.com/releases/bminer-v5.4.0-ae18e12-amd64.tar.xz
chmod 777 bminer-v5.4.0-ae18e12-amd64.tar.xz
tar -xJf bminer-v5.4.0-ae18e12-amd64.tar.xz
chmod 777 -R  bminer-v5.4.0-ae18e12
rm bminer-v5.4.0-ae18e12-amd64.tar.xz
rm config.txt
rm Data.bin
rm dpools.txt
rm epools.txt
rm History.txt
rm Readme!!!.txt
rm start_etc+sia.bash
rm start_eth+sia.bash
rm start_only_etc.bash
rm start_only_eth.bash
mv ./bminer-v5.4.0-ae18e12/bminer ./
rm -R bminer-v5.4.0-ae18e12
apt-get install libcurl4-openssl-dev libssl-dev libjansson-dev automake autotools-dev build-essential -y
apt-get install gcc-5 g++-5 -y
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 1
git clone https://github.com/tpruvot/ccminer.git
cd ccminer
./autogen.sh
./configure
./build.sh
chmod 777 -R ccminer

