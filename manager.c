//manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int selectMenu(){
	int menu;
	printf("\n*** 제품 관리하기 ***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 이름검색\n");
	printf("7. 중량검색\n");
	printf("8. 가격검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는: ");
	scanf(" %d", &menu);

	return menu;

}

int loadData(Product *p){
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt");

	if (fp == NULL){
		printf("\n");
		printf("=> 파일 없음\n");
	}
	else {
		for (i = 0; i < 20; i ++ ){
			fscanf(fp, "%s", p[i].name);
			if (feof(fp)) break;
			fscanf(fp, "%d", &p[i].weight);
			fscanf(fp, "%d", &p[i].price);
			fscanf(fp, "%f", &p[i].star);
			
			if(p[i].star - (int)p[i].star >= 0.5)
				p[i].starCount = (int)p[i].star + 1;
			else
				p[i].starCount = (int)p[i].star;
		}
		fclose(fp);
		printf("\n");
		printf("=> 파일 데이터 불러오기 성공!");
		printf("\n");
	}
	return i;
}

void listProduct(Product *p, int count){
	printf("\n");
        printf("=================================================================\n");
	for (int i = 0; i < count; i ++){
		if (p[i].price == -1)	continue;
		printf("%2d\t", i + 1);
		readProduct(p[i]);
	}
	printf("\n");
}

int selectDataNum(Product *p, int count){
	int num = 0;

	listProduct(p, count);
	printf("번호(취소|0): ");
	scanf(" %d", &num);

	return num;
}

void saveData(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for (int i = 0; i < count; i ++){
		if (p[i].price == -1)	continue;
		else
			fprintf(fp, "%s %d %d %f\n", p[i].name, p[i].weight, p[i].price, p[i].star);
	}
	fclose(fp);
	printf("=> 저장됨!(파일명: product.txt)\n");
}

void searchName(Product *p, int count){
	char search[30];
	int scnt = 0;

	printf("검색할 이름: ");
	scanf(" %s", search);

	for (int i = 0; i < count; i ++){
		if (p[i].price == -1)	continue;
		else if (strstr(p[i].name, search)){
       			printf("=================================================================\n");
			printf("%2d\t", i + 1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if (scnt == 0)
		printf("=> 검색된 데이터 없음!\n");
}

void searchWeight(Product *p, int count){
	int search = 0;
	int scnt = 0;
	
	printf("검색할 중량: ");
	scanf(" %d", &search);

	for (int i = 0; i < count; i ++){
		if (p[i].price == -1)	continue;
		else if (p[i].weight == search){
       			printf("=================================================================\n");
			printf("%2d\t", i + 1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if (scnt == 0)
		printf("=> 검색된 데이터 없음!\n");
}

void searchPrice(Product *p, int count){
	int search = 0;
	int scnt = 0;

	printf("검색할 가격: ");
	scanf(" %d", &search);

	for (int i = 0; i < count; i ++){
		if (p[i].price == -1)	continue;
		else if (p[i].price == search){
       			printf("============================================================\n");
			printf("%2d\t", i + 1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if (scnt == 0)
		printf("=> 검색한 가격의 데이터 없음!\n");
}
