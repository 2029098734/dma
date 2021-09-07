.pHONY : all
all :
	cd /C/Users/Administrator/Desktop/DMA/hard && make
	cd /C/Users/Administrator/Desktop/DMA/mtom && make
	cd /C/Users/Administrator/Desktop/DMA/soft && make
	
.pHONY : cleanall
cleanall :
	cd /C/Users/Administrator/Desktop/DMA/hard && make clean
	cd /C/Users/Administrator/Desktop/DMA/mtom && make clean
	cd /C/Users/Administrator/Desktop/DMA/soft && make clean