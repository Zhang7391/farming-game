### 歡迎來到binary種田人生(Linux版)

在這裡可以體驗到下面的功能(慢慢更新中):

1. 看著螢幕等待秧苗成熟。
2. 適時的給予水源
3. 商店系統
	1. 購買種子
	2. 賣出農作物
	3. 購買道具
4. 遊戲存檔系統
5. 全英文遊戲環境


這個遊戲在發布的時候皆未編譯，請自行`cd`進code-file裡面執行以下程式:
```c++
g++ -g -Wall gaming.cpp -o gaming.exe
./gaming.exe
```

如果程式報錯請確認以下程式包有安裝
* 缺少`#include<conio.h>`
	* [安裝conio.h](https://github.com/zoelabbb/conio.h)

```
更新日誌:
	Alpha0.0 2021.01.10 新增遊戲github介面
	Alpha1.0 2021.01.12 新增遊戲主頁
	Alpha1.1 2021.01.13 新增遊戲商店、玩家背包
```

※由於本人的作業環境是Linux(CentOS 7)，有使用到部分Linux系統指令，所以Windows和Mac無法執行，clone前請注意是否是使用Linux系統。



### Welcome to binary farming life (Linux version)

Here, you can experience the following functions (updating slowly):

1. Look at the screen and wait for the seedlings to mature.
2. Timely supply of water.
3. Store:
	1. Buy seeds
	2. Selling crops
	3. Buy props
4. Game archive.
5. All English game environment.


This game was not compiled when it was released.
Please `cd` it into the code-file and execute the following program:
```c++
g++ -g -Wall gaming.cpp -o gaming.exe
/gaming.exe
```

If the program reports an error, please confirm that the following packages are installed
* Missing`#include<conio.h>`
	* [install conio.h](https://github.com/zoelabbb/conio.h)

```
Update log:
	Alpha0.0 2021.01.10 new game GitHub interface
	Alpha1.0 2021.01.12 new game home page
	Alpha1.1 2021.01.13 new game store and player Backpack
```

ATTENTION:
	Because my working environment is Linux(CentOS 7), I use some Linux system instructions, so windows and Mac can't execute this game.
	Please pay attention to whether I use "Linux system" before clone.
