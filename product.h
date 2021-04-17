//product.h
#include <stdio.h>

typedef struct{
    char name[50]; //제품명
    int weight; //제품 중량
    int price; //제품 가격
    float star; //제품 별점
    int starCount; //제품 별점 개수
} Product;

int addProduct(Product *p); //2. 제품 추가하기_C
void readProduct(Product p); //제품 한줄 출력하기
int updateProduct(Product *p); //3. 제품 수정하기_U
int deleteProduct(Product *p); //4. 제품 삭제하기_D

