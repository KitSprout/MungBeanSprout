[MungBeanSprout](https://github.com/KitSprout/MungBeanSprout)
========
* Author  : [Hom](https://github.com/Hom-Wang)
* Version : v1.0
* Update  : 2014/11/24

Description
========
MungBeanSprout 是一個 STM32F030F 的開發模組，體積小、成本低、並拉出所有的 GPIO、可以直接插在麵包板上，使用 3V3 供電。

License
========
* 硬體(Hardware)採用 [CC BY-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW) 方式授權 
  
　　<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW"><img alt="創用 CC 授權條款" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/tw/80x15.png" /></a>  
　　<span xmlns:dct="http://purl.org/dc/terms/" property="dct:title"> MungBeanSprout v1.0 </span>由<a xmlns:cc="http://creativecommons.org/ns#" href="http://about.me/Hom" property="cc:attributionName" rel="cc:attributionURL"> Hom </a>製作，以<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/deed.zh_TW"> 創用CC 姓名標示-相同方式分享 4.0 國際 授權條款 </a>釋出。  

* 軟體(Software)採用 [MIT License](http://opensource.org/licenses/MIT) 方式授權  

Hardware
========
* 控制器　 : [STM32F030F](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1574/LN1826/PF258968) 20Pin 48MHz
* PCB 尺寸 : 15.24 * 18.00mm
* 設計軟體 [Altium Designer 14](http://www.altium.com/en/products/altium-designer) ( PcbLib use AD [PcbLib v1.1](https://github.com/KitSprout/AltiumDesigner_PcbLibrary/releases/tag/v1.1) )

Software
========
* 開發環境 Keil uVision v5.12
* BSM_TestADC ... ADC 讀取範例
* BSM_TestGPIO ... GPIO 輸入輸出範例
* BSM_TestMPU6050 ... MPU6050 模擬I2C 讀寫範例
* BSM_TestPWM ... PWM 輸出範例
* BSM_TestSF138 ... 74HC138 範例
* BSM_TestSF164 ... 74HC164 範例
* BSM_TestSF595 ... 74HC595 範例
* BSM_TestSystick ... Systick 中斷範例
* BSM_TestTFT2.2 ... SPI TFT 讀寫範例
* BSM_TestUART ... UART 傳輸範例，PC 端使用 Putty

Related Documents
========
* [Google Drive](http://goo.gl/i5fahz)

View
========
<img src="https://lh5.googleusercontent.com/-ScuEJge8KRw/VG4jHJs-ZpI/AAAAAAAALO4/s65es7P8gnY/s1600/DSC_2650.jpg" />

Config
========
<img src="https://lh4.googleusercontent.com/-wGYIDgoioXk/VHLSwlL3PaI/AAAAAAAALYc/_CMvftVr67A/s1600/Config_2.png" />
<img src="https://lh4.googleusercontent.com/-3KsPbPbc0GA/VHLSwltHYBI/AAAAAAAALYY/uF6fmXXzD_c/s1600/Config_1.png" />

Schematic
========
<img src="https://lh3.googleusercontent.com/-ct5bmDdww5s/VGc2Jpql_bI/AAAAAAAALLE/xLAkGv6_mY0/s1600/Sch_MungBeanSprout.png"/>
