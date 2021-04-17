//main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(){
	Product plist[20];
	int count = 0, menu;
	int index = 0;
	int num = 0;
	
	count = loadData(plist);
	index = count;

	while (1){
		menu = selectMenu();
		if (menu == 0)	break;
		if (menu == 1){
			if (count != 0)	listProduct(plist, index);
			else		printf("조회할 데이터가 존재하지 않습니다.\n");
		}
		else if (menu == 2){
			if (addProduct(&plist[index ++])){
				count = count + 1;
				printf("=> 추가됨!\n");
			}
		}
		else if (menu == 3){
			if (count != 0){
				num = selectDataNum(plist, index);
				if (num != 0)	updateProduct(&plist[num - 1]);
				else		printf("=> 취소됨!\n");
			}
			else	printf("수정할 데이터가 존재하지 않습니다.\n");
		}
		else if (menu == 4){
			if (count != 0){
				num = selectDataNum(plist, index);
				if (num != 0){
					int check = 0;
					printf("정말로 삭제하시겠습니까(삭제:1)? ");
					scanf(" %d", &check);
					if (check == 1)
						if (deleteProduct(&plist[num - 1])){
							printf("=> 삭제됨!\n");
							count = count -1;
						}
				}
				else {
					printf("=> 취소됨!\n");
					continue;
				}	
			}
			else	printf("삭제할 데이터가 존재하지 않습니다.\n");
		}
		else if (menu == 5)	saveData(plist, index);
		else if (menu == 6)	searchName(plist, index);
		else if (menu == 7)	searchWeight(plist, index);
		else if (menu == 8)	searchPrice(plist, index);
	}
	printf("종료됨!\n");
	return 0;
}
