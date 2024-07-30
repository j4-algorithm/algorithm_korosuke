// チェイン法によるハッシュ（ソース部：キーは氏名）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".h"
#include ".h"

/*--- ハッシュ関数（keyのハッシュ値を返す）---*/
static int hash(const int key, int size)
{
	return key % ;
}

/*--- ノードの各メンバに値を設定 ----*/
static void SetNode(Node *n, const int *x, Node *next)
{
	n-> = ;		// データ
	n-> = next;		// 後続ポインタ
}

/*--- ハッシュ表の初期化 ---*/
int Initialize(ChainHash *h, int size)
{
	if () {
		
		return 0;
	}

	h->size = ;
	
	for (int i = 0; i < size; i++){ 	// すべてのバケットを空にする
		
	}

	return 1;
}

/*--- 探索 ---*/
(const ChainHash *h, const int *x)
{
	int key = hash(, h->size);	// 探索するデータのハッシュ値
	Node *p = h->table[key];			// 着目ノード

	while (p != NULL) {
		if (p->v  *x) {	// 探索成功
			
		}
		
		p = p->next;					// 後続ノードに着目
	}
	
	return NULL;						// 探索失敗
}

/*--- データの追加 ---*/
 (ChainHash *h, const int *x)
{
	int key = hash(*x, h->size);	// 追加するデータのハッシュ値
	Node *p = h->table[key];			// 着目ノード
	Node *temp;

	while (p != NULL) {
		if (p->v  *x){		// このキーは登録ずみ
			return ;					// 追加失敗
		}
		
		p = p->next;					// 後続ノードに着目
	}
	
	if () {
		return ;
	}
	
	(temp, , h->table[key]);	// 追加するノードに値を設定
	h->table[key] = temp;

	return 0;							// 追加成功
}

/*--- データの削除 ---*/
int Remove(ChainHash *h, const int *x)
{
	int   = hash(, h->size);	// 削除するデータのハッシュ値
	 = h->table[key];			// 着目ノード
	 = &h->table[key];			// 着目ノードへのポインタ

	while (p != NULL) {
		if (p->v)	{	// 見つけたら
			
			free(p);					// 解放

			return 0;					// 削除成功
		}

		pp = &p->next;
		p = p->next;					// 後続ノードに着目
	}

	return 1;							// 削除失敗（存在しない）
}

/*--- ハッシュ表をダンプ ---*/
void Dump(const ChainHash *h)
{
	for () {
		
		printf("%05d  ", i);
		
		while (p != NULL) {
			printf(": %d ", );
			
			
		}
		
		putchar('\n');
	}
}

/*--- 全データの削除 ---*/
void Clear(ChainHash *h)
{
	 () {
		Node *p = h->table[i];			// 着目ノード

		 () {
		
			Node *next = p->next;
			free(p);					// 着目ノード用の記憶域を解放
			p = next;					// 後続ノードに着目
		}

		;
	}
}

/*--- ハッシュ表を後始末 ---*/
void Terminate(ChainHash *h)
{
	Clear(h);				// 全データを削除
	free(h->table);			// ハッシュ表用配列の記憶域を解放
	h->size = 0;			// ハッシュ表の容量をクリア
}

