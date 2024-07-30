// Node（ヘッダ部）

#ifndef ___Node
#define ___Node

/*--- バケットを表すノード ---*/
typedef struct __node {
	int         v;	// データ
	struct __node *next;	// 後続ポインタ（後続ノードへのポインタ）
} Node;

void PrintNode(const Node* x);

void PrintLnNode(const Node* x);

Node ScanNode();

#endif
