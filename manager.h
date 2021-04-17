//manager.h

int selectMenu();
int loadData(Product *p); //데이터 불러오기
void listProduct(Product *p, int count); //1. 제품 list 조회하기_R
int selectDataNum(Product *p, int count); //번호 고르기
void saveData(Product *p, int count); //5. 제품 파일에 저장하기
void searchName(Product *p, int count); //6. 제품 검색하기_이름
void searchWeight(Product *p, int count); //7. 제품 검색하기_중량
void searchPrice(Product *p, int count); //8. 제품 검색하기_가격
