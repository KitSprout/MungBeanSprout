MungBeanSprout TFT2.2 Example
========
* Author  : [Hom](http://about.me/Hom)
* Update  : 2015/02/20

Description
========
MungBeanSprout TFT2.2 的範例程式，透過 SPI 讀寫 [TFT_2.2-inch](https://github.com/KitSprout/TFT_2.2-inch) 模組，並在螢幕上顯示彩條。

Hardware
========
* TFT2.2  
PB1  - LCD_LIG  
PA2  - LCD_DC  
PA3  - LCD_RST  
PA4  - LCD_CST  
PA5  - LCD_CLK  
PA6  - LCD_SDO  
PA7  - LCD_SDI  
> SPIx = SPI1  
> Dir = 2Lines_FullDuplex  
> Mode = Master  
> CPOL = High  
> CPHA = 2Edge  
> FirstBit = MSB  
> DataSize = 8 bits  
> Prescaler = Prescaler_2 
