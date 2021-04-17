//product.c
#include "product.h"

int addProduct(Product *p){
	printf("추가할 제품명: ");
	scanf(" %[^\n]s", p -> name);
	
	printf("추가할 제품 중량(g): ");
	scanf(" %d", &p -> weight);

	printf("추가할 제품 가격: ");
	scanf(" %d", &p -> price);

	printf("추가할 제품 별점(1~5): ");
	scanf(" %f", &p -> star);

	if (p -> star - (int) p -> star >= 0.5)
		p -> starCount = (int) p -> star + 1;
	else
		p -> starCount = (int) p -> star;

	return 1;
}

void readProduct(Product p){
	printf("%s  ||  %d g  ||  $ %d  ||  %.1f (", p.name, p.weight, p.price, p.star);
	for (int i = 0; i < p.starCount; i ++){
		printf("*");
	}
	printf(")\n");
	printf("\n");
}

int updateProduct(Product *p){
	
	printf("수정할 제품명: ");
	scanf(" %[^\n]s", p -> name);
	
	printf("수정할 제품 중량(g): ");
	scanf(" %d", &p -> weight);

	printf("수정할 제품 가격: ");
	scanf(" %d", &p -> price);

	printf("수정할 제품 별점(1~5): ");
	scanf(" %f", &p -> star);

	if (p -> star - (int) p -> star >= 0.5)
		p -> starCount = (int) p -> star + 1;
	else
		p -> starCount = (int) p -> star;
	printf("=> 수정성공!\n");

	return 1;
}

int deleteProduct(Product *p){
	p -> price = -1;
	return 1;
}
