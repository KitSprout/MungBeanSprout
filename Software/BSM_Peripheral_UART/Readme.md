MungBeanSprout UART Example
========
* Author  : [Hom](http://about.me/Hom)
* Update  : 2015/02/22

Description
========
MungBeanSprout UART 的範例程式，接收鍵盤輸入的資料，並回傳電腦顯示在 Putty 上。

Hardware
========
* UART  
PA9  - UART Tx  
PA10 - UART Rx  
> UARTx = USART1  
> BaudRate = 115200  
> ByteSize = 8  
> StopBits = 1  
> Parity = 'N'  
> HardwareFlowControl = None  
