// ８王妃問題を解く

#include <stdio.h>

#define X 8
#define D 15
#define B 7

int flag_a[X];		// 各行に王妃が配置ずみか
int flag_b[D];		// ／対角線に王妃が配置ずみか
int flag_c[D];		// ＼対角線に王妃が配置ずみか
int pos[X];			// 各列の王妃の位置

/*--- 盤面（各列の王妃の位置）を出力 ---*/
void print(void) {
    static int Y = 0;
    Y++;
	for (int i = 0; i < X; i++) {
        for(int j = 0; j < X; j++){
            if(j == pos[i]){
                printf("1 ");
            }else{
                printf("0 ");
            }
        }
        putchar('\n');
	}
	printf("%d\n", Y);
}

/*--- i列目の適当な位置に王妃を配置 ---*/
void set(int i) {
	for (int j = 0; j < X; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + B]) {
			pos[i] = j;

			if (i == B) {			// 全列に配置終了
				print();
			} else {
				flag_a[j] = 1;
				flag_b[i + j] = 1;
				flag_c[i - j + 7] = 1;

				set(i+1);		// 次の列に配置

				flag_a[j] = 0;
				flag_b[i + j] = 0;
				flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < X; i++) {
		flag_a[i] = 0;
	}
	
	for (int i = 0; i < D; i++) {
		flag_b[i] = 0;
        flag_c[i] = 0;
	}

	set(0);						// 0列目に配置

	return 0;
}