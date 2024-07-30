// オープンアドレス法によるハッシュの利用例

#include <stdio.h>
#include "Bucket.h"
#include "ClosedHash.h"

/*--- メニュー ---*/
typedef enum {
  TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
  int ch;

  do {
    //printf("(1)Add (2)Remove (3)Search (4)Delete All (5)Dump (0)Terminate：");
    scanf("%d", &ch);
  } while (ch < TERMINATE || ch > DUMP);
  
  return (Menu)ch;
}

/*--- メイン ---*/
int main(void)
{
  Menu menu;				// メニュー
  ClosedHash hash;		// ハッシュ表

  Initialize(&hash, 13);	// ハッシュ表の初期化
  
  do {
    int result;
    Bucket x;
    Bucket *temp;

    switch (menu = SelectMenu()) {
    case ADD :		/*--- データの追加 ---*/
      x = ScanBucket();
      result = Add(&hash, &x.v);
      
      if (result) {
	printf("Failed\n");
      }
      
      break;

    case DELETE :	/*--- データの削除 ---*/
      x = ScanBucket();
      result = Remove(&hash, &x.v);
      
      if (result == 1) {
	printf("Not Found\n");
      }
      
      break;

    case SEARCH :	/*--- データの探索 ---*/
      x = ScanBucket();
      temp = Search(&hash, &x.v);
	    
      if (temp == NULL) {
	printf("\aNot found\n");
      } else {
	printf("Found\n");
	PrintLnBucket(temp);
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
  
  Terminate(&hash);		// ハッシュ表の後始末

  return 0;
}
