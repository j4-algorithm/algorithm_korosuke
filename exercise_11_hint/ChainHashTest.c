// 演習3-10　チェインハッシュChainHashの利用例（キーは氏名）

#include <stdio.h>
#include "Node.h"
#include "ChainHash.h"

/*--- メニュー ---*/
typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		//printf("(1)Add (2)Remove (3)Search (4)Delete all (5)Dump (0)Terminate: ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > DUMP);
	
	return (Menu)ch;
}

/*--- メイン ---*/
int main(void)
{
	Menu menu;				// メニュー
	ChainHash hash;			// ハッシュ表

	Initialize(&hash, 13);	// ハッシュ表の初期化

	do {
		int result;
		Node x;
		Node *temp;

		switch (menu = SelectMenu()) {
			
		case ADD :		/*--- データの追加 ---*/
			x = ScanNode();
			result = Add(&hash, &x.v);
			
			if (result) {
				printf("Failed\n");
			}
      
			break;

		case DELETE :	/*--- データの削除 ---*/
			x = ScanNode();
			result = Remove(&hash, &x.v);
      
			if (result == 1) {
				printf("Not Found\n");
			}
			
			break;

		case SEARCH :	/*--- データの探索 ---*/
			x = ScanNode();
			temp = Search(&hash, &x.v);
	    
			if (temp == NULL) {
				printf("\aNot found\n");
			} else {
				printf("Found\n");
				PrintLnNode(temp);
			}

			break;

		case CLEAR :  /*--- 全データの削除 ---*/
			Clear(&hash);
			
			break;

		case DUMP :  /*--- ハッシュ表のダンプ ---*/
			Dump(&hash);
			
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&hash);							// ハッシュ表の後始末

	return 0;
}
