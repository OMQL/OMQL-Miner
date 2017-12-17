
git clone https://github.com/ethereum-mining/ethminer.git
chmod -R 777 ethminer
sudo apt-get install cmake
cd ethminer/cmake
cmake ..
cmake --build .
make install
