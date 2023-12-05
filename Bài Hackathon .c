#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct CD{
    int id;
    char name[50];
    float duration;
    char content[100];
    bool status;
};
void printCDList(struct CD cdList[], int size){
    printf("Danh sach CD:\n");
    for (int i = 0; i < size; ++i) {
        printf("ID: %d, Ten: %s, Thoi gian: %.2f, Noi dung: %s, Trang thai: %s\n",
               cdList[i].id, cdList[i].name, cdList[i].duration,
               cdList[i].content, cdList[i].status  ? "Da cho thue" : "Chua cho thue");
    }
    printf("\n");
}
void addNewCD(struct CD cdList[], int *size){
    struct CD newCD;
    printf("Nhap ten CD: ");
    getchar();
    fgets(newCD.name, sizeof(newCD.name), stdin);
    strtok(newCD.name, "\n");
    printf("Nhap thoi luong CD: ");
    scanf("%f", &newCD.duration);
    printf("Nhap noi dung CD: ");
    getchar();
    fgets(newCD.content, sizeof(newCD.content), stdin);
    strtok(newCD.content, "\n");
    newCD.status = false;
    newCD.id = *size + 1;
    cdList[(*size)++] = newCD;
    printf("Them CD thanh cong.\n");
}
void updateCD(struct CD cdList[], int size){
    char searchName[50];
    printf("Nhap ten CD can chinh sua: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    strtok(searchName, "\n");
    int index = -1;
    for (int i = 0; i < size; ++i){
        if (strcmp(cdList[i].name, searchName) == 0){
            index = i;
            break;
        }
    }
    if (index != -1){
        printf("Nhap thong tin moi cho CD:\n");
        printf("Nhap ten CD: ");
        getchar();
        fgets(cdList[index].name, sizeof(cdList[index].name), stdin);
        strtok(cdList[index].name, "\n");
        printf("Nhap thoi gian CD: ");
        scanf("%f", &cdList[index].duration);
        printf("Nhap noi dung CD: ");
        getchar();
        fgets(cdList[index].content, sizeof(cdList[index].content), stdin);
        strtok(cdList[index].content, "\n");
        printf("Cap nhat CD thanh cong.\n");
    } else {
        printf("Khong tim thay CD.\n");
    }
}
void deleteCD(struct CD cdList[], int *size){
    char deleteName[50];
    printf("Nhap ten CD can xoa: ");
    getchar();
    fgets(deleteName, sizeof(deleteName), stdin);
    strtok(deleteName, "\n");
    int index = -1;
    for (int i = 0; i < *size; ++i){
        if (strcmp(cdList[i].name, deleteName) == 0){
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *size - 1; ++i){
            cdList[i] = cdList[i + 1];
        }
        (*size)--;
        printf("Xoa CD thanh cong.\n");
    } else {
        printf("Khong tim thay CD.\n");
    }
}
void sortByDuration(struct CD cdList[], int size){
    for (int i = 1; i < size; ++i) {
        struct CD key = cdList[i];
        int j = i - 1;
        while (j >= 0 && cdList[j].duration > key.duration){
            cdList[j + 1] = cdList[j];
            j = j - 1;
        }
        cdList[j + 1] = key;
    }
    printf("Danh sach CD sau khi sap xep:\n");
    printCDList(cdList, size);
}
int main(){
    const int MAX_CDS = 100;
    struct CD cdList[MAX_CDS];
    int currentSize = 2;
    cdList[0] = (struct CD){1, "Kinh di ma quy", 7.0, "Phim giat minh", false};
    cdList[1] = (struct CD){2, "Phim lang man tinh cam", 39.0, "Phim hon hit", true};
    do{
        printf("*******************MENU*******************\n");
		printf("1. In toan bo danh sach cd co o trong mang cdList tren cung mot hang.\n");
		printf("2. Them moi cd vao vi tri cuoi cung cua cdList.\n");
		printf("3. Cap nhat thong tin cua mot cd.\n");
		printf("4. Xoa mot cd.\n");
		printf("5. Sap xep va in ra danh sach cdList theo thu tu tang dan.\n");
		printf("6. Tim kiem va in ra thong tin cua cd\n");
		printf("7. Tim kiem va in ra toan bo thong tin cua cac cd theo status.\n");
		printf("Lua chon cua ban la: ");
        int choice;
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printCDList(cdList, currentSize);
                break;
            case 2:
                addNewCD(cdList, &currentSize);
                break;
            case 3:
                updateCD(cdList, currentSize);
                break;
            case 4:
                deleteCD(cdList, &currentSize);
                break;
            case 5:
                sortByDuration(cdList, currentSize);
                break;
            case 6:
                break;
            case 7:
    			break;
            default:
                printf("Vui long chon tu 1-7.\n");
        }
    }while (1 == 1);
    return 0;
}
