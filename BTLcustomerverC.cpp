#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
    char phoneNumber[15];
    int isLoggedIn;
    char purchasedProducts[100][50]; // Luu tru ten cac san pham da mua
    int purchaseCount; // So luong san pham da mua
    double totalSpent; // So tien da tieu
} Account;

double totalSpentWithoutLogin = 0; // Bien toan cuc luu tong so tien da tieu khi khong dang nhap

// Cac ham xu ly
void displayMenu();
void login(Account *accounts, int *loggedInUser);
void createAccount(Account *accounts, int *loggedInUser);
void customerMenu(Account *accounts, int loggedInUser);
void changePassword(Account *accounts, int loggedInUser);
void buyProduct(Account *accounts, int loggedInUser);
void viewPurchasedProducts(Account *accounts, int loggedInUser);
void viewTotalSpent(Account *accounts, int loggedInUser);
void viewVoucher(Account *accounts, int loggedInUser);
void searchProductByName();
void searchProductByID();
void searchProductByPrice();
void displayProducts(); // Ham moi de hien thi danh sach san pham

// Hien thi menu lua chon
void displayMenu() {
    printf("\n============ MENU ============\n");
    printf("1) Tao tai khoan\n");
    printf("2) Dang nhap\n");
	printf("3) Xem danh sach san pham\n"); // Tùy ch?n m?i ð? xu?t s?n ph?m 
    printf("4) Mua san pham\n");
    printf("5) Xem so tien da tieu\n");
    printf("6) Tim kiem san pham theo ten\n");
    printf("7) Tim kiem san pham theo ma\n");
    printf("8) Tim kiem san pham duoi gia tien\n");

    printf("9) Thoat\n");
}

// Hien thi menu khach hang
void customerMenu(Account *accounts, int loggedInUser) {
    while (1) {
        printf("\n============ MENU KHACH HANG ============\n");
        printf("1) Doi mat khau\n");
        printf("2) Mua hang\n");
        printf("3) Nhung san pham da mua\n");
        printf("4) So tien da tieu\n");
        printf("5) Voucher dua tren %% tien da mua\n");
        printf("6) Dang xuat\n");

        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                changePassword(accounts, loggedInUser);
                break;
            case 2:
                buyProduct(accounts, loggedInUser);
                break;
            case 3:
                viewPurchasedProducts(accounts, loggedInUser);
                break;
            case 4:
                viewTotalSpent(accounts, loggedInUser);
                break;
            case 5:
                viewVoucher(accounts, loggedInUser);
                break;
            case 6:
                accounts[loggedInUser].isLoggedIn = 0;
                printf("Da dang xuat.\n");
                return;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
}

// Dang nhap vao he thong
void login(Account *accounts, int *loggedInUser) {
    char username[50];
    char password[50];
    char phoneNumber[15];

    printf("Nhap ten dang nhap: ");
    scanf("%s", username);
    printf("Nhap mat khau: ");
    scanf("%s", password);
    printf("Nhap so dien thoai: ");
    scanf("%s", phoneNumber);

    // Kiem tra tai khoan va mat khau
    for (int i = 0; i < 10; ++i) {
        if (strcmp(accounts[i].username, username) == 0 && strcmp(accounts[i].password, password) == 0 && strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            *loggedInUser = i; // Danh dau da dang nhap thanh cong
            accounts[i].isLoggedIn = 1;
            printf("Dang nhap thanh cong!\n");
            customerMenu(accounts, i); // Hien thi menu khach hang
            return;
        }
    }

    // Neu khong tim thay tai khoan
    printf("Ten dang nhap, mat khau hoac so dien thoai khong dung.\n");
}

// Tao moi tai khoan
void createAccount(Account *accounts, int *loggedInUser) {
    char username[50];
    char password[50];
    char phoneNumber[15];

    printf("Nhap ten dang nhap moi: ");
    scanf("%s", username);

    // Kiem tra xem ten dang nhap da ton tai chua
    for (int i = 0; i < 10; ++i) {
        if (strcmp(accounts[i].username, username) == 0) {
            printf("Ten dang nhap da ton tai. Vui long nhap ten moi.\n");
            return;
        }
    }

    printf("Nhap mat khau moi: ");
    scanf("%s", password);
    printf("Nhap so dien thoai moi: ");
    scanf("%s", phoneNumber);

    // Tim vi tri de luu tai khoan moi
    for (int i = 0; i < 10; ++i) {
        if (strlen(accounts[i].username) == 0) { // Tim vi tri trong
            strcpy(accounts[i].username, username);
            strcpy(accounts[i].password, password);
            strcpy(accounts[i].phoneNumber, phoneNumber);
            accounts[i].isLoggedIn = 0; // Ban dau chua dang nhap
            accounts[i].purchaseCount = 0;
            accounts[i].totalSpent = 0;
            printf("Tao tai khoan thanh cong!\n");
            return;
        }
    }

    // Neu khong co vi tri trong
    printf("So luong tai khoan da dat gioi han. Khong the tao them.\n");
}

// Doi mat khau
void changePassword(Account *accounts, int loggedInUser) {
    char newPassword[50];
    printf("Nhap mat khau moi: ");
    scanf("%s", newPassword);
    strcpy(accounts[loggedInUser].password, newPassword);
    printf("Doi mat khau thanh cong!\n");
}

// Mua hang
void buyProduct(Account *accounts, int loggedInUser) {
    char _productName[50], productID[10], productName[50], manufactureDate[11], expirationDate[11], category[50];
    double price;

    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file san pham.\n");
        return;
    }

    printf("Danh sach san pham:\n");
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        printf("Ma san pham: %s, Ten san pham: %s, Gia: %.2lf, Ngay san xuat: %s, Han su dung: %s, Danh muc: %s\n", productID, productName, price, manufactureDate, expirationDate, category);
    }
    fclose(file);

    printf("Nhap ten san pham muon mua: ");
    scanf("%s", _productName);

    file = fopen("products.txt", "r");
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        if (strcmp(_productName, productName) == 0) {
            if (loggedInUser != -1) {
                strcpy(accounts[loggedInUser].purchasedProducts[accounts[loggedInUser].purchaseCount], productName);
                accounts[loggedInUser].purchaseCount++;
                accounts[loggedInUser].totalSpent += price;
            } else {
                totalSpentWithoutLogin += price;
            }
            printf("Ban da mua san pham %s voi gia %.2lf\n", productName, price);
            fclose(file);
            return;
        }
    }

    printf("San pham khong ton tai.\n");
    fclose(file);
}

// Hien thi cac san pham da mua
void viewPurchasedProducts(Account *accounts, int loggedInUser) {
    printf("Cac san pham da mua:\n");
    for (int i = 0; i < accounts[loggedInUser].purchaseCount; i++) {
        printf("%s\n", accounts[loggedInUser].purchasedProducts[i]);
    }
}

// Hien thi so tien da tieu
void viewTotalSpent(Account *accounts, int loggedInUser) {
    if (loggedInUser != -1) {
        printf("So tien da tieu (da dang nhap): %.2lf\n", accounts[loggedInUser].totalSpent);
    } else {
        printf("So tien da tieu (khong dang nhap): %.2lf\n", totalSpentWithoutLogin);
    }
}

// Xem voucher dua tren so tien da tieu
void viewVoucher(Account *accounts, int loggedInUser) {
    double voucher = 0;
    if (accounts[loggedInUser].totalSpent >= 1000) {
        voucher = accounts[loggedInUser].totalSpent * 0.1;
    } else if (accounts[loggedInUser].totalSpent >= 500) {
        voucher = accounts[loggedInUser].totalSpent * 0.05;
    } else {
        voucher = accounts[loggedInUser].totalSpent * 0.02;
    }
    printf("Voucher cua ban la: %.2lf\n", voucher);
}

// Tim kiem san pham theo ten
void searchProductByName() {
    char searchName[50], productID[10], productName[50], manufactureDate[11], expirationDate[11], category[50];
    double price;

    printf("Nhap ten san pham can tim: ");
    scanf("%s", searchName);

    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file san pham.\n");
        return;
    }

    printf("Ket qua tim kiem theo ten san pham \"%s\":\n", searchName);
    int found = 0;
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        if (strstr(productName, searchName) != NULL) {
            printf("Ma san pham: %s, Ten san pham: %s, Gia: %.2lf, Ngay san xuat: %s, Han su dung: %s, Danh muc: %s\n", productID, productName, price, manufactureDate, expirationDate, category);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham nao.\n");
    }

    fclose(file);
}

// Tim kiem san pham theo ma
void searchProductByID() {
    char searchID[10], productID[10], productName[50], manufactureDate[11], expirationDate[11], category[50];
    double price;

    printf("Nhap ma san pham can tim: ");
    scanf("%s", searchID);

    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file san pham.\n");
        return;
    }

    printf("Ket qua tim kiem theo ma san pham \"%s\":\n", searchID);
    int found = 0;
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        if (strcmp(productID, searchID) == 0) {
            printf("Ma san pham: %s, Ten san pham: %s, Gia: %.2lf, Ngay san xuat: %s, Han su dung: %s, Danh muc: %s\n", productID, productName, price, manufactureDate, expirationDate, category);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham nao.\n");
    }

    fclose(file);
}

// Tim kiem san pham duoi gia tien
void searchProductByPrice() {
    double maxPrice, price;
    char productID[10], productName[50], manufactureDate[11], expirationDate[11], category[50];
    printf("Nhap gia tien toi da: ");
    scanf("%lf", &maxPrice);
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file san pham.\n");
        return;
    }
    printf("Ket qua tim kiem cac san pham duoi gia %.2lf:\n", maxPrice);
    int found = 0;
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        if (price <= maxPrice) {
            printf("Ma san pham: %s, Ten san pham: %s, Gia: %.2lf, Ngay san xuat: %s, Han su dung: %s, Danh muc: %s\n", productID, productName, price, manufactureDate, expirationDate, category);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham nao.\n");
    }
    fclose(file);
}
// Hien thi danh sach san pham
void displayProducts() {
    char productID[10], productName[50], manufactureDate[11], expirationDate[11], category[50];
    double price;
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file san pham.\n");
        return;
    }
    printf("Danh sach san pham:\n");
    while (fscanf(file, "%s %s %lf %s %s %s", productID, productName, &price, manufactureDate, expirationDate, category) != EOF) {
        printf("Ma san pham: %s, Ten san pham: %s, Gia: %.2lf, Ngay san xuat: %s, Han su dung: %s, Danh muc: %s\n", productID, productName, price, manufactureDate, expirationDate, category);
    }

    fclose(file);
}

int main() {
    Account accounts[10] = {0}; // Gia su chi luu toi da 10 tai khoan
    int loggedInUser = -1; // Khong co ai dang nhap ban dau
    while (1) {
        displayMenu();
        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount(accounts, &loggedInUser);
                break;
            case 2:
                login(accounts, &loggedInUser);
                break;
            case 3:
                // Xem danh sach san pham
                displayProducts();
                break;
            case 4:
                // Mua san pham khong can dang nhap
                buyProduct(accounts, loggedInUser);
                break;
            case 5:
                // Xem so tien da tieu
                viewTotalSpent(accounts, loggedInUser);
                break;
            case 6:
                searchProductByName();
                break;
            case 7:
                searchProductByID();
                break;
            case 8:
                searchProductByPrice();
                break;
            case 9:
                // Thoat chuong trinh
                printf("Da thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}

